#ifndef MENUDEVELOPER_H_INCLUDED
#define MENUDEVELOPER_H_INCLUDED

#include "ArchivoDesafio.h"
#include "ArchivoDesafioUsuario.h"
void todosDesafios();
void crearDesafio();
void eliminarDesafio();

void crearDesafio()
{
    system("cls");
    ArchivoDesafio reg("desafios.dat");
    reg.agregarRegistro();
    system("pause");
}
void eliminarDesafio()
{
    system("cls");
    todosDesafios();
    ArchivoDesafio aux("desafios.dat");
    aux.eliminarRegistro();
    system("pause");
}
void todosDesafios()
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
void dniDesafio()
{
    system("cls");
    todosDesafios();
    ArchivoDesafioUsuario aux("desafiousuarios.dat");
    DesafioUsuario reg;

    int id;
    cout<<"INGRESAR ID DE DESAFIO: "<<endl;
    cin>>id;
    system("cls");
    int cant = aux.contarRegistros();
    for(int i=0;i<cant;i++)
    {
        reg=aux.leerRegistro(i);
        if(reg.getEstado()==true&&reg.getID()==id)
        {
            cout<<i<<". "<<reg.getDNI()<<endl;
            cout<<"-------------------------"<<endl;
        }
    }
    system("pause");

}
int menuDeveloper()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU DEVELOPER"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<endl;
        cout<<"1.CREAR DESAFIO"<<endl;
        cout<<"2.ELIMINAR DESAFIO"<<endl;
        cout<<"3.TODOS LOS DESAFIOS"<<endl;
        cout<<"4.LOS DNI EN UN DESAFIO"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"0.SALIR"<<endl;
        cout<<"ELEGIR OPCION"<<endl;
        cout<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            crearDesafio();
            break;
        case 2:
            eliminarDesafio();
            break;
        case 3:
            {
                todosDesafios();
                system("pause");

            }

            break;
        case 4:
            dniDesafio();
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

#endif // MENUDEVELOPER_H_INCLUDED
