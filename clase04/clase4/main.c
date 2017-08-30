#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main()
{
    int jugar;
    int numeroIngresado;
    int numeroOculto=0;
    char teclaIng;


    teclaIng = 's';

    while (teclaIng == 's')
        {
           numeroOculto = getNumeroAleatorio(1,100,1);

            jugar = 1;

            while (jugar == 1)
                {
                numeroIngresado = getInt("ingrese un numero de 1 a 99 \n");
                if (numeroIngresado < 0 )
                    {
                    jugar = 0 ;
                    }
               else if (numeroIngresado == numeroOculto)

                    {
                    printf("GANASTE \n");
                    jugar = 0;

                    }
                else if (numeroIngresado < numeroOculto)
                    {
                    printf("el numero que ingresaste es chico \n");
                    }
                else if (numeroIngresado > numeroOculto)
                    {
                    printf("el numero ingresado es grande \n");

                    }


                }

        getChar("desea seguir jugando? (s/n) \n");



    }
    return 0;
}
