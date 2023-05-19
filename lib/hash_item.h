#ifndef HASHITEM_H
#define HASHITEM_H
//структура хеш элемента(хеш, строка)
typedef unsigned long long hash;

unsigned long hash_function(char* str,int* len);

#endif /*HASHITEM_H*/