#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../lib/hash_item.h"

//Хеш функция, алгоритм которой изменяет строку в уникальную последовательность 
unsigned long hash_function(char* str,int* len){
    int P=46; //максимальное количество различных символов в строке.
    unsigned long long sum=0;
    for(int i=0;i<*len;i++){
        int ch=(int) str[i];//преобразовываем символ ASCII в int 
        ch*=pow(P,i);// и умножаем на его количество уникальных сиволов в степени позиции символа в строке
        sum+=ch;//прибавляем число к сумме
    }
    return sum;
}