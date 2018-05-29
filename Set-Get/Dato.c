#include <stdio.h>
#include <stdlib.h>
#include "Dato.h"

int eDato_set_a(eDato* dato, int valor)
{
    int ret = 0;
    if(dato!=NULL && valor!=NULL)
    {
        dato->a = valor;
        ret = 1;
    }

    return ret;
}

int eDato_set_b(eDato* dato, char* valor)
{
    int ret = 0;
    if(dato!=NULL && valor!=NULL)
    {
        strcpy(dato->b , valor);
        ret = 1;
    }

    return ret;
}

int eDato_get_a(eDato* dato)
{
    int valor = -1;

    if(dato!=NULL)
    {
        valor = dato->a;
    }

    return valor;
}

char* eDato_get_b(eDato* dato)
{
    char* valor;
    if(dato!=NULL)
    {
       valor=dato->b;
    }

    return valor;
}

eDato* func_Malloc (eDato* d, int numero, char caracter[50])
{
    eDato* retorno;

    retorno=(eDato*)malloc(sizeof(d));
    if(retorno!=NULL)
    {
    eDato_set_a(retorno,numero);

    eDato_set_b(retorno,caracter);
    }
    return retorno;
}










