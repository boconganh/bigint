# bigint
Bigint algorithm 

####10000!
```c
/**
     * 
     *  10000! 
    ll i;
    for(i=1;i<=10000;i++){
        bigint_mul_ll(&a,i,&a);
    }
    */
    //bigint_print(&a);
```

####convert base
```c
/**
     * 
     *    convert dec ->hex
     * 
     */
     bigint_init_str(&a,"12313213123213131231");
     char output[100];
     int len=0;
     while(!bigint_is_zero(&a)){
         ll rem=bigint_divmod_ll(&a,16,&a);
         output[len++]="0123456789ABCDEF"[rem];
    }
     
    // puts reversed output
    while(--len>=0){
        putchar(output[len]);
    }
```
