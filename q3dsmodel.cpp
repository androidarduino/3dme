#include "q3dsmodel.h"


Q3dsModel::Q3dsModel(QString modelFile, QString pName, QWidget* parent):QGLWidget(parent)
{
    name=pName;
    setMouseTracking(true);
    view_rotx=view_roty=view_rotz=anim_rotz=0.0;
    zoom=1.0;
    currentCamera="";
    anti_alias=true;
    iflush=false;
    file=0;
    show_object=true;
    show_bounds=true;
    show_cameras=false;
    show_lights=false;
    xRotate=yRotate=zRotate=0;
    xBend=yBend=zBend=0;
    xOffset=yOffset=zOffset=0;
    xScale=yScale=zScale=1;
    TEX_XSIZE=TEX_YSIZE=1024;
    defaultColor=defaultColor.fromRgb(100,100,70,255);
    if(modelFile!="")
        loadModel(modelFile);
    highlighted=false;
    reGenerate=false;
    father=NULL;
}
void Q3dsModel::retrieveTexture(QImage& picture, QString fileName)
{
    qDebug()<<"getting picture texture: "<<fileName;
    picture.load(fileName);
}
void Q3dsModel::replaceColor(QString colorName, QColor color)
{
    colorMap[colorName]=color;
}
void Q3dsModel::loadModel(QString fileName)
{
    //decompose file name and data path
    modelFile=fileName;
    int slash=fileName.lastIndexOf('/');
    datapath=fileName.left(slash);
    fileName=fileName.mid(slash+1);
    if(name=="")
        name=fileName;
    objName=fileName;
    if(slash==-1)
        datapath=".";
    //load the model file
    qDebug()<<fileName;
    file=lib3ds_file_load(fileName.toAscii().constData());
    if (!file) {
        qDebug()<<("3dsplayer: Error: Loading 3DS file failed.");
        exit(1);
    }
    /* No nodes?  Fabricate nodes to display all the meshes. */
    if(!file->nodes)
    {
        Lib3dsMesh *mesh;
        Lib3dsNode *node;
        for(mesh=file->meshes;mesh!=NULL;mesh=mesh->next)//for each mesh, create a node
        {
            node = lib3ds_node_new_object();
            strcpy(node->name, mesh->name);
            node->parent_id = LIB3DS_NO_PARENT;
            lib3ds_file_insert_node(file, node);
        }
    }
    lib3ds_file_eval(file, 1.0f);//re-evaluate the file
    lib3ds_file_bounding_box_of_nodes(file, LIB3DS_TRUE, LIB3DS_FALSE, LIB3DS_FALSE, bmin, bmax);
    sx = bmax[0] - bmin[0];
    sy = bmax[1] - bmin[1];
    sz = bmax[2] - bmin[2];
    isize = ((sx)>(sy)?(sx):(sy)); isize = ((isize)>(sz)?(isize):(sz));
    modelSize=isize;
    cx = (bmin[0] + bmax[0])/2;
    cy = (bmin[1] + bmax[1])/2;
    cz = (bmin[2] + bmax[2])/2;
    //qDebug()<<cx<<cy<<cz;
    /* No cameras in the file?  Add four */
    if( !file->cameras ) {
        /* Add some cameras that encompass the bounding box */
        Lib3dsCamera *camera = lib3ds_camera_new("Camera_X");
        camera->target[0] = cx;
        camera->target[1] = cy;
        camera->target[2] = cz;
        memcpy(camera->position, camera->target, sizeof(camera->position));
        camera->position[0] = bmax[0] + 1.5 * ((sy)>(sz)?(sy):(sz));
        camera->near_range = ( camera->position[0] - bmax[0] ) * .5;
        camera->far_range = ( camera->position[0] - bmin[0] ) * 2;
        lib3ds_file_insert_camera(file, camera);
        /* Since lib3ds considers +Y to be into the screen, we'll put
         * this camera on the -Y axis, looking in the +Y direction.
         */
        camera = lib3ds_camera_new("Camera_Y");
        camera->target[0] = cx;
        camera->target[1] = cy;
        camera->target[2] = cz;
        memcpy(camera->position, camera->target, sizeof(camera->position));
        camera->position[1] = bmin[1] - 1.5 * ((sx)>(sz)?(sx):(sz));
        camera->near_range = ( bmin[1] - camera->position[1] ) * .5;
        camera->far_range = ( bmax[1] - camera->position[1] ) * 2;
        lib3ds_file_insert_camera(file, camera);
        camera = lib3ds_camera_new("Camera_Z");
        camera->target[0] = cx;
        camera->target[1] = cy;
        camera->target[2] = cz;
        memcpy(camera->position, camera->target, sizeof(camera->position));
        camera->position[2] = bmax[2] + 1.5 * ((sx)>(sy)?(sx):(sy));
        camera->near_range = ( camera->position[2] - bmax[2] ) * .5;
        camera->far_range = ( camera->position[2] - bmin[2] ) * 2;
        lib3ds_file_insert_camera(file, camera);
        camera = lib3ds_camera_new("Camera_ISO");
        camera->target[0] = cx;
        camera->target[1] = cy;
        camera->target[2] = cz;
        memcpy(camera->position, camera->target, sizeof(camera->position));
        camera->position[0] = bmax[0] + .75 * isize;
        camera->position[1] = bmin[1] - .75 * isize;
        camera->position[2] = bmax[2] + .75 * isize;
        camera->near_range = ( camera->position[0] - bmax[0] ) * .5;
        camera->far_range = ( camera->position[0] - bmin[0] ) * 3;
        lib3ds_file_insert_camera(file, camera);
    }

    /* No lights in the file?  Add some. */
    if (file->lights == NULL)
    {
        Lib3dsLight *light;
        light = lib3ds_light_new("light0");
        light->spot_light = 0;
        light->see_cone = 0;
        light->color[0] = light->color[1] = light->color[2] = .6;
        light->position[0] = cx + isize * .75;
        light->position[1] = cy - isize * 1.;
        light->position[2] = cz + isize * 1.5;
        //light->position[3] = 0.;//TODO fix the array warning
        light->outer_range = 100;
        light->inner_range = 10;
        light->multiplier = 1;
        lib3ds_file_insert_light(file, light);

        light = lib3ds_light_new("light1");
        light->spot_light = 0;
        light->see_cone = 0;
        light->color[0] = light->color[1] = light->color[2] = .3;
        light->position[0] = cx - isize;
        light->position[1] = cy - isize;
        light->position[2] = cz + isize * .75;
        //light->position[3] = 0.;
        light->outer_range = 100;
        light->inner_range = 10;
        light->multiplier = 1;
        lib3ds_file_insert_light(file, light);

        light = lib3ds_light_new("light2");
        light->spot_light = 0;
        light->see_cone = 0;
        light->color[0] = light->color[1] = light->color[2] = .3;
        light->position[0] = cx;
        light->position[1] = cy + isize;
        light->position[2] = cz + isize;
        //light->position[3] = 0.;
        light->outer_range = 100;
        light->inner_range = 10;
        light->multiplier = 1;
        lib3ds_file_insert_light(file, light);
    }
    if (!file->cameras)
    {
        fputs("3dsplayer: Error: No Camera found.\n", stderr);
        lib3ds_file_free(file);
        file=0;
        exit(1);
    }
    if (currentCamera=="")
    {
        currentCamera=QString(file->cameras->name);
    }
    lib3ds_file_eval(file,0.);
    for(Lib3dsNode* p=file->nodes; p!=0; p=p->next) {
            render_node(p,true);
        }
}

void Q3dsModel::reload()
{
    reGenerate=true;
}

void Q3dsModel::render_node(Lib3dsNode *node, bool dryRun)
{
    ASSERT(file);
    {
        Lib3dsNode *p;
        for (p=node->childs; p!=0; p=p->next)//render recursively
        {
            render_node(p);
        }
    }
    if (node->type==LIB3DS_OBJECT_NODE)//if it is a mesh
    {
        Lib3dsMesh *mesh;
        QString nodeName(node->name);
        //if(nodeName.startsWith("_"))
        //    return;
        if (strcmp(node->name,"$$$DUMMY")==0)//why change the name to dummy?
        {
            return;
        }
        mesh = lib3ds_file_mesh_by_name(file, node->data.object.morph);//create a mesh
        if(mesh==NULL)//if creation unsuccessful, try again with other method
            mesh=lib3ds_file_mesh_by_name(file, node->name);
        if(reGenerate)
        {
            glDeleteLists(mesh->user.d, 1);
            mesh->user.d=NULL;
        }
        if (!mesh->user.d)
        {
            //TODO: make two objects and test the conjunction generation code
            // next step would be writing the code to connect two objects
            // when drawing the objects, it should follow the tree structure,
            // move around the conjunctions and rotate accordingly
            // should test only at the first run, and neglect in the future
            if(nodeName.startsWith("_"))
            {
                _conjunctions[nodeName].setPos(mesh->pointL->pos);
                qDebug()<<"found Conjunction: "<<nodeName<<_conjunctions[nodeName].x<<_conjunctions[nodeName].y<<_conjunctions[nodeName].z;
                return;
            }
            if(dryRun)
                return;
            //qDebug()<<"Node name is: "<<nodeName<<" at: "<<mesh->pointL->pos[0]<<mesh->pointL->pos[1]<<mesh->pointL->pos[2];
            ASSERT(mesh);
            if (!mesh) {
                return;
            }
            mesh->user.d=glGenLists(1);//create an OpenGL list and assign to the mesh
            glNewList(mesh->user.d, GL_COMPILE);
            {
                //enable gl blending for transparency
                glEnable(GL_BLEND);
                glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                unsigned p;
                Lib3dsVector *normalL=(Lib3dsVector*)malloc(3*sizeof(Lib3dsVector)*mesh->faces);//allocate normal line memory
                Lib3dsMaterial *oldmat = (Lib3dsMaterial *)-1;//old material
                {//create a matrix to multi to the list?
                    Lib3dsMatrix M;
                    lib3ds_matrix_copy(M, mesh->matrix);
                    lib3ds_matrix_inv(M);
                    glMultMatrixf(&M[0][0]);
                }
                lib3ds_mesh_calculate_normals(mesh, normalL);//calculate the normals
                for (p=0; p<mesh->faces; ++p)//for each face
                {
                    Lib3dsFace *f=&mesh->faceL[p];//grab the face pointer
                    Lib3dsMaterial *mat=0;//material pointer
                    Player_texture *pt = NULL;//texture pointer
                    int tex_mode = 0;//by default texture mode is 0
                    if (f->material[0])//if mesh has at least 1 material
                        mat=lib3ds_file_material_by_name(file, f->material);//load the material
                    //here check whether this material is to be replaced
                    //if so replace the material and skip the things
                    //qDebug()<<f->material;
                    if( mat != oldmat )//if it is a new material
                    {
                        //qDebug()<<"updating with new material"<<f->material<<colorMap.contains(f->material);
                        if(mat){
                            if(mat->two_sided)//if it is two sided then disable cull face to avoid Q3dsModel::mess up
                                glDisable(GL_CULL_FACE);
                            else
                                glEnable(GL_CULL_FACE);
                            glDisable(GL_CULL_FACE);//why? disabled by liu
                            if (mat->texture1_map.name[0])//if it has a texture mapping
                            {
                                Lib3dsTextureMap *tex=&mat->texture1_map;//grab the texture map
                                if (!tex->user.p)//if the texture is not loaded
                                {
                                    pt=(Player_texture*)malloc(sizeof(*pt));
                                    tex->user.p = pt;
                                    QString textureName=datapath;
                                    textureName+="/"+QString(tex->name);
                                    QImage img;
                                    //here there might be an alternative needed.
                                    retrieveTexture(img, textureName);
                                    //img.load(QString(textureName));
                                    QImage tex=QGLWidget::convertToGLFormat(img);
                                    int upload_format = GL_RED; /* safe choice, shows errors */
                                    //int bytespp=4;
                                    void *pixel = NULL;
                                    glGenTextures(1, &pt->tex_id);
                                    //                                            printf("Uploading texture to OpenGL, id %d, at %d bytepp\n",pt->tex_id, bytespp);
                                    pixel = tex.bits();
                                    upload_format = GL_RGBA;//incase bytespp=4
                                    glBindTexture(GL_TEXTURE_2D, pt->tex_id);
                                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEX_XSIZE, TEX_YSIZE, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
                                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
                                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
                                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                                    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
                                    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, tex.width(), tex.height(), upload_format, GL_UNSIGNED_BYTE, pixel);
                                    pt->scale_x = (float)tex.width()/(float)TEX_XSIZE;
                                    pt->scale_y = (float)tex.height()/(float)TEX_YSIZE;
                                    pt->valid = 1;
                                }
                                else
                                {
                                    pt=(Player_texture *)tex->user.p;
                                }
                                tex_mode = pt->valid;
                            }
                            else
                            {
                                tex_mode = 0;
                            }
                            //qDebug()<<"updating going ahead...";
                            qDebug()<<name<<"-----------------"<<f->material;
                            if(colorMap.contains(f->material))
                            {
                                QColor& c=colorMap[f->material];
                                double R,G,B,A;
                                R=c.redF();
                                G=c.greenF();
                                B=c.blueF();
                                A=c.alphaF();
                                //qDebug()<<"replacing color "<<R<<G<<B<<A;
                                Lib3dsRgba a={R,G,B,A};
                                Lib3dsRgba d={R,G,B,A};
                                Lib3dsRgba s={1.0, 1.0, 1.0, 1.0};
                                //set material properties
                                glMaterialfv(GL_FRONT, GL_AMBIENT, a);
                                glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
                                glMaterialfv(GL_FRONT, GL_SPECULAR, s);
                                glMaterialf(GL_FRONT, GL_SHININESS, pow(2, 10.0*0.5));
                                oldmat=mat;
                            }
                            else
                            {
                                 glMaterialfv(GL_FRONT, GL_AMBIENT, mat->ambient);
                                 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat->diffuse);
                                 glMaterialfv(GL_FRONT, GL_SPECULAR, mat->specular);
                                 glMaterialf(GL_FRONT, GL_SHININESS, pow(2, 10.0*mat->shininess));
                            }
                        }
                        else
                        {
                            QColor c;
                            c=c.fromRgb(255,0,255);
                            if(!highlighted)
                                c=defaultColor;
                            Lib3dsRgba a={c.redF(),c.greenF(),c.blueF(), c.alphaF()};
                            Lib3dsRgba d={c.redF(),c.greenF(),c.blueF(), c.alphaF()};
                            Lib3dsRgba s={1,1,1,1};
                            //const Lib3dsRgba a={0.7, 0.7, 0.7, 1.0};
                            //const Lib3dsRgba d={0.7, 0.7, 0.7, 1.0};
                            //const Lib3dsRgba s={1.0, 1.0, 1.0, 1.0};
                            //set material properties
                            glMaterialfv(GL_FRONT, GL_AMBIENT, a);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, s);
                            glMaterialf(GL_FRONT, GL_SHININESS, 50);
                        }
                        oldmat = mat;//update current material
                    }
                    else
                    if(mat!=NULL && mat->texture1_map.name[0])
                    {
                        Lib3dsTextureMap *tex = &mat->texture1_map;
                        if(tex!=NULL && tex->user.p!=NULL)
                        {
                            pt=(Player_texture*)tex->user.p;
                            tex_mode=pt->valid;
                         }
                    }
                    if(tex_mode)//if in texture mode, bind texture
                    {
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, pt->tex_id);
                    }
                    glBegin(GL_TRIANGLES);
                    glNormal3fv(f->normal);
                    for (int i=0; i<3; ++i) {
                        glNormal3fv(normalL[3*p+i]);
                        if (tex_mode)
                            glTexCoord2f(mesh->texelL[f->points[i]][1] *pt->scale_x, pt->scale_y - mesh->texelL[f->points[i]][0] *pt->scale_y);
                        glVertex3fv(mesh->pointL[f->points[i]].pos);
                    }
                    glEnd();
                    if(tex_mode)
                        glDisable(GL_TEXTURE_2D);
                }
                free(normalL);
            }
            glEndList();
        }
        if (mesh->user.d)//put into gl buffer
        {
            Lib3dsObjectData *d;
            glPushMatrix();
            d=&node->data.object;
            glMultMatrixf(&node->matrix[0][0]);
            glTranslatef(-d->pivot[0], -d->pivot[1], -d->pivot[2]);
            glCallList(mesh->user.d);
            glPopMatrix();
            if(iflush)
                glFlush();
        }
    }
}


void Q3dsModel::display(bool externCall)
{
    if(!externCall)
    {
        if(file!=NULL && file->background.solid.use)//put in the default background color
            glClearColor(file->background.solid.col[0], file->background.solid.col[1], file->background.solid.col[2],1.);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    //rotation, moving and scaling
    glTranslatef(xOffset,yOffset,zOffset);
/*
    glRotatef(xRotate, 1., 0., 0.);//rotate
    glRotatef(yRotate, 0., 1., 0.);
    glRotatef(zRotate, 0., 0., 1.);
*/
    //glTranslatef(axis.x,axis.y,axis.z);
    glRotatef(xBend, 1, 0, 0);//rotate
    glRotatef(yBend, 0, 1, 0);
    glRotatef(zBend, 0, 0, 1);
    //glTranslatef(-axis.x, -axis.y, -axis.z);

    glScalef(xScale,yScale,zScale);//scale
    if(highlighted)//draw bounding box
    {
    glBegin(GL_LINES);
    glShadeModel(GL_FLAT);
    glColor3f(0,1,0);
    glVertex3f(bmin[0],bmin[1],bmin[2]);
    glVertex3f(bmax[0],bmin[1],bmin[2]);
    glVertex3f(bmin[0],bmax[1],bmin[2]);
    glVertex3f(bmax[0],bmax[1],bmin[2]);
    glVertex3f(bmin[0],bmin[1],bmax[2]);
    glVertex3f(bmax[0],bmin[1],bmax[2]);
    glVertex3f(bmin[0],bmax[1],bmax[2]);
    glVertex3f(bmax[0],bmax[1],bmax[2]);

    glVertex3f(bmin[0],bmin[1],bmin[2]);
    glVertex3f(bmin[0],bmax[1],bmin[2]);
    glVertex3f(bmax[0],bmin[1],bmin[2]);
    glVertex3f(bmax[0],bmax[1],bmin[2]);
    glVertex3f(bmin[0],bmin[1],bmax[2]);
    glVertex3f(bmin[0],bmax[1],bmax[2]);
    glVertex3f(bmax[0],bmin[1],bmax[2]);
    glVertex3f(bmax[0],bmax[1],bmax[2]);

    glVertex3f(bmin[0],bmin[1],bmin[2]);
    glVertex3f(bmin[0],bmin[1],bmax[2]);
    glVertex3f(bmax[0],bmin[1],bmin[2]);
    glVertex3f(bmax[0],bmin[1],bmax[2]);
    glVertex3f(bmin[0],bmax[1],bmin[2]);
    glVertex3f(bmin[0],bmax[1],bmax[2]);
    glVertex3f(bmax[0],bmax[1],bmin[2]);
    glVertex3f(bmax[0],bmax[1],bmax[2]);

    glEnd();
    }
    if(show_object)//draw self
    {
        for(Lib3dsNode* p=file->nodes; p!=0; p=p->next) {
            render_node(p);
        }
    }
    glScalef(1/xScale,1/yScale,1/zScale);//scale back because scale shouldn't be inherited
    foreach(Q3dsModel* model, children)//draw children
    {
        glPushMatrix();
        model->display(externCall);
        glPopMatrix();
    }
    //TODO: rotate back, Not fully correct yet
    //glTranslatef(axis.x,axis.y,axis.z);
    glRotatef(-xBend, 1, 0, 0);//rotate
    glRotatef(-yBend, 0, 1, 0);
    glRotatef(-zBend, 0, 0, 1);
    //glTranslatef(-axis.x, -axis.y, -axis.z);

    glTranslatef(-xOffset,-yOffset,-zOffset);
 }

void Q3dsModel::mouse_move(QMouseEvent* event)
{
    if( event->buttons()==Qt::LeftButton)
    {
        view_rotz += 0.1 * (event->x() - mx);
        view_rotx += 0.1 * (event->y() - my);
        update();
    }
    mx = event->x();
    my = event->y();
}
void Q3dsModel::key_press(QKeyEvent* event)
{
    int keyCode=event->key();
    if(keyCode==Qt::Key_X)
        currentCamera="Camera_X";
    if(keyCode==Qt::Key_Y)
        currentCamera="Camera_Y";
    if(keyCode==Qt::Key_Z)
        currentCamera="Camera_Z";
    if(keyCode==Qt::Key_I)
        currentCamera="Camera_ISO";
    view_rotx = view_roty = view_rotz = anim_rotz = 0.;
    update();
}
void Q3dsModel::wheel(QWheelEvent* event)
{
    if(event->delta()>0)
        zoom*=1.1;
    else
        zoom*=0.9;
    update();
}
void Q3dsModel::mouseMoveEvent(QMouseEvent* event)
{
    mouse_move(event);
}
void Q3dsModel::keyPressEvent(QKeyEvent* event)
{
    key_press(event);
}
void Q3dsModel::wheelEvent(QWheelEvent* event)
{
    wheel(event);
}
void Q3dsModel::initGL()
{
    initializeGL();
}
void Q3dsModel::resize(int w, int h)
{
    resizeGL(w,h);
}
void Q3dsModel::scale(float x, float y, float z)
{
    xScale=x;yScale=y;zScale=z;
}
void Q3dsModel::scaleTo(float x)//, float y, float z)
{
    modelSize=x;
    xScale=yScale=zScale=x/sx;
}
void Q3dsModel::move(float x, float y, float z)
{
    xOffset+=x;yOffset+=y;zOffset+=z;
}
void Q3dsModel::moveTo(float x, float y, float z)
{
    xOffset=x;yOffset=y;zOffset=z;
}
void Q3dsModel::rotate(float x, float y, float z)
{
    xRotate+=x;yRotate+=y;zRotate+=z;
}
void Q3dsModel::rotateTo(float x, float y, float z)
{
    xRotate=x;yRotate=y;zRotate=z;
}
void Q3dsModel::paintGL()
{
    display(false);
}
void Q3dsModel::resizeGL(int width, int height)
{
    gl_width=width;
    gl_height=height;
    //            glViewport(0,0,width,height);
}
void Q3dsModel::initializeGL()
{
    glClearColor(0.5, 0.7, 0.5, 1.0);
    //    glShadeModel(GL_SMOOTH);
    GLfloat light_ambient [] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse [] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 0, 0, 0, 0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT , light_ambient );
    glLightfv(GL_LIGHT0, GL_DIFFUSE , light_diffuse );
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glDisable(GL_LIGHT1);
    //glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    //glCullFace(GL_BACK);
    //glEnable(GL_NORMALIZE);
    //glPolygonOffset(1.0, 2);
    //Q3dsTools::create_icons();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    qDebug()<<"called...";
}

Q3dsPoint& Q3dsModel::conjunction(QString name)
{
    //qDebug()<<"****************"<<name;
    if(!_conjunctions.contains(name))
        qDebug()<<"conjunction name not found: "<<name;
    return _conjunctions[name];
}

void Q3dsModel::addChildToAxis(Q3dsModel* child, QString axis, QString conjunction)
{
    //display(true);
    //child->display(true);
    if(!_conjunctions.contains(conjunction))
        qDebug()<<"conjunction name not found: "<<conjunction;
    Q3dsPoint p1=_conjunctions[conjunction];
    Q3dsPoint& p2=child->conjunction(axis);
    qDebug()<<"-------------------"<<p1.x<<p2.y;
    child->move((p1.x-p2.x)*xScale, (p1.y-p2.y)*yScale, (p1.z-p2.z)*zScale);
    child->_axis.x=p2.x;
    child->_axis.y=p2.y;
    child->_axis.z=p2.z;
    children<<child;
    child->father=this;
    child->axisConjunction=conjunction;
    child->axisPoint=axis;
}

void Q3dsModel::removeChild(Q3dsModel* child)
{
    children.removeOne(child);
}

void Q3dsModel::bend(float x, float y, float z)
{
    xBend+=x;
    yBend+=y;
    zBend+=z;
}

QList<Q3dsModel*> Q3dsModel::allChildren()
{
    QList<Q3dsModel*> list;
    list<<children;
    foreach(Q3dsModel* m, children)
        list<<m->allChildren();
    return list;
}

QString Q3dsModel::axis()
{
    if(father)
        return father->name+"."+axisConjunction;
    else
        return "";
}

QStringList Q3dsModel::conjunctions()
{
    QStringList list;
    list<<_conjunctions.keys();
    return list;
}

QDomElement Q3dsModel::toXml(QDomDocument* doc)
{
    //convert the model and children into a xml tree element
    QDomElement me=doc->createElement("part");
    me.setAttribute("name", this->name);
    me.setAttribute("size", this->modelSize);
    me.setAttribute("offset", QString("%1,%2,%3").arg(xOffset).arg(yOffset).arg(zOffset));
    me.setAttribute("file",this->modelFile);
    if(father)
        me.setAttribute("axis", QString("%1=%2->%3").arg(this->axisPoint).arg(father->name).arg(this->axisConjunction));
    me.setAttribute("bend", QString("%1,%2,%3").arg(xBend).arg(yBend).arg(zBend));
    me.setAttribute("rotation","N/A");
    foreach(Q3dsModel* child, this->children)
        me.appendChild(child->toXml(doc));
    qDebug()<<"total attributes: "<<me.attributes().count();
    return me;
}

void Q3dsModel::fromXml(QDomElement e, Q3dsModel* p)
{
    //construct the model with children from a xml file
    name=e.attribute("name");
    this->loadModel(e.attribute("file"));
    if(e.hasAttribute("axis"))
    {
        QStringList l=e.attribute("axis").split("=");
        QString axis=l.at(0);
        QStringList t=l.at(1).split("->");
        QString parent=t.at(0);//unused parent name
        QString conjunction=t.at(1);
        p->addChildToAxis(this,axis,conjunction);
        qDebug()<<"connecting "<<name<<" to "<<parent<<"."<<conjunction;
    }
    if(e.hasAttribute("size"))
        scaleTo(e.attribute("size").toDouble());
    if(e.hasAttribute("name"))
        name=e.attribute("name");
    if(e.hasAttribute("offset"))
    {
        QStringList l=e.attribute("offset").split(",");
        this->moveTo(l.at(0).toDouble(), l.at(1).toDouble(), l.at(2).toDouble());
    }
    if(e.hasAttribute("bend"))
    {
        QStringList l=e.attribute("bend").split(",");
        this->bend(l.at(0).toDouble(), l.at(1).toDouble(), l.at(2).toDouble());
    }
    if(e.hasAttribute("rotation"))
    {
    }

    QDomNodeList nodes=e.childNodes();
    for(int i=0;i<nodes.count();i++)
    {
        Q3dsModel* m=new Q3dsModel();
        m->fromXml(nodes.at(i).toElement(), this);
    }
}
