#ifndef MENUUSUARIO_H_INCLUDED
#define MENUUSUARIO_H_INCLUDED

#include "globales.h"
#include "Usuario.h"
#include "ArchivoUsuario.h"
#include "menuHabitos.h"
#include "menuDesafio.h"

void registrar()
{
    system("cls");
    ArchivoUsuario reg("usuarios.dat");
    reg.agregarRegistro();
    system("pause");

}
Usuario iniciarSesion()
{
    system("cls");
    int dni;
    cout<<"INGRESE SU DNI: "<<endl;
    cin>>dni;
    ArchivoUsuario aux("usuarios.dat");
    Usuario reg;
    int cant = aux.contarRegistros();
    for(int i=0;i<=cant;i++)
    {
        reg=aux.leerRegistro(i);
        if(reg.getDNI()==dni)
        {
            return reg;
        }

    }
    cout<<"NO PARECE ESTAR REGISTRADO"<<endl;

}
int menuDentro(Usuario usuario)
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU USUARIO"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<endl;
        cout<<"1.HABITOS"<<endl;
        cout<<"2.DESAFIOS"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"0.SALIR"<<endl;
        cout<<"ELEGIR OPCION"<<endl;
        cout<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            menuHabitos(usuario);
            break;
        case 2:
            menuDesafio(usuario);
            break;
        case 0:
            return 0;
        default:
            cout<<"OPCION INCORRECTA"<<endl;
            break;


        }


    }
}
int menuUsuario()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU USUARIO"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<endl;
        cout<<"1.INICIAR SESION"<<endl;
        cout<<"2.REGISTRARSE"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"0.SALIR"<<endl;
        cout<<"ELEGIR OPCION"<<endl;
        cout<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            {
                Usuario usuario = iniciarSesion();
                menuDentro(usuario);

            }
            break;
        case 2:
            registrar();
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

#endif // MENUUSUARIO_H_INCLUDED
