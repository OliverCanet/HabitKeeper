#ifndef ARCHIVOHABITO_H
#define ARCHIVOHABITO_H

#include "Habito.h"


class ArchivoHabito
{
    private:
        char nombre[30];



    public:
        ArchivoHabito(const char *n)
        {
            strcpy(nombre,n);
        }
        void agregarRegistro(int dni)
        {
             FILE *p;
             Habito h(dni);
             p=fopen(nombre,"ab+");
             int ultimoID=0;
             if(p==NULL)
             { cout<<"Error de archivo";
             exit(1);
             }
             while (fread(&h, sizeof(Habito), 1, p)) {
                if (h.getID() > ultimoID) {
                    ultimoID = h.getID();
                }
            }
             h.Cargar(ultimoID,dni);
             fwrite(&h, sizeof(Habito),1,p);
             fclose(p);
        }

        void modificarRegistro(int com)
        {
             FILE *p;
             Habito reg;
             p=fopen("habitos.dat","rb+");
             if(p==NULL)
             { cout<<"Error de archivo";
             }
             int id;
             cout<<"INGRESAR ID DE HABITO COMPLETADO: "<<endl;
             cin>>id;
             while (fread(&reg, sizeof(Habito), 1, p)==1) {
                    if (reg.getID() == id )
                    {

                        reg.setCompletado(com);


                         fseek(p, ftell(p)-sizeof reg, 0);
                         fwrite(&reg, sizeof reg, 1, p);
                         fclose(p);
                    }

             }

             fclose(p);


        }
        void eliminarRegistro()
        {
             FILE *p;
             Habito reg;
             p=fopen("habitos.dat","rb+");
             if(p==NULL)
             { cout<<"Error de archivo";
             }
             int id;
             cout<<"INGRESAR ID DE HABITO A ELIMINAR: "<<endl;
             cin>>id;
             while (fread(&reg, sizeof(Habito), 1, p)==1) {
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

        int contarRegistros()
        {
            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Habito);
        }
        Habito leerRegistro(int pos,int dni)
        {

            Habito reg(dni);

            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return reg;

            fseek(p, sizeof reg*pos,0);
            fread(&reg, sizeof reg,1, p);

            fclose(p);
            return reg;
        }

};

#endif // ARCHIVOHABITO_H
