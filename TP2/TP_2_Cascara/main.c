#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[CANT];
    int espLibre;
    int flagEmpezarEstados=0;
    int contMenos18, cont19a35, contMas35;
    int i;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if(flagEmpezarEstados==0)
            {
                iniciarEstados(lista, CANT);
                flagEmpezarEstados = 1;
            }

            espLibre = obtenerEspacioLibre(lista, CANT);

            if(espLibre == -1)
            {
                printf("\nNo hay m%cs espacio libre!\n", 160);
                break;
            }

            cargarPersona(lista, CANT, espLibre);

            break;

        case 2:
            borrarPersona(lista, CANT);
            break;

        case 3:
            listarPorNombre(lista, CANT);
            break;

        case 4:
            contMenos18=0;
            cont19a35=0;
            contMas35=0;

            for(i=0; i<CANT; i++)
            {
                if(lista[i].estado==1)
                {
                    if(lista[i].edad < 18)
                    {
                        contMenos18++;
                    }
                    else if(lista[i].edad < 36)
                    {
                        cont19a35++;
                    }
                    else
                    {
                        contMas35++;
                    }
                }

            }
            graficar(contMenos18, cont19a35, contMas35);
            break;

        case 5:
            seguir = 'n';
            break;

        default:
            printf("\n\nIngrese una opción v%clida!\n",160);
            break;

        }
        system("pause");
        system("cls");

    }


    return 0;
}
