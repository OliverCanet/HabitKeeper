#ifndef ARCHIVOUSUARIO_H
#define ARCHIVOUSUARIO_H

#include "Usuario.h"


class ArchivoUsuario
{
    private:
        char nombre[30];



    public:
        ArchivoUsuario(const char *n)
        {
            strcpy(nombre,n);
        }
        void agregarRegistro()
        {
             FILE *p;
             Usuario u;
             p=fopen(nombre,"ab");
             if(p==NULL)
             { cout<<"Error de archivo";
             exit(1);
             }
             u.Cargar();
             fwrite(&u, sizeof(Usuario),1,p);
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
            return tam/sizeof(Usuario);
        }
        Usuario leerRegistro(int pos)
        {

            Usuario reg;

            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return reg;

            fseek(p, sizeof reg*pos,0);
            fread(&reg, sizeof reg,1, p);

            fclose(p);
            return reg;
        }
};

#endif // ARCHIVOUSUARIO_H
