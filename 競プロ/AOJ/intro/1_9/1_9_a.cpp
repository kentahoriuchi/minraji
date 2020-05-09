#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char* lower(char c[]){
    int len = strlen(c);

    for(int i = 0; i < len; i++){
        if('A' <= c[i] and c[i] <= 'Z'){
            c[i] = c[i] + 32;
        }
    }
    return c;

}


int main(){
    char word[10];
    char text[100];
    //char texts[20];

    scanf("%s", word);
    int count = 0;

    while(1){
        scanf("%s", text);//空白、改行は読み込まない
        if(strcmp(text, "END_OF_TEXT") == 0){
            break;
        }
        else{
            if(strcmp(word, lower(text)) == 0){
            //printf("%s\n", text[i]);
            count++;
            }
        }
    }

    
   
   printf("%d\n", count);
   //printf("aaaa\n");
   return 0;
}