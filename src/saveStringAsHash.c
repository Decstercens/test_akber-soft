#include <stdio.h>
#include <stdlib.h>
#include "../lib/read_string.h"
#include "../lib/hash_item.h"
#include "../lib/file_work.h"

int main(void){
    int len;
    hash hash;
    char* s;
    while(1){
        printf("Please write the string that you want to store in hash table:\n");
        s=readString(&len);
        if(checkInput(s)>0){
            printf("Error! You are using forbidden symbol in your string!\nPlease use only english letters and numbers\n");
        }
        else{
            printf("You're wrote string:\n%s\nAmount memory:\n%d\n",s,len);
            hash = hash_function(s,&len);
            if(findStr("hash.txt",hash)>=0){
                write("hash.txt", hash,s);
            }
            hash=0;
        }
        printf("If you want to exit press CTRL+C\n");
        free(s);
    }
    return 0;
}