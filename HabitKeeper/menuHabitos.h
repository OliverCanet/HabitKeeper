#ifndef MENUHABITOS_H_INCLUDED
#define MENUHABITOS_H_INCLUDED

#include "ArchivoHabito.h"
#include "Habito.h"

void nuevoHabito(Usuario usuario)
{
    system("cls");
    ArchivoHabito reg("habitos.dat");
    reg.agregarRegistro(usuario.getDNI());
    system("pause");


}
void todosHabitos(Usuario usuario)
{
    system("cls");
    ArchivoHabito aux("habitos.dat");
    Habito reg(usuario.getDNI());
    cout<<"-------------------------"<<endl;
    cout<<"MES: "<<reg.getMes()<<endl;
    int cant = aux.contarRegistros();
    for(int i=0;i<=cant;i++)
    {
        reg=aux.leerRegistro(i,usuario.getDNI());
        if(reg.getDNI()==usuario.getDNI()&&reg.getEstado()==true)
        {
            reg.Mostrar();
            cout<<"-------------------------"<<endl;
        }
    }




}
void completarHabito(Usuario usuario)
{
    system("cls");

    todosHabitos(usuario);
    ArchivoHabito aux("habitos.dat");
    aux.modificarRegistro(1);


    system("pause");

}
void cancelarCompletacion(Usuario usuario)
{
    system("cls");

    todosHabitos(usuario);
    ArchivoHabito aux("habitos.dat");
    aux.modificarRegistro(0);


    system("pause");
}
void eliminarHabito(Usuario usuario)
{
    system("cls");
    todosHabitos(usuario);
    ArchivoHabito aux("habitos.dat");
    aux.eliminarRegistro();
    system("pause");
}
int menuHabitos(Usuario usuario)
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"BUEN DIA "<<usuario.getNombre()<<endl;
        cout<<"MENU HABITOS"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<endl;
        cout<<"1.NUEVO HABITO"<<endl;
        cout<<"2.TODOS LOS HABITOS"<<endl;
        cout<<"3.COMPLETAR HABITO"<<endl;
        cout<<"4.CANCELAR COMPLETACION DE HABITO"<<endl;
        cout<<"5.ELIMINAR HABITO"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"0.SALIR"<<endl;
        cout<<"ELEGIR OPCION"<<endl;
        cout<<endl;
        cin>>opc;

        switch(opc){
        case 1:
                nuevoHabito(usuario);
            break;
        case 2:
                {
                todosHabitos(usuario);
                system("pause");

                }
            break;
        case 3:
                completarHabito(usuario);
            break;
        case 4:
                cancelarCompletacion(usuario);
            break;
        case 5:
                eliminarHabito(usuario);
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

#endif // MENUHABITOS_H_INCLUDED
