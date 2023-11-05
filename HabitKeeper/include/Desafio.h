#ifndef DESAFIO_H
#define DESAFIO_H


class Desafio
{
    private:
        char nombre[30];
        char descricpcion[30];
        int id;
        int cantAnotados;
        bool estado;

    public:
        Desafio()
        {
            estado=true;
            cantAnotados=0;
        }
        bool getEstado(){return estado;}
        int getID(){return id;}
        char *getNombre(){return nombre;}
        char *getDescripcion(){return descricpcion;}
        void setEstado(bool est){estado=est;}
        void sumarCantidad(){cantAnotados++;}
        void Cargar(int ID)
        {
            id=++ID;
            cout<<"INGRESAR NOMBRE DEL DESAFIO: "<<endl;
            cargarCadena(nombre,30);
            cout<<"INGRESAR DESCRIPCION DEL DESAFIO: "<<endl;
            cargarCadena(descricpcion,30);
            cantAnotados=0;


        }
        void Mostrar()
        {
            cout<<"ID: "<<id<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"DESCRIPCION: "<<descricpcion<<endl;
            cout<<"CANTIDAD ANOTADOS: "<<cantAnotados<<endl;

            cout<<endl;
        }
};

#endif // DESAFIO_H
