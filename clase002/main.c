#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS_INGRESADOS 5


int main()
{


    float numero;
    //int i;
    float maximo;
    float minimo;
    float acumulador;
    char respuesta;
    int contadorIteraciones=0;


    do{
    //for(i=0; i < CANTIDAD_NUMEROS_INGRESADOS ;i++){

        printf("ingrese un numero\n");
        scanf("%f",&numero);


        if (contadorIteraciones==0){
            maximo=numero;
            minimo=numero;
        }
            else{
                if(numero>maximo){
                    maximo=numero;
                     }

            if(numero<minimo){
                minimo=numero;
                     }
        }


     acumulador += numero;

    contadorIteraciones++;
    printf("desea continuar ingresando numeros? s/n  \n");
    fflush(stdin);
    scanf("%c",&respuesta);
    }while(respuesta == 's' );






  printf("el maximo es :%.2f\n",maximo);
  printf("el minimo es: %.2f\n", minimo);
  printf("el promedio es: %.2f \n", acumulador /contadorIteraciones);

return 0;

}

