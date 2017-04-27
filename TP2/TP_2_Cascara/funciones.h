#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    char nombre[50];
    int edad;
    int dni;
    int estado;

} EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tam  tama�o de el array epersona
 * @return el primer indice disponible y -1 si no hay lugares libres
 */
int obtenerEspacioLibre(EPersona lista[], int tam);






/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param int  tama�o del array persona
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int tam);






/** \brief carga una estructura de personas con todos sus datos
 *
 * \param lista[] estructura de personas a cargar
 * \param tamLista  tama�o del array de personas
 * \param posicion  posicion libre para guardar los datos de la persona en la estructura
 *
 */
void cargarPersona(EPersona lista[], int tamLista, int posicion);


/** \brief borra los datos de una estructura de personas
 *
 * \param lista[] estructura de personas de la que se va a borrar
 * \param tamLista tama�o del array de personas
 *
 */
void borrarPersona(EPersona lista[], int tamLista);


/** \brief lista a todas las personas alfabeticamente por nombre
 *
 * \param lista[] estructura de personas para mostrar
 * \param tamLista tama�o del array de personas
 *
 */
void listarPorNombre(EPersona lista[], int tamLista);


/** \brief muestra un gr�fico de barras en el que se analizan las edades
 *
 * \param menos18 int  contador de personas menores a 18 a�os
 * \param cont19a35 int   contador de personas de entre 19 y 35 a�os
 * \param mas35 int  cant de personas con m�s de 35 a�os
 * \return void
 *
 */
void graficar(int menos18, int cont19a35, int mas35);


/** \brief inicia a todos los estados de las personas en 0
 *
 * \param lista[] estructura de personas a inicializar
 * \param tamLista tama�o del array de personas
 *
 */
void iniciarEstados(EPersona lista[], int tamLista);


#endif // FUNCIONES_H_INCLUDED

