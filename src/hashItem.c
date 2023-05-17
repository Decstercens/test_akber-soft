#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../lib/hash_item.h"

//функция создания структуры хеш элемент
hash_item* create_item(unsigned long long key, char* value) {
    hash_item* item = (hash_item*) malloc (sizeof(hash_item));//выделяем память для 
    item->key = malloc (sizeof(unsigned long long));
    item->value = (char*) malloc (strlen(value) + 1);
    item->key=key;
    strcpy(item->value, value);
    return item;
}

//Хеш функция, алгоритм которой изменяет строку в уникальную последовательность 
unsigned long hash_function(char* str) {
    int P=79; //максимальное количество различных символов в строке.
    unsigned long long sum=0;
    for(int i=0;i<sizeof(str);i++){
        int ch=(int) str[i];//преобразовываем символ ASCII в int 
        ch*=pow(P,i);// и умножаем на его количество уникальных сиволов в степени позиции символа в строке
        sum+=ch;//прибавляем число к сумме
    }
    return sum;
}
