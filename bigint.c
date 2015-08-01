#include "bigint.h"


void bigint_print(bigint *a){
    assert(a);
    if(!a->size){
        puts("0");
        return;
    }
    if(a->sign<0){
        printf("-");
    }
    int i=a->size-1;
    printf("%lld",a->digits[i]);
    while(--i>=0){
        printf("%0"STR_POW_BASE"lld",a->digits[i]);
    }
    printf("\n");
}
int bigint_digits_len(bigint *a){
    assert(a);
    char temp[25];
    return sprintf(temp,"%lld",a->digits[a->size-1])+(a->size-1)*POW_BASE;
}
void bigint_init(bigint *a){
    assert(a);
    a->sign=PLUS;
    a->size=0;
}
void bigint_init_ll(bigint *a,ll x){
    assert(a);
    if(x<0){
        x=-x;
        a->sign=MINUS;
    }else{
        a->sign=PLUS;
    }
    a->size=0;
    while(x){
        a->digits[a->size++]=x%BASE;
        x/=BASE;
    }
}

static void _bigint_init_str(bigint *a, char *str){
    // init string of digits

    int len=strlen(str);
    int cnt=0;
    a->size=0;
    ll value=0;
    ll pw=1;
    while(--len>=0){
        cnt++;
        value+=pw*(str[len]-'0');
        if(len==0|| cnt==POW_BASE){
            a->digits[a->size++]=value;
            cnt=0;
            value=0;
            pw=1;
        }else{
            pw*=10;
        }
    }
   
}

void bigint_init_str(bigint *a,char *str){
    
    assert(a);
    if(str[0]=='-'){
        _bigint_init_str(a,str+1);
        a->sign=-1;
    }else{
        _bigint_init_str(a,str);
    }
}


void bigint_mul_ll(bigint *a,ll x,bigint *c){
    assert(a);
    assert(c);
    
    if(x>=0){
        c->sign=a->sign;
    }else{
        c->sign=-a->sign;
        x=-x;
    }
    int i;
    ll memo=0;
    for(i=0;i<a->size;i++){
        memo+=a->digits[i]*x;
        c->digits[i]=memo%BASE;
        memo/=BASE;
    }
    while(memo){
        c->digits[i++]=memo%BASE;
        memo/=BASE;
    }
    c->size=i;
    
}

ll bigint_divmod_ll(bigint *a,ll x,bigint *c){
    // for a->sign >=0
    assert(a);
    assert(c);
    int i;
    ll rem=0;
    for(i=a->size-1;i>=0;--i){
        ll temp=a->digits[i]+rem*BASE;
        c->digits[i]=temp/x;
        rem=temp%x;
    }
    c->size=a->size;
    c->sign=PLUS;
    while(c->size>0 && c->digits[c->size-1]==0){
        --c->size;
    }
    return rem;
}