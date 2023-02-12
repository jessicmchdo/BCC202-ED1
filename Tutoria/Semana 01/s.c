#include <stdio.h>


void printa(int *v, int n){
    
    if(n > 1){
        printf("%d", v[n-1]);
    }
    printa(v, n-1);
}

int main(){
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    
    printa(v, 10);
    return 0;

}