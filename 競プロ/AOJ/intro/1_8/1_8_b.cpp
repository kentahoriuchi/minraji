#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main(){

    int count;
    long n;
    int amari;
    int length;

    char str[1000];
    
    while(1){
        //scanf("%ld", &n);
        scanf("%s", str);//文字列で読み込む
        //printf("%s\n", str);
        length = strlen(str);
        //printf("length : %d\n", length);
        count = 0;
        amari = 0;
        //printf("n : %ld\n", n);
        if(str[0] == '0'){
            break;
        }
        else{
            for(int i = 0; i < length; i++){
                int kazu = ctoi(str[i]);
                count = count + kazu;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}