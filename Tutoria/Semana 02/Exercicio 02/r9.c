#include "r9.h"
#include <stdio.h>

int soma_r9(int n){

    if (n / 10 > 0)
    {
        int aux = n % 10;
        return aux + soma_r9(n/10);
    }
    else {
        return n;
    }  
    

}