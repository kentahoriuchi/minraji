#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char upper(char c){
    if('a' <= c and c <= 'z'){
        c = c - 32;
    }
    return c;
}

char lower(char c){
    if('A' <= c and c <= 'Z'){
        c = c + 32;
    }
    return c;

}

int main(){
    int n = 1200;
    char str[n];



    scanf("%[^\n]%*c", str);//空白も読み込む
    

    int length = strlen(str);

    //printf("length %d\n", length);

    

    for(int i = 0; i < length; i++){
        if('a' <= str[i] and str[i] <= 'z'){
            str[i] = upper(str[i]);
        }
        else if('A' <= str[i] and str[i] <= 'Z'){
            //printf("%c", str[i]);
            str[i] = lower(str[i]);
        }
    }
    
    printf("%s", str);
    printf("\n");

    return 0;

}