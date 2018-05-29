#include <stdio.h>
#include <stdlib.h>

#include "Dato.h"


int main()
{
    eDato* d;
    d=func_Malloc(d,1800,"hola");



    printf("%d--%s", eDato_get_a(d),eDato_get_b(d));

    return 0;
}

