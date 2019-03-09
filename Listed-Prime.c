/**
 * リスト型素数計算プログラム
 * Copyright (C) HyodaKazuaki
*/

#include <stdio.h>
#include <stdlib.h>

struct prime{
    unsigned int value; // 素数
    struct prime* next; // 次の構造体
};

struct prime* cons(unsigned int value, struct prime* list)
{
    struct prime* ret;
    if((ret = (struct prime*)malloc(sizeof(struct prime))) != NULL){
        ret->value = value;
        ret->next = list;
    }
    else{
        printf("\nMemory allocation fault\n");
    }
    
    return ret;
}

int isPrime(unsigned int value, struct prime* top)
{
    struct prime* pos = top;

    for(; pos->next != NULL; pos = pos->next){
        if(value % pos->value == 0){
            return 0;
        }
    }
    
    return 1;
}

struct prime* calcPrime(unsigned int value, struct prime* top)
{
    if(isPrime(value, top)){
        top = cons(value, top);
    }

    return top;
}

int main(void)
{
    struct prime* top;
    struct prime* pos;
    unsigned int size = 0, i = 0, next = 0;

    printf("Please input number what you want calculate primes.\n");
    scanf("%d", &size);

    printf("Calculation in progress...\n");
    printf("0 %%");
    top = cons(3, cons(2, NULL));
    next = top->value + 2;
    for(i = 2; i < size; next += 2){
        if((i * 100 / size) % 10 == 0)
            printf("\r%d %%", (i * 100 / size));

        top = calcPrime(next, top);
        if(next == top->value)
            i += 1;
    }
    printf("\nFinished.\n");
    printf("Result : ");
    printf("%d\n", top->value);

    return 0;
}