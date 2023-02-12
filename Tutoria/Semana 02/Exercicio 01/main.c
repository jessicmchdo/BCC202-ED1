#include <stdio.h>
#include "f91.h"

int main (){
    int n;

    while(scanf("%d", &n), n){
        printf("f91(%d) = %d\n", n, f91(n));
    }

    return 0;
}