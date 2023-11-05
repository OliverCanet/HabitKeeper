#ifndef MENUDESAFIO_H_INCLUDED
#define MENUDESAFIO_H_INCLUDED

#include "ArchivoDesafio.h"
#include "ArchivoDesafioUsuario.h"


void desafiosDisponibles()
{
    system("cls");
    ArchivoDesafio aux("desafios.dat");
    Desafio reg;
    int cant = aux.contarRegistros();
    for(int i=0;i<cant;i++)
    {
        reg=aux.leerRegistro(i);
        if(reg.getEstado()==true)
        {
            reg.Mostrar();
            cout<<"-------------------------"<<endl;
        }
    }

}
void misDesafios(Usuario usuario)
{
    system("cls");
    ArchivoDesafioUsuario aux("desafiousuarios.dat");
    DesafioUsuario reg;
    int cant = aux.contarRegistros();
    for(int i=0;i<cant;i++)
    {
        reg=aux.leerRegistro(i);
        if(reg.getEstado()==true&&reg.getDNI()==usuario.getDNI())
        {
            reg.Mostrar();
            cout<<"-------------------------"<<endl;
        }
    }
}
void anotarseDesafio(Usuario usuario)
{
    system("cls");
    int id;
    ArchivoDesafio reg("desafios.dat");
    ArchivoDesafioUsuario aux("desafiousuarios.dat");
    desafiosDisponibles();
    cout<<"ID DEL DESAFIO A UNIRSE: "<<endl;
    cin>>id;
    aux.agregarRegistro(id,usuario.getDNI(),usuario.getNombre());
    reg.sumarUsuario(id);
    system("pause");

}
void completarDesafio(Usuario usuario)
{
    system("cls");
    int id;
    ArchivoDesafio reg("desafios.dat");
    ArchivoDesafioUsuario aux("desafiousuarios.dat");
    misDesafios(usuario);
    aux.modificarRegistro(1,usuario.getDNI());
    system("pause");

}
int menuDesafio(Usuario usuario)
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"BUEN DIA "<<usuario.getNombre()<<endl;
        cout<<"MENU DESAFIOS"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<endl;
        cout<<"1.TODOS LOS DESAFIOS DISPONIBLES"<<endl;
        cout<<"2.MIS DESAFIOS"<<endl;
        cout<<"3.ANOTARSE A UN DESAFIO"<<endl;
        cout<<"4.COMPLETAR DIA DESAFIO"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"0.SALIR"<<endl;
        cout<<"ELEGIR OPCION"<<endl;
        cout<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            {
            desafiosDisponibles();
            system("pause");
            }
            break;
        case 2:
            {
            misDesafios(usuario);
            system("pause");
            }
            break;
        case 3:
            anotarseDesafio(usuario);
            break;
        case 4:
            completarDesafio(usuario);
            break;
        case 5:

            break;
        case 0:
            return 0;
        default:
            cout<<"OPCION INCORRECTA"<<endl;
            break;


        }


    }

    return 0;
}

#endif // MENUDESAFIO_H_INCLUDED
