#include <iostream>
#include <cstdlib>

using namespace std;

#include "menuUsuario.h"
#include "menuDeveloper.h"

int main()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<endl;
        cout<<"1.USUARIO"<<endl;
        cout<<"2.MODO DEVELOPER"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"0.SALIR"<<endl;
        cout<<"ELEGIR OPCION"<<endl;
        cout<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            menuUsuario();
            break;
        case 2:
            menuDeveloper();
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
