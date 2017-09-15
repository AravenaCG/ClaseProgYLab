#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "validar.h"


int main()
{


    sProducto arrayProductos[200];
    char bufferInt[40];

    prod_initProducto(arrayProductos,200);



    do
    {
        val_getUnsignedInt(bufferInt,"\n1-Alta\n2-Listar\n3-Modificar\n4-Borrar\n8-Salir\n","\nSolo 1,2 y 8\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:

                prod_cargarProducto (arrayProductos, prod_buscarProductoLibre(arrayProductos,200),200);



                break;

            case 2:
                prod_printProducto(arrayProductos,200);
                break;
            case 3:
                prod_modificarPorId(arrayProductos);
                break;
            case 4:
                prod_BorrarProducto(arrayProductos);
                break;
        }

    }while( atoi(bufferInt) != 8);





    return 0;
}
