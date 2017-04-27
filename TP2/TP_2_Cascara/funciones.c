#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int i;
    int auxFlag=0;
    int respuesta;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 0)
        {
            respuesta = i;
            auxFlag = 1;
            break;
        }
    }

    if(auxFlag==0)
    {
        respuesta = -1;
    }

    return respuesta;
}

void cargarPersona(EPersona lista[], int tamLista, int posicion)
{
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(lista[posicion].nombre);

    printf("\nIngrese edad: ");
    scanf("%d", &lista[posicion].edad);

    printf("\nIngrese dni: ");
    scanf("%d", &lista[posicion].dni);

    lista[posicion].estado = 1;

}


int buscarPorDni(EPersona lista[], int dni, int tam)
{
    int  i, indicedni;

    for(i=0; i<tam; i++)
    {
        if(lista[i].dni == dni && lista[i].estado == 1)
        {
            indicedni = i;
            break;
        }
    }

    return indicedni;
}

void borrarPersona(EPersona lista[], int tamLista)
{
    int paraBorrar, posic;
    int flagAux=0;
    char opcion;
    printf("\nIngrese el dni de la persona que desea borrar: ");
    scanf("%d", &paraBorrar);

    posic = buscarPorDni(lista, paraBorrar, tamLista);


    printf("Esta seguro que desea borrar esta persona? (s/n)\n%d - %s", lista[posic].dni, lista[posic].nombre);
    scanf("%s", &opcion);

    if(opcion=='s')
    {
        lista[posic].estado = 0;
        printf("\nBorrado con %cxito.\n", 130);
        flagAux = 1;
    }
    else
    {
        printf("\nOperacion cancelada!\n");
        flagAux = 1;

    }


    if(flagAux == 0)
    {
        printf("\nNo se encontr%c el dni solicitado!\n", 162);
    }
}


void listarPorNombre(EPersona lista[], int tamLista)
{
    int i, j;
    EPersona aux;

    for(i=0; i<tamLista-1; i++)
    {
        for(j=i+1; j<tamLista; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }

    }

    printf("\nNombre\tEdad\tDNI\n");

    for(i=0; i<tamLista; i++)
    {
        if(lista[i].estado==1)
        {
            printf("%s\t%d\t%d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }


}


void graficar(int menos18, int cont19a35, int mas35)
{


    int i, j;
    int mayor=0;
    int filas[3] = {menos18, cont19a35, mas35};

    for(i=0; i<3; i++)
    {
        if(filas[i] > mayor)
        {
            mayor = filas[i];
        }

    }



    for(i=mayor; i>0; i--)
    {
        printf("%d",i);

        for(j=0; j<3; j++)
        {
            if(filas[j] >= i)
            {
                printf("\t*");
            }
            else
            {
                printf("\t ");
            }

        }

        printf("\n");
    }
    printf("\t<18\t19-35\t>35\n");

}


void iniciarEstados(EPersona lista[], int tamLista)
{
    int i;

    for(i=0; i<tamLista; i++)
    {
        lista[i].estado = 0;
    }
}




