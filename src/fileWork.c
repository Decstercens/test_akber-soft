#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/hash_item.h"
#include "../lib/file_work.h"
//функция проверки хеша на наличие в файле
int findStr(char* file,hash hash){
    FILE* fp;
    unsigned long long num;
    fp=fopen(file,"r");//создаем поток на чтение из файла
    while(fscanf(fp,"%llu[^\na-zA-z]",&num)!=EOF){//читаем хеш из файла в переменную num 
        fgetc(fp);//пропускаем символ перехода строки
        if(num==hash){//сравниваем введенный пользователем хеш с хешем из файла
            printf("ERROR! This string already in the file!\nWrite something else!\n");
            fclose(fp);//закрываем поток
            return -1;//если есть выход
        }
    }
    fclose(fp);
    return 0;
}

//функция записи хеша и строки в файл
int write(char* fileName, hash hash, char* str){
    FILE* fp;
    fp = fopen(fileName,"a");//создаем поток на запись в файл
    if(!fp){
        printf("File opening ERROR! File not found!\n");
        return 1;
    }
    //Записываем обе переменные в файл, каждую с новой строки
    int stat=fprintf(fp,"%llu\n%s\n",hash,str);
    fclose(fp);
    return stat;
}