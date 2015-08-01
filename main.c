#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigint.h"

typedef long long ll;


int main(){
    bigint a;
    bigint_init_str(&a,"1");
    ll i;
    for(i=1;i<=10000;i++){
        bigint_mul_ll(&a,i,&a);
    }
    //bigint_print(&a);
    
    printf("%d\n",bigint_digits_len(&a));
    
    return 0;
}
