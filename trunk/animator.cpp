#include "animator.h"

Model::Model()
{

}

Node::Node(QString n)
{
    name=n;
}

void Model::loadModel(QString) //fileName)
{
    Lib3dsFile *file=lib3ds_file_load("dole.3ds");//TODO: tmp
    Lib3dsNode *node;
    for(node=file->nodes;node!=NULL;node=node->next)//create Nodes for the file
    {
        Node* n=new Node(node->name);
        n->createDisplayLists(node, file);//create the display list for this node
        this->nodes<<n;//add it to the model's node list
    }
    //delete the file object
}

void Node::createDisplayLists(Lib3dsNode* node, Lib3dsFile* file)
{
    for(Lib3dsNode* p=node->childs; p!=0; p=p->next)//render recursively
        createDisplayLists(p, file);
    if (node->type==LIB3DS_OBJECT_NODE)//if it is an object node
    {
        Lib3dsMesh *mesh;
        if (strcmp(node->name,"$$$DUMMY")==0)//? TODO: refactor the next lines
            return;
        mesh=lib3ds_file_mesh_by_name(file, node->data.object.morph);//create a mesh
        if(mesh==NULL)//if creation unsuccessful, try again with other method
            mesh=lib3ds_file_mesh_by_name(file, node->name);
        GLuint nl=glGenLists(1);//create an OpenGL list and assign to the mesh

        glNewList(nl, GL_COMPILE);
        glEnable(GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 /*       Lib3dsVector *normalL=(Lib3dsVector*)malloc(3*sizeof(Lib3dsVector)*mesh->faces);
        Lib3dsMaterial *oldmat = (Lib3dsMaterial *)-1;//old material

        Lib3dsMatrix M;
        lib3ds_matrix_copy(M, mesh->matrix);
        lib3ds_matrix_inv(M);
        glMultMatrixf(&M[0][0]);

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
            if( mat != oldmat )//if it is a new material
            {
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
                            QString datapath="";
                            QString textureName=datapath;
                            textureName+="/"+QString(tex->name);
                            QImage img;
                            //here there might be an alternative needed.
                            //retrieveTexture(img, textureName);
                            img.load(QString(textureName));
                            QImage tex=QGLWidget::convertToGLFormat(img);
                            int upload_format = GL_RED;
                            //int bytespp=4;
                            void *pixel = NULL;
                            glGenTextures(1, &pt->tex_id);
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
        free(normalL);*/
        glEndList();
        displayLists<<nl;
    }
}
