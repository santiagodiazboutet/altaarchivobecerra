#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char Pais[10];
    int id;
    char nombre[10];
}eMoneda;

void Moneda_MostrarListado(eMoneda *Lista,int limite);
void Moneda_Alta(eMoneda *Lista,int limite);
int Moneda_BuscarporId(eMoneda *lista,int limite,int id);
void Moneda_Baja(eMoneda *Lista,int limite);
void Moneda_AltaArchivo(eMoneda *lista,int limite);

int main()
{
    eMoneda lista[3];//={{"Argentina",1,"Peso"},{"Brasil",2,"Real"},{"USA",3,"Dolar"}};

    eMoneda* puntLista;

    puntLista=lista;
    puntLista->id=5;
    Moneda_Alta(puntLista,3);
    Moneda_MostrarListado(puntLista,3);
    Moneda_Baja(puntLista,3);
    Moneda_MostrarListado(puntLista,3);
    Moneda_AltaArchivo(puntLista,3);

    return 0;
}


void Moneda_MostrarListado(eMoneda *lista,int limite)
{   int i;
    if(lista!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            printf("pais %s -- nombre %s -- id %d\n",(lista+i)->Pais,(lista+i)->nombre,(lista+i)->id);
        }
    }

}
void Moneda_Alta(eMoneda *lista,int limite)
{   int i;
    if(lista!=NULL && limite>0)
    {   for(i=0;i<limite;i++)
        {
            fflush(stdin);
            printf("Por favor ingrese el pais: \n");
            gets((lista+i)->Pais);
            printf("Por favor ingrese el nombre de la moneda: \n");
            gets((lista+i)->nombre);
            printf("Por favor ingrese el id: \n");
            scanf("%d",&((lista+i)->id));
        }
    }
}

int Moneda_BuscarporId(eMoneda *lista,int limite,int id)
{   int i;

    int indice;
    if(lista!=NULL && limite>0)
    {   for(i=0;i<limite-1;i++)
        {
           if((lista+i)->id==id)
           {
               indice=id;
           }
        }
    }
    return indice;
}


void Moneda_Baja(eMoneda *lista,int limite)
{   int i;
    char seguir="s";
    int id;
    int indice;
    if(lista!=NULL && limite>0)
    {
            printf("Ingrese el id del elemento que desea dar de baja:");
            scanf("%d",&id);
            indice=Moneda_BuscarporId(lista,limite,id);
            strcpy((lista+indice)->nombre," ");
            strcpy((lista+indice)->Pais," ");
            (lista+indice)->id=0;
            printf("Desea seguir: S/N");
            seguir=getche();

    }
}


void Moneda_AltaArchivo(eMoneda *lista,int limite)
{   int i;
    char seguir="s";
    int id;
    int indice;
    FILE* fp;
    fp = fopen("C:\\TEST\\sboutet\\ALta\\fichero.txt","w");

    if(lista!=NULL && limite>0)
    {
            for(i=0;i<limite;i++)
            {
                fprintf(fp,"Nombre: %s - Pais: %s - Id: %d\n",(lista+i)->nombre,(lista+i)->Pais,(lista+i)->id);
            }
        fclose(fp);
    }
}


