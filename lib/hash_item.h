#ifndef HASHITEM_H
#define HASHITEM_H
//структура хеш элемента(хеш, строка)
typedef struct hash_item hash_item;

struct hash_item
{
    unsigned long long key;
    char* value;
};

unsigned long hash_function(char* str);

hash_item* create_item(unsigned long long key, char* value);

#endif /*HASHITEM_H*/