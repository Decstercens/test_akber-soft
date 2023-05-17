#include<stdio.h>
#include "../lib/read_string.h"
#include "../lib/hash_item.h"

char* readString(int* len);
int main(void){
    int len;
    printf("Please write the string that you want to store in hash table:\n");
    char* s=readString(&len);
    printf("You're wrote:\n%s\n Amount memory :\n %d\n",s,len);
}