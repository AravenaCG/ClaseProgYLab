#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/**
* \brief solicita un numero entero y lo devuelve
* \param mensaje es el mensaje que se muestra
* \return El numero entero ingresado por el usuario
*
*/

int getInt(char mensaje[]
{
int aux;
printf("%s",mensaje);
scanf("%d",&aux);
return aux;



}


/**
* \brief solicita un char y lo devuelve
* \param mensaje es el mensaje que se muestra
* \return El char ingresado por el usuario
*
*/

char getChar(char mensaje[])
{
float aux;
printf("%s",mensaje);
fflush(stdin);
scanf("%c",&aux);
return aux;



}


/**
* \brief solicita un numero con decimales y lo devuelve
* \param mensaje es el mensaje que se muestra
* \return El numero con decimales ingresado por el usuario
*
*/

int getFloat(char mensaje[])
{
float aux;
printf("%s",mensaje);
scanf("%f",&aux);
return aux;



}

/** \brief genera un numero aleatorio entre un rango elegido
 *
 * \param desde es el origen
 * \param hasta es el final del rango
 * \param iniciar es para generarlo
 * \return un numero aleatorio
 *
 */


char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if (iniciar)
    {
       srand(time(NULL));
        return desde + (rand() % (hasta + 1 - desde));
    }


}

