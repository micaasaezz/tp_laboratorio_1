#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    int cantMovies=0;
    //EMovie* pelicula;
    EMovie* movies;
    int cargoMovie=0;
    FILE* archivoMovies;
    char auxtitulo[20];
    int flagIngreso=0;
    int auxInt, i;


    archivoMovies = fopen("peliculas.dat","rb");
    if(archivoMovies == NULL)
    {
        archivoMovies = fopen("peliculas.dat", "wb");
    }

    if(archivoMovies!=NULL)
    {
        movies = newMovie();
        if(movies!=NULL)
        {
            while(!feof(archivoMovies))
            {
                fread(movies, sizeof(EMovie), 1, archivoMovies);
            }

        }
    }

   // fclose(archivoMovies);



    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                movies = newMovie();
                cargoMovie = cargarDatosMovie(movies);
                if(cargoMovie==0)
                {
                    break;
                }
                if(cantMovies == 0)
                {
                    cargoMovie = agregarPelicula(movies, archivoMovies);
                }
                else
                {
                    cargoMovie = agregarPelicula((movies+cantMovies), archivoMovies);
                }

                if(cargoMovie==1)
                {
                    printf("Pelicula cargada correctamente.\n");
                    cantMovies++;
                    movies = (EMovie*) realloc(movies,sizeof(EMovie)*cantMovies);
                    flagIngreso = 1;
                }
                else
                {
                    printf("No se pudo cargar la pelicula!\n");
                }

                    break;

            case 2:
                if(flagIngreso == 0)
                {
                    printf("\nNo se ingresaron peliculas!\n");
                    break;
                }
                for(i=0; i<cantMovies; i++)
                {
                    printMovie((movies+i));
                }
                printf("\nEscriba el nombre de pelicula para borrar:");
                fflush(stdin);
                gets(auxtitulo);
                for(i=0; i<cantMovies; i++)
                {
                    if( strcmp(auxtitulo, (movies+i)->titulo ) == 0 )
                    {
                        auxInt = borrarPelicula(*(movies+i), archivoMovies);
                        if(auxInt == 1)
                        {
                             cantMovies--;
                             printf("\nPelicula borrada!\n");
                        }

                        break;
                    }
                }

                break;

            case 3:
                if(flagIngreso == 0)
                {
                    printf("\nNo se ingresaron peliculas!\n");
                    break;
                }
                 for(i=0; i<cantMovies; i++)
                {
                    printMovie((movies+i));
                }
                printf("\Escriba el nombre de pelicula para modificar:");
                fflush(stdin);
                gets(auxtitulo);
                for(i=0; i<cantMovies; i++)
                {
                    if( strcmp(auxtitulo, (movies+i)->titulo ) == 0 )
                    {
                        auxInt = modifyMovie(movies+i);

                        break;
                    }
                }
               break;

            case 4:
                if(flagIngreso == 0)
                {
                    printf("\nNo se ingresaron peliculas!\n");
                    break;
                }
                printf("Ingrese el nombre para el archivo:");
                fflush(stdin);
                gets(auxtitulo);

                generarPagina(movies, auxtitulo);

               break;

            case 5:
                seguir = 'n';
                break;

            default:
                printf("Error, reingrese opcion!");
                break;

        }


        system("pause");
        system("cls");

    }

    return 0;
}
