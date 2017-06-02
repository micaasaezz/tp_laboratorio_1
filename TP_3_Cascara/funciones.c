#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

EMovie* newMovie()
{
    EMovie* movie = NULL;
    movie = malloc(sizeof(EMovie));
    return movie;
}


int cargarDatosMovie(EMovie* movie)
{
    int pudo;
    char opcion;
    EMovie* auxiliarMovie;
    auxiliarMovie = newMovie();

    printf("Ingrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(auxiliarMovie->titulo);

    printf("Ingrese el genero de la pelicula: ");
    fflush(stdin);
    gets(auxiliarMovie->genero);

    printf("Ingrese la duracion de la pelicula en minutos: ");
    scanf("%d", &auxiliarMovie->duracion);

    printf("Ingrese una descripcion para la pelicula (menos de 50 caracteres): ");
    fflush(stdin);
    gets(auxiliarMovie->descripcion);
    while(strlen(auxiliarMovie->descripcion) > 50)
    {
        printf("La descripcion debe ser de menos de 50 caracteres: ");
        fflush(stdin);
        gets(auxiliarMovie->descripcion);

    }

    printf("Ingrese el puntaje de la pelicula (del 1 al 100): ");
    scanf("%d", &auxiliarMovie->puntaje);
    while(auxiliarMovie->puntaje > 100 || auxiliarMovie->puntaje < 1)
    {
        printf("El putaje de la pelicula debe estar entre 1 y 100: ");
        scanf("%d", &auxiliarMovie->puntaje);
    }

    printf("Ingrese el link a la imagen de la pelicula: ");
    fflush(stdin);
    gets(auxiliarMovie->linkImagen);
    while(strlen(auxiliarMovie->linkImagen) > 50)
    {
        printf("El link a la imagen de la pelicula debe ser menor a 50 caracteres: ");
        fflush(stdin);
        gets(auxiliarMovie->linkImagen);
    }

    printf("\nEsta seguro que desea guardar esta pelicula? (s/n)\n");
    printMovie(auxiliarMovie);
    scanf("%c", &opcion);
    if(opcion == 's')
    {
        *movie = *auxiliarMovie;
        free(auxiliarMovie);
        pudo = 1;
    }
    else
    {
        printf("Cancelado!\n");
        pudo = 0;
    }

    return pudo;
}

void printMovie(EMovie* movie)
{
    printf("TITULO: %s\nGENERO: %s\nDURACION: %d\nDESCRIPCION: %s\nPUNTAJE: %d\nLINK DE IMAGEN: %s\n",movie->titulo,movie->genero,movie->duracion,movie->descripcion, movie->puntaje, movie->linkImagen);


}

int agregarPelicula(EMovie* movie, FILE* archivo)
{
    int pudo=0;

    archivo = fopen("peliculas.dat", "wb");

    if(archivo!=NULL)
    {
        pudo = fwrite(movie, sizeof(EMovie), 1, archivo);
        if(pudo==1)
        {
            pudo = 1;
        }
        else
        {
            pudo = 0;
        }
    }


    fclose(archivo);


    return pudo;
}



int borrarPelicula(EMovie movie, FILE* archivo)
{
    int pudo=0;
    int i;
    EMovie* auxMov;

    archivo = fopen("peliculas.dat", "wb");

    if(archivo!=NULL)
    {
        pudo = fread(&auxMov, sizeof(EMovie), 1, archivo);
        if(pudo!=1)
        {
            for(i=0; i<sizeof(auxMov); i++)
            {
                *(&auxMov+i) = *(&auxMov+i+1);
            }

        }

        pudo = fwrite(&auxMov, sizeof(EMovie), 1, archivo);
        if(pudo<1)
        {
            pudo = 0;
        }
        else
        {
            pudo = 1;
        }
    }


    fclose(archivo);
   free(auxMov);


    return pudo;
}




int modifyMovie(EMovie* movie)
{
    int pudo=0;
    int opcion;
    char newTitulo[20];
    char newGenero[20];
    int newDurac;
    char newDescrp[51];
    int newPunt;
    char newLink[50];
    EMovie* newMov = newMovie();
    char rta;

    newMov = movie;

    printf("Elija que desea modificar:");
    printf("1- titulo.\n2- genero.\n3- duracion.\n4- descripcion.\n5- puntaje.\n6- link de imagen.\n");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            printf("Ingrese el nuevo titulo:");
            fflush(stdin);
            gets(newTitulo);
            strcpy(newMov->titulo, newTitulo);
            printf("\nEsta seguro? (s/n)\n");
            printMovie(newMov);
            scanf("%c", &rta);
            if(rta == 's')
            {
                movie = newMov;
                printf("\nCambio realizado!\n");
                pudo = 1;
            }
            else
            {
                printf("\nCambio cancelado!\n");
                pudo = 0;
            }
            break;
        case 2:
            printf("Ingrese el nuevo genero:");
            fflush(stdin);
            gets(newGenero);
            strcpy(newMov->genero, newGenero);
            printf("\nEsta seguro? (s/n)\n");
            printMovie(newMov);
            scanf("%c", &rta);
            if(rta == 's')
            {
                movie = newMov;
                printf("\nCambio realizado!\n");
                pudo = 1;
            }
            else
            {
                printf("\nCambio cancelado!\n");
                pudo = 0;
            }
            break;
        case 3:
            printf("Ingrese la nueva duracion:");
            scanf("%d", &newDurac);
            newMov->duracion = newDurac;
            printf("\nEsta seguro? (s/n)\n");
            printMovie(newMov);
            scanf("%c", &rta);
            if(rta == 's')
            {
                movie = newMov;
                printf("\nCambio realizado!\n");
                pudo = 1;
            }
            else
            {
                printf("\nCambio cancelado!\n");
                pudo = 0;
            }
            break;
        case 4:
            printf("Ingrese la nueva descripcion:");
            fflush(stdin);
            gets(newDescrp);
            while(strlen(newDescrp) > 50)
            {
                printf("\nLa descripcion debe ser de menos de 50 caracteres: ");
                fflush(stdin);
                gets(newDescrp);

            }
            strcpy(newMov->descripcion, newDescrp);
            printf("\nEsta seguro? (s/n)\n");
            printMovie(newMov);
            scanf("%c", &rta);
            if(rta == 's')
            {
                movie = newMov;
                printf("\nCambio realizado!\n");
                pudo = 1;
            }
            else
            {
                printf("\nCambio cancelado!\n");
                pudo = 0;
            }
            break;
        case 5:
            printf("Ingrese la nueva puntuacion:");
            scanf("%d", &newPunt);
            while(newPunt > 100 || newPunt < 1)
            {
                printf("\nEl putaje de la pelicula debe estar entre 1 y 100: ");
                scanf("%d", &newPunt);
            }
            newMov->puntaje = newPunt;
            printf("\nEsta seguro? (s/n)\n");
            printMovie(newMov);
            scanf("%c", &rta);
            if(rta == 's')
            {
                movie = newMov;
                printf("\nCambio realizado!\n");
                pudo = 1;
            }
            else
            {
                printf("\nCambio cancelado!\n");
                pudo = 0;
            }
            break;
        case 6:
            printf("Ingrese el nuevo link:");
            fflush(stdin);
            gets(newLink);
            while(strlen(newLink) > 50)
            {
                printf("\nEl link a la imagen de la pelicula debe ser menor a 50 caracteres: ");
                fflush(stdin);
                gets(newLink);
            }
            strcpy(newMov->linkImagen, newLink);
            printf("\nEsta seguro? (s/n)\n");
            printMovie(newMov);
            scanf("%c", &rta);
            if(rta == 's')
            {
                movie = newMov;
                printf("\nCambio realizado!\n");
                pudo = 1;
            }
            else
            {
                printf("\nCambio cancelado!\n");
                pudo = 0;
            }
            break;
        default:
            printf("\nNo se pudo realizar la modificaion.\n");
            pudo = 0;
            break;
    }


    return pudo;
}



void generarPagina(EMovie* movie, char nombre[])
{
    FILE* html;

    char codigoPrincipio[] = {"<!DOCTYPE html>\
                        <!-- Template by Quackit.com -->\
                        <html lang='en'>\
                        <head>\
                            <meta charset='utf-8'>\
                            <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
                            <meta name='viewport' content='width=device-width, initial-scale=1'>\
                            <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\
                            <title>Lista peliculas</title>\
                            <!-- Bootstrap Core CSS -->\
                            <link href='css/bootstrap.min.css' rel='stylesheet'>\
                            <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\
                            <link href='css/custom.css' rel='stylesheet'>\
                            <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\
                            <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\
                            <!--[if lt IE 9]>\
                                <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\
                                <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\
                            <![endif]-->\
                        </head>\
                        <body>\
                            <div class='container'>\
                                <div class='row'>"};



    char codigoFinal[] = {"</div>\
                            <!-- /.row -->\
                        </div>\
                        <!-- /.container -->\
                        <!-- jQuery -->\
                        <script src='js/jquery-1.11.3.min.js'></script>\
                        <!-- Bootstrap Core JavaScript -->\
                        <script src='js/bootstrap.min.js'></script>\
                        <!-- IE10 viewport bug workaround -->\
                        <script src='js/ie10-viewport-bug-workaround.js'></script>\
                        <!-- Placeholder Images -->\
                        <script src='js/holder.min.js'></script>\
                    </body>\
                    </html>"};


    nombre = strcat(nombre, ".html");
    html = fopen(nombre,"w");

    if(html != NULL)
    {
        fwrite(codigoPrincipio, sizeof(EMovie), 1, html);
        fprintf(html, "<article class='col-md-4 article-intro'>\
                <a href='#'>\
                    <img class='img-responsive img-rounded' src='%s' alt=''>\
                </a>\
                <h3>\
                    <a href='#'>%s</a>\
                </h3>\
				<ul>\
					<li>Género:%s</li>\
					<li>Puntaje:%d</li>\
					<li>Duración:%d</li>\
				</ul>\
                <p>%s</p>\
            </article>", movie->linkImagen, movie->titulo, movie->genero, movie->puntaje, movie->duracion, movie->descripcion);
         fwrite(codigoFinal, sizeof(EMovie), 1, html);


    }

    fclose(html);

}










