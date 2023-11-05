#ifndef ARCHIVODESAFIO_H
#define ARCHIVODESAFIO_H

#include "Desafio.h"


class ArchivoDesafio
{
    private:
        char nombre[30];



    public:
        ArchivoDesafio(const char *n)
        {
            strcpy(nombre,n);
        }
        void agregarRegistro()
        {

             FILE *p;
             Desafio d;
             p=fopen(nombre,"ab+");
             int ultimoID=0;
             if(p==NULL)
             { cout<<"Error de archivo";
             exit(1);
             }
             while (fread(&d, sizeof(Desafio), 1, p)) {
                if (d.getID() > ultimoID) {
                    ultimoID = d.getID();
                }
            }
             d.Cargar(ultimoID);
             fwrite(&d, sizeof(Desafio),1,p);
             fclose(p);
        }
        void eliminarRegistro()
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


        }
        void sumarUsuario(int id)
        {
             FILE *p;
             Desafio reg;
             p=fopen("desafios.dat","rb+");
             if(p==NULL)
             { cout<<"Error de archivo";
             }
             while (fread(&reg, sizeof(Desafio), 1, p)==1) {
                    if (reg.getID() == id)
                    {

                        reg.sumarCantidad();


                         fseek(p, ftell(p)-sizeof reg, 0);
                         fwrite(&reg, sizeof reg, 1, p);
                         fclose(p);
                    }

             }

             fclose(p);


        }
        int contarRegistros()
        {
            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Desafio);
        }
        Desafio leerRegistro(int pos)
        {

            Desafio reg;

            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return reg;

            fseek(p, sizeof reg*pos,0);
            fread(&reg, sizeof reg,1, p);

            fclose(p);
            return reg;
        }
};

#endif // ARCHIVODESAFIO_H
