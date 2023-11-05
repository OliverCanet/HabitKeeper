#ifndef GLOBALES_H_INCLUDED
#define GLOBALES_H_INCLUDED

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
void cargarCadena2(char *pal,char *pal2, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=pal2[2];
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

#endif // GLOBALES_H_INCLUDED
