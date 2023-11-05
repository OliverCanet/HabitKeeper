#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <ctime>
using namespace std;



class Fecha{
private:
    int dia,mes, anio;
public:
    Fecha(){
        time_t t = time(NULL);
        struct tm fechaSistema = *localtime(&t);
        dia=fechaSistema.tm_mday;
        mes=fechaSistema.tm_mon+1;
        anio=fechaSistema.tm_year+1900;




    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};


#endif // FECHA_H
