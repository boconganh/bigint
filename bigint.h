#ifndef _bigint_h_
#define _bigint_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <inttypes.h>


#define BIGINT_SIZE_LIMIT 100000
#define BASE 1000000000000LL
#define XSTR(x) STR(x)
#define STR(x) #x
#define POW_BASE 12
#define STR_POW_BASE XSTR(POW_BASE)

#define PLUS 1
#define MINUS (-1)

typedef long long ll;


typedef struct bigint bigint;

struct bigint {
    int sign;
    int size; // length of digits
    ll digits[BIGINT_SIZE_LIMIT];
};
void bigint_print(bigint *);
void bigint_init(bigint *);
int  bigint_digits_len(bigint *);
void bigint_init_ll(bigint *,ll);
void bigint_add( bigint *, bigint *,bigint *);
void bigint_mul_ll( bigint *, ll,bigint *);
ll bigint_divmod_ll(bigint *,ll,bigint *);



#endif /* _bigint_h_ */