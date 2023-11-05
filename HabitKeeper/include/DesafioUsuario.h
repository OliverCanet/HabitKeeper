#ifndef DESAFIOUSUARIO_H
#define DESAFIOUSUARIO_H


class DesafioUsuario
{
    private:
        char nombreUsuario[30];
        char nombreDesafio[30];
        char descripcion[30];
        int diaComenzado;
        int dniUsuario;
        int idDesafio;
        int completado;
        bool estado;
        Fecha fecha;

    public:
        DesafioUsuario()
        {
            estado=true;
            completado=0;
        }
        bool getEstado(){return estado;}
        int getID(){return idDesafio;}
        int getDNI(){return dniUsuario;}
        char *getNombre(){return nombreUsuario;}
        char *getDescripcion(){return descripcion;}
        void setEstado(bool est){estado=est;}
        void setCompletado(int com){completado=com;}
        void Cargar(int id,int dni,const char *nombre,const char *desafio,const char *desc)
        {
            idDesafio=id;
            dniUsuario=dni;
            strcpy(nombreUsuario,nombre);
            strcpy(nombreDesafio,desafio);
            strcpy(descripcion,desc);
            diaComenzado=fecha.getDia();
            completado=0;

        }
        void Mostrar()
        {
            cout<<"DURAN 1 DIA LOS DESAFIOS!"<<endl;
            cout<<"ID: "<<idDesafio<<endl;
            cout<<"NOMBRE: "<<nombreDesafio<<endl;
            cout<<"DESCRIPCION: "<<descripcion<<endl;
            cout<<"DIA COMENZADO: "<<diaComenzado<<endl;
            cout<<"COMPLETADO: "<<completado<<endl;


        }
};

#endif // DESAFIOUSUARIO_H
