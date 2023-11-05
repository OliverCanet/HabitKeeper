#ifndef HABITO_H
#define HABITO_H

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "Fecha.h"


class Habito
{
    private:
        int id;
        char nombre[30];
        int dni;
        char descripcion[40];
        int completado[12][31];
        bool estado;
        Fecha fecha;



    public:
        Habito()
        {

        }
        Habito(int DNI)
        {
            dni=DNI;
            estado=true;
            for(int i=0;i<12;i++)
            {
                for(int j=0;j<31;j++)
                {
                    completado[i][j]=0;
                }
            }



        }
        int getDNI(){return dni;}
        int getID(){return id;}
        int getDia(){return fecha.getDia();}
        int getMes(){return fecha.getMes();}
        char *getNombre() {return nombre;}
        bool getEstado(){return estado;}
        void setCompletado(int com){completado[fecha.getMes()][fecha.getDia()]=com;}
        void setEstado(bool e){estado=e;}
        void Cargar(int ID,int DNI)
        {
            dni=DNI;
            id=++ID;
            cout<<"CARGAR NOMBRE: "<<endl;
            cargarCadena(nombre,29);
            cout<<"CARGAR DESCRIPCION: "<<endl;
            cargarCadena(descripcion,29);
            for(int i=0;i<12;i++)
            {
                for(int j=0;j<31;j++)
                {
                    completado[i][j]=0;
                }
            }


        }
        void Mostrar()
        {
            cout<<"ID: "<<id<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"DESCRIPCION: "<<descripcion<<endl;
            cout<<"DIAS COMPLETADOS DEL MES "<<fecha.getMes()<<": "<<endl;
            for(int i=1;i<31;i++)
            {


                if(completado[fecha.getMes()][i]==1)
                {
                    cout<<i<<" | ";
                }
            }
            cout<<endl;
        }
};

#endif // HABITO_H
