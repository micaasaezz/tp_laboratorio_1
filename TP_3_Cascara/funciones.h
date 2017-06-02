#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[51];
    int puntaje;
    char linkImagen[50];

}EMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param FILE* archivo donde se va a guardar la pelicula
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* movie, FILE* archivo);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param FILE* archivo donde se va a borrar la pelicula
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie, FILE* archivo);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* movie, char nombre[]);








/** \brief resera espacio en memoria para una estructura de movie
 *
 * \return EMovie*  puntero a la estructura de pelicula
 *
 */
EMovie* newMovie();


/** \brief carga los datos de una pelicula
 *
 * \param EMovie* puntero a la estructura a cargar
 * \return int 1 si se pudo cargar, 0 si no se pudo
 *
 */
int cargarDatosMovie(EMovie*);


/** \brief imprime por consola los datos de una estructura de pelicula
 *
 * \param EMovie* estructura a mostrar
 * \return void
 *
 */
void printMovie(EMovie*);


/** \brief modifica datos de una pelicula
 *
 * \param movie EMovie* estructura a modificar
 * \return int 1 si se pudo modificar, 0 si no
 *
 */
int modifyMovie(EMovie* movie);

#endif // FUNCIONES_H_INCLUDED



