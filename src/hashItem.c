#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../lib/hash_item.h"

//Хеш функция, алгоритм которой изменяет строку в уникальную последовательность 
unsigned long long hashFunction(char* str,int* len){
    const int p = 63;
    const int mod = 1000000007; //
    unsigned long long hash = 0, p_pow = 1;
    for (int i=0; i<*len; ++i)
    {
        hash += ((str[i] - 'A' + 1) * p_pow) % mod; 
        p_pow = (p_pow * p) % mod;
    }
    return hash;
}