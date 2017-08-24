#include <stdio.h>
#include <stdlib.h>


int dividir(float*, float, float);
int otrasFunciones(float*, float*, float*, float, float);

int main()
{
    float x,y,resultadoDivision,resultadoMultiplicacion,resultadoSuma,ResultadoResta;

    printf("Ingrese el primer numero :\n");
    scanf("%f",&x);
    printf("Ingrese el segundo numero : \n");
    scanf("%f",&y);

    if(dividir(&resultadoDivision,x,y) == -1)
    {
        printf("eRROR");
    }
    else
    {
        printf("La division es : %.2f",resultadoDivision);
    }

     otrasFunciones(&resultadoSuma, &ResultadoResta, &resultadoMultiplicacion, x, y);

    return 0;
}
/** \brief Divide
 *
 * \param resultado resultado de la di....
 * \param
 * \param
 * \return (0) ok - (-1) Error
 *
 */
int dividir(float* resultado,float a, float b)
{
    int retorno = -1;
    if(b != 0)
    {
        *resultado = a/b;
        retorno = 0;
    }
    return retorno;
}



/** \brief el resto de las funciones suma, resta  y multiplicacion
 *
 * \param suma  suma los factores
 * \param resta resta los factores
 * \param multiplicacion multiplica los factores
 * \param
 * \return retorna los resultados de las operaciones
 *
 */

int otrasFunciones(float* resultadoSuma,float* resultadoResta,float* resultadoMultiplicacion, float a, float b){

*resultadoSuma= a+ b;
*resultadoResta= a-b;
*resultadoMultiplicacion=a*b;

printf("el resultado de la suma es: \n %2.f", resultadoSuma);
printf("\n el resultado de la resta es: \n %2.f", resultadoResta);
printf("\n el resultado de la multiplicacion es: \n %2.f ", resultadoMultiplicacion);


return 0;

}
