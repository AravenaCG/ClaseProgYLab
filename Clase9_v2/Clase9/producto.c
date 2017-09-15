#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "validar.h"

int prod_cargarProducto (sProducto* arrayProducto, int index, int len)
{
    int id;
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];

    if(arrayProducto != NULL && index >= 0 && index <len)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                id= prod_GenerarID(arrayProducto,len);
                if(id != -1)
                    {
                        strncpy(arrayProducto[index].nombre,bNombre,51);
                        arrayProducto[index].precio = atof(bPrecio);
                        arrayProducto[index].estado = PRODUCTO_OCUPADO;
                        arrayProducto[index].iDProducto = id;
                retorno=0;
                    }
            }
        }

    }
    return retorno;
}

int prod_initProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayProducto[i].estado = PRODUCTO_LIBRE;
        }

    }
    return retorno;
}

int prod_printProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                printf("\n Descripcion: %d -\n Nombre:%s -\n Precio: %.2f - \n",arrayProducto[i].iDProducto,arrayProducto[i].nombre,arrayProducto[i].precio);
            }
        }

    }
    return retorno;
}


int prod_buscarProductoLibre (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

int prod_GenerarID(sProducto* arrayProducto, int longitud)
{

    int i;
    int ultimoId=0;

    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if (arrayProducto[i].iDProducto > ultimoId)
                {
                        ultimoId= arrayProducto[i].iDProducto;

                }

            }
        }

    }
    return ultimoId+1;
}


static int buscarIndicePorId(sProducto* arrayProducto, int longitud, int id)
{
    int i;
    int idIngresado = id;
    int retorno=0;


    if(arrayProducto != NULL && longitud > 0 && idIngresado > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if (arrayProducto[i].iDProducto == idIngresado)
                {
                    retorno= i;
                    break;

                }

            }
        }

    }
    return retorno;



}

int prod_ModificarProducto (sProducto* arrayProducto, int index)
{

    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];



    if(arrayProducto != NULL && index >= 0 )
    {


        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                strncpy(arrayProducto[index].nombre,bNombre,51);
                arrayProducto[index].precio = atof(bPrecio);

                retorno=0;

            }
        }

    }
    return retorno;
}


int prod_modificarPorId (sProducto* arrayProducto)
{
    int id ;
    int indice;
    val_getInt(&id,"ingreseID","error",3);
    //printf("%d \n ", id);
    indice = buscarIndicePorId(arrayProducto,200,id);
    //printf("%d \n ", indice);
    prod_ModificarProducto(arrayProducto,indice);

    return 0 ;

}

int prod_BorrarProducto (sProducto* arrayProducto)
{
    int id ;
    int indice;
    val_getInt(&id,"ingreseID","error",3);

    indice = buscarIndicePorId(arrayProducto,200,id);



        if(arrayProducto[indice].estado == PRODUCTO_OCUPADO )
            {
                arrayProducto[indice].estado = PRODUCTO_LIBRE;

                printf("producto borrado!!!");

            }



    return 0;

}
