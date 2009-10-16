#ifndef Q3DSMODEL_H
#define Q3DSMODEL_H

#include <QGLWidget>
#include "q3dstools.h"

class Player_texture
{
    public:
        int valid;
        void *bitmap;
        GLuint tex_id;
        float scale_x, scale_y;
};

class Q3dsPoint
{
    public:
        float x,y,z;
        Q3dsPoint(){x=y=z=0;};
        void setPos(float* p){
            x=p[0];y=p[1];z=p[2];
        }
};

class Q3dsModel:public QGLWidget
{
    public:
        Q3dsModel(QString modelFile="", QWidget* parent=0);
        void resize(int w, int h);
        void scale(float x, float y, float z);
        void scaleTo(float x);
        void move(float x, float y, float z);
        void moveTo(float x, float y, float z);
        void rotate(float x, float y, float z);
        void rotateTo(float x, float y, float z);
        void display(bool externCall=true);
        void wheel(QWheelEvent* event);
        void key_press(QKeyEvent* event);
        void mouse_move(QMouseEvent* event);
        void replaceColor(QString colorName, QColor color);
        void loadModel(QString fileName);
        void initGL();
        Q3dsPoint& conjunction(QString name, Q3dsPoint p);
        void setAxis(Q3dsPoint& p);
    protected:
        void paintGL();
        void initializeGL();
        void resizeGL(int width, int height);
        void mouseMoveEvent(QMouseEvent* event);
        void keyPressEvent(QKeyEvent* event);
        void wheelEvent(QWheelEvent* event);
        virtual void retrieveTexture(QImage& picture, QString fileName);
    private:
        void draw_light(const GLfloat *pos, const GLfloat *color);
        void draw_bounds(Lib3dsVector tgt);
        void light_update(Lib3dsLight *l);
        void render_node(Lib3dsNode *node);
    private:
        QMap<QString, Q3dsPoint> conjunctions;//conjunctions pool
        int TEX_XSIZE, TEX_YSIZE;
        float zoom;
        QString datapath,objName;
        QString currentCamera;
        Lib3dsFile *file;
        bool iflush;
        bool anti_alias;
        int gl_width, gl_height;
        bool show_object, show_bounds, show_cameras, show_lights;
        Lib3dsVector bmin, bmax;
        float	sx, sy, sz, isize;
        float	cx, cy, cz;
        float xRotate,yRotate,zRotate,xOffset,yOffset,zOffset,xScale,yScale,zScale;
        float	view_rotx , view_roty , view_rotz ;
        float	anim_rotz ;
        int	mx, my;
        QMap<QString, QColor> colorMap;
        Q3dsPoint axis;
};

Q3dsModel::Q3dsModel(QString modelFile, QWidget* parent):QGLWidget(parent)
{
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
    xOffset=yOffset=zOffset=0;
    xScale=yScale=zScale=1;
    TEX_XSIZE=TEX_YSIZE=1024;
    if(modelFile!="")
        loadModel(modelFile);
}
void Q3dsModel::retrieveTexture(QImage& picture, QString fileName)
{
    picture.load(fileName);
}
void Q3dsModel::replaceColor(QString colorName, QColor color)
{
    colorMap[colorName]=color;
}
void Q3dsModel::loadModel(QString fileName)
{
    //decompose file name and data path
    int slash=fileName.lastIndexOf('/');
    datapath=fileName.left(slash);
    fileName=fileName.mid(slash+1);
    objName=fileName;
    if(slash==-1)
        datapath=".";
    //load the model file
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
    cx = (bmin[0] + bmax[0])/2;
    cy = (bmin[1] + bmax[1])/2;
    cz = (bmin[2] + bmax[2])/2;
    qDebug()<<cx<<cy<<cz;
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
}

void Q3dsModel::render_node(Lib3dsNode *node)
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
        if (!mesh->user.d)
        {
            //TODO: make two objects and test the conjunction generation code
            // next step would be writing the code to connect two objects
            // when drawing the objects, it should follow the tree structure,
            // move around the conjunctions and rotate accordingly
            // should test only at the first run, and neglect in the future
            if(nodeName.startsWith("_"))
            {
                conjunctions[nodeName].setPos(mesh->pointL->pos);
                qDebug()<<"found Conjunction: "<<nodeName<<conjunctions[nodeName].x<<conjunctions[nodeName].y<<conjunctions[nodeName].z;
                return;
            }
            qDebug()<<"Node name is: "<<nodeName<<" at: "<<mesh->pointL->pos[0]<<mesh->pointL->pos[1]<<mesh->pointL->pos[2];
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
                            const Lib3dsRgba a={0.7, 0.7, 0.7, 1.0};
                            const Lib3dsRgba d={0.7, 0.7, 0.7, 1.0};
                            const Lib3dsRgba s={1.0, 1.0, 1.0, 1.0};
                            //set material properties
                            glMaterialfv(GL_FRONT, GL_AMBIENT, a);
                            glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
                            glMaterialfv(GL_FRONT, GL_SPECULAR, s);
                            glMaterialf(GL_FRONT, GL_SHININESS, pow(2, 10.0*0.5));
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

void Q3dsModel::light_update(Lib3dsLight *l)
{
    Lib3dsNode *ln, *sn;
    ln = lib3ds_file_node_by_name(file, l->name, LIB3DS_LIGHT_NODE);
    sn = lib3ds_file_node_by_name(file, l->name, LIB3DS_SPOT_NODE);
    if(ln!= NULL)
    {
        memcpy(l->color, ln->data.light.col, sizeof(Lib3dsRgb));
        memcpy(l->position, ln->data.light.pos, sizeof(Lib3dsVector));
    }
    if( sn != NULL )
        memcpy(l->spot, sn->data.spot.pos, sizeof(Lib3dsVector));
}

void Q3dsModel::draw_bounds(Lib3dsVector tgt)
{
    //qDebug()<<bmin[0]<<bmax[0]<<sx;
    const GLfloat white[4] = {1.,1.,1.,1.};
    const GLfloat red[4] = {1.,0.,0.,1.};
    const GLfloat green[4] = {0.,1.,0.,1.};
    const GLfloat blue[4] = {0.,0.,1.,1.};
    double cx,cy,cz;
    double lx,ly,lz;
    lx = sx / 10.; ly = sy / 10.; lz = sz / 10.;
    cx = tgt[0]; cy = tgt[1]; cz = tgt[2];
    glDisable(GL_LIGHTING);
    glColor4fv(white);
    glBegin(GL_LINES);
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

    glVertex3f(cx-isize/32, cy, cz);
    glVertex3f(cx+isize/32, cy, cz);
    glVertex3f(cx, cy-isize/32, cz);
    glVertex3f(cx, cy+isize/32, cz);
    glVertex3f(cx, cy, cz-isize/32);
    glVertex3f(cx, cy, cz+isize/32);
    glEnd();

    glColor4fv(red);
    glBegin(GL_LINES);
    glVertex3f(0.,0.,0.);
    glVertex3f(lx,0.,0.);
    glEnd();

    glColor4fv(green);
    glBegin(GL_LINES);
    glVertex3f(0.,0.,0.);
    glVertex3f(0.,ly,0.);
    glEnd();

    glColor4fv(blue);
    glBegin(GL_LINES);
    glVertex3f(0.,0.,0.);
    glVertex3f(0.,0.,lz);
    glEnd();

    glEnable(GL_LIGHTING);
}

void Q3dsModel::draw_light(const GLfloat *pos, const GLfloat *color)
{
    glMaterialfv(GL_FRONT, GL_EMISSION, color);
    glPushMatrix();
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(isize/20, isize/20, isize/20);
    glCallList(Q3dsTools::getLightList());
    glPopMatrix();
}

void Q3dsModel::display(bool externCall)
{
    /*            Lib3dsNode *c,*t;
                  Lib3dsFloat fov=0, roll=0;
                  float near, far, dist;
                  float *campos=0;
                  float *tgt=0;
                  Lib3dsMatrix M;
                  Lib3dsCamera *cam;
                  Lib3dsVector v;
                  Lib3dsNode *p;
                  if(!externCall)
                  {
                  if(file!=NULL && file->background.solid.use)//put in the default background color
                  glClearColor(file->background.solid.col[0], file->background.solid.col[1], file->background.solid.col[2],1.);
                  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                  }
                  if(anti_alias)
                  glEnable(GL_POLYGON_SMOOTH);
                  else
                  glDisable(GL_POLYGON_SMOOTH);
                  if (!file)
                  return;
                  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, file->ambient);
                  c=lib3ds_file_node_by_name(file, currentCamera.toAscii().constData(), LIB3DS_CAMERA_NODE);//get the camera
                  t=lib3ds_file_node_by_name(file, currentCamera.toAscii().constData(), LIB3DS_TARGET_NODE);//get the target
                  if(t!=NULL)
                  tgt = t->data.target.pos;//get target pos
                  if( c!= NULL ) {
                  fov = c->data.camera.fov;//get camera details
                  roll = c->data.camera.roll;
                  campos = c->data.camera.pos;
                  }
                  if((cam=lib3ds_file_camera_by_name(file,currentCamera.toAscii().constData()))==NULL)
                  return;
                  near = cam->near_range;//get its near range
                  far = cam->far_range;//get its far range if ISO camera, it should be just 1.5 times of size away
                  if (c == NULL || t == NULL) {
                  if( c == NULL ) {
                  fov = cam->fov;
                  roll = cam->roll;
                  campos = cam->position;
                  }
                  if( t == NULL )
                  tgt = cam->target;
                  }
                  */
    if(!externCall)
    {
        if(file!=NULL && file->background.solid.use)//put in the default background color
            glClearColor(file->background.solid.col[0], file->background.solid.col[1], file->background.solid.col[2],1.);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //            if( near <= 0. ) near = far * .001;
    //            gluPerspective(fov, 1.0*gl_width/gl_height, near, far);//set the perspective of the view
    gluPerspective(45,1,1,10000);//set the perspective of the view
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //            glRotatef(-90, 1.0,0,0);
    // User rotates the view about the target point
    //            lib3ds_vector_sub(v, tgt, campos);
    //            dist = lib3ds_vector_length(v);
    //            glTranslatef(0. ,dist, 0.);
    glTranslatef(0,0,-3000);
    glRotatef(view_rotx, 1., 0., 0.);//rotate
    glRotatef(view_roty, 0., 1., 0.);
    glRotatef(view_rotz, 0., 0., 1.);
    glTranslatef(xOffset,yOffset,zOffset);
    glRotatef(xRotate, 1., 0., 0.);//rotate
    glRotatef(yRotate, 0., 1., 0.);
    glRotatef(zRotate, 0., 0., 1.);
    glScalef(xScale,yScale,zScale);//scale
    glTranslatef(-cx,-cy,-cz);//put it back to 0,0,0
    /*
       glTranslatef(0,0,-2000);
       glRotatef(view_rotx, 1., 0., 0.);//rotate
       glRotatef(view_roty, 0., 1., 0.);
       glRotatef(view_rotz, 0., 0., 1.);
       glTranslatef(-cx,-cy,-cz);//put it to 0,0,0 centered position
       glTranslatef(xOffset,yOffset,zOffset);
       glScalef(xScale,yScale,zScale);//scale
       glRotatef(xRotate, 1., 0., 0.);//rotate
       glRotatef(yRotate, 0., 1., 0.);
       glRotatef(zRotate, 0., 0., 1.);
       */

    //            glTranslatef(0.,-dist, 0.);
    //            lib3ds_matrix_camera(M, campos, tgt, roll);
    //            glMultMatrixf(&M[0][0]);
    if(show_object)
    {
        for(Lib3dsNode* p=file->nodes; p!=0; p=p->next) {
            render_node(p);
        }
    }
    /*            if(show_bounds)
                  draw_bounds(tgt);
                  if(show_cameras)
                  {
                  for( cam = file->cameras; cam != NULL; cam = cam->next )
                  {
                  lib3ds_matrix_camera(M, cam->position, cam->target, cam->roll);
                  lib3ds_matrix_inv(M);
                  glPushMatrix();
                  glMultMatrixf(&M[0][0]);
                  glScalef(isize/20, isize/20, isize/20);
                  glCallList(Q3dsTools::getCameraList());
                  glPopMatrix();
                  }
                  }
                  if( show_lights )
                  {
                  Lib3dsLight *light;
                  for(light = file->lights; light!= NULL; light=light->next)
                  draw_light(light->position, light->color);
                  const GLfloat black[4] = {0.,0.,0.,1.};
                  glMaterialfv(GL_FRONT, GL_EMISSION, black);
                  }
                  */
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
    glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glDisable(GL_LIGHT1);
    //glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    //glCullFace(GL_BACK);
    //glEnable(GL_NORMALIZE);
    //glPolygonOffset(1.0, 2);
    //Q3dsTools::create_icons();
}

Q3dsPoint& Q3dsModel::conjunction(QString name, Q3dsPoint p)
{
    return conjunctions[name];
}

void Q3dsModel::setAxis(Q3dsPoint& p)
{
    axis.x=p.x;
    axis.y=p.y;
    axis.z=p.y;
}

#endif
