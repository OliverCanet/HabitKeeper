#ifndef USUARIO_H
#define USUARIO_H

#include "Habito.h"
#include "../globales.h"


class Usuario
{
    private:
        int DNI;
        char nombre[30];
        char titulo[30];
        bool estado;



    public:
        Usuario()
        {
            strcpy(titulo,"Madera");
            estado=true;
        }
        int getDNI() {return DNI;}
        char *getNombre() {return nombre;}
        void Cargar()
        {
            cout<<"CARGAR DNI: "<<endl;
            cin>>DNI;
            cout<<"CARGAR NOMBRE: "<<endl;
            cargarCadena(nombre,29);


        }
        void Mostrar()
        {
            cout<<"DNI: "<<DNI<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"TITULO: "<<titulo<<endl;
            cout<<"ESTADO: "<<estado<<endl;
        }
};

#endif // USUARIO_H
