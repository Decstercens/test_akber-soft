#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "../lib/read_string.h"

//Функция чтения строки неограниченной длинны из консоли в массив символов
char* readString(int* len){
    *len=0; // сначала строка пустая
    int capacity=1; //минимальный размер массива строк
    char *s=(char*)malloc(sizeof(char)); //динамическая пустая строка
    char c=getchar(); //промежуточная переменная для хранения символа
    while(c!='\n'){//продолжить ввод, пока не будет символа переноса строки
        s[(*len)++]=c; //вносим строку в массив строк
        if(*len>=capacity){//если массив переполнен
            capacity*=2;//увеличить размер в 2 раза
            s=(char*) realloc(s,capacity*sizeof(char));//увеличить размер памяти для массива
        }
        c=getchar();//прочитать новый символ
    }
    s[*len]='\0';//завершение строки
    return s;
}
//функция проверки введенной строки на соответствие шаблону
int checkInput(char* str){
    regex_t reg;//создаем переменную для хранения регулярки
    char* pattern="[^a-zA-Z0-9\\p{P}$\\^+><|~`]"; //регулярка
    regcomp(&reg,pattern,0);//компиляция регулярки в исполняемую строку
    int res=regexec(&reg,str,0,NULL,0);//сравнение строки с регуляркой
    if(!res){//если есть совпадение
        regfree(&reg);//освобождаем место в памяти
        return 1;
    }
    else if(res==REG_NOMATCH){//если нет совпадений
        regfree(&reg);
        return 0;
    }
    else{
        regfree(&reg);
        return -1;
    }
}