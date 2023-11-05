#ifndef ARCHIVODESAFIOUSUARIO_H
#define ARCHIVODESAFIOUSUARIO_H

#include "DesafioUsuario.h"
#include "ArchivoDesafio.h"

class ArchivoDesafioUsuario
{
    private:
        char nombre[30];



    public:
        ArchivoDesafioUsuario(const char *n)
        {
            strcpy(nombre,n);
        }
        void agregarRegistro(int id,int dni,const char *nU)
        {
             FILE *p;
             DesafioUsuario aux2;
             Desafio reg;
             ArchivoDesafio aux("desafios.dat");
             p=fopen(nombre,"ab+");
             if(p==NULL)
             { cout<<"Error de archivo";
             exit(1);
             }
             char nD[30]={};
             char d[30]={};
             int cant = aux.contarRegistros();
             for(int i=0;i<cant;i++)
             {
                reg=aux.leerRegistro(i);
                if(reg.getID()==id&&reg.getEstado()==true)
                {

                    strcpy(nD,reg.getNombre());
                    strcpy(d,reg.getDescripcion());
                }
             }

             aux2.Cargar(id,dni,nU,nD,d);
             fwrite(&aux2, sizeof(DesafioUsuario),1,p);
             fclose(p);
        }
        void modificarRegistro(int com,int dni)
        {
             FILE *p;
             DesafioUsuario reg;
             p=fopen("desafiousuarios.dat","rb+");
             if(p==NULL)
             { cout<<"Error de archivo";
             }
             int id;
             cout<<"INGRESAR ID DE DESAFIO COMPLETADO: "<<endl;
             cin>>id;
             while (fread(&reg, sizeof(DesafioUsuario), 1, p)==1) {
                    if (reg.getID() == id && reg.getDNI() == dni)
                    {

                        reg.setCompletado(com);


                         fseek(p, ftell(p)-sizeof reg, 0);
                         fwrite(&reg, sizeof reg, 1, p);
                         fclose(p);
                    }

             }

             fclose(p);


        }
        /*void eliminarRegistro()
        {
             FILE *p;
             Desafio reg;
             p=fopen("desafios.dat","rb+");
             if(p==NULL)
             { cout<<"Error de archivo";
             }
             int id;
             cout<<"INGRESAR ID DE DESAFIO A ELIMINAR: "<<endl;
             cin>>id;
             while (fread(&reg, sizeof(Desafio), 1, p)==1) {
                    if (reg.getID() == id )
                    {

                        reg.setEstado(false);


                         fseek(p, ftell(p)-sizeof reg, 0);
                         fwrite(&reg, sizeof reg, 1, p);
                         fclose(p);
                    }

             }

             fclose(p);


        }*/

        int contarRegistros()
        {
            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(DesafioUsuario);
        }
        DesafioUsuario leerRegistro(int pos)
        {

            DesafioUsuario reg;

            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return reg;

            fseek(p, sizeof reg*pos,0);
            fread(&reg, sizeof reg,1, p);

            fclose(p);
            return reg;
        }
};

#endif // ARCHIVODESAFIOUSUARIO_H
