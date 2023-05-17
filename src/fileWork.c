#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/hash_item.h"
#include "../lib/file_work.h"

//функция проверки хеша на наличие в файле
int findStr(char* file,hash_item* hi){
    FILE* fp;
    unsigned long long num;
    fp=fopen(file,"r+");
    while(fscanf(fp,"%llu\n",&num)!=EOF){
        /*
        printf("%llu\n",num); тестирование
        printf("%llu\n%s\n",hi->key,hi->value);
        */
        if(num==hi->key){
            return -1;
        }
    }
    fclose(fp);
    return 0;
}
//функция записи хеша и строки в файл
int write(char* fileName, hash_item* hi){
    FILE* fp;
    fp = fopen(fileName,"a");
    if(!fp){
        printf("File opening ERROR! File not found!\n");
        return 1;
    }
    int stat=fprintf(fp,"%llu\n%s\n",hi->key,hi->value);
    fclose(fp);
    return stat;
}
