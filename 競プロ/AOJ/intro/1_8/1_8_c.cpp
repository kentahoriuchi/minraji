#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int counter[26];

void char_count(char s[]){
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        if(s[i] == 'a' || s[i] == 'A'){
            counter[0]++;
        }
        else if(s[i] == 'b' || s[i] == 'B'){
            counter[1]++;
        }
        else if(s[i] == 'c' || s[i] == 'C'){
            counter[2]++;
        }
        else if(s[i] == 'd' || s[i] == 'D'){
            counter[3]++;
        }
        else if(s[i] == 'e' || s[i] == 'E'){
            counter[4]++;
        }
        else if(s[i] == 'f' || s[i] == 'F'){
            counter[5]++;
        }
        else if(s[i] == 'g' || s[i] == 'G'){
            counter[6]++;
        }
        else if(s[i] == 'h' || s[i] == 'H'){
            counter[7]++;
        }
        else if(s[i] == 'i' || s[i] == 'I'){
            counter[8]++;
        }
        else if(s[i] == 'j' || s[i] == 'J'){
            counter[9]++;
        }
        else if(s[i] == 'k' || s[i] == 'K'){
            counter[10]++;
        }
        else if(s[i] == 'l' || s[i] == 'L'){
            counter[11]++;
        }
        else if(s[i] == 'm' || s[i] == 'M'){
            counter[12]++;
        }
        else if(s[i] == 'n' || s[i] == 'N'){
            counter[13]++;
        }
        else if(s[i] == 'o' || s[i] == 'O'){
            counter[14]++;
        }
        else if(s[i] == 'p' || s[i] == 'P'){
            counter[15]++;
        }
        else if(s[i] == 'q' || s[i] == 'Q'){
            counter[16]++;
        }
        else if(s[i] == 'r' || s[i] == 'R'){
            counter[17]++;
        }
        else if(s[i] == 's' || s[i] == 'S'){
            counter[18]++;
        }
        else if(s[i] == 't' || s[i] == 'T'){
            counter[19]++;
        }
        else if(s[i] == 'u' || s[i] == 'U'){
            counter[20]++;
        }
        else if(s[i] == 'v' || s[i] == 'V'){
            counter[21]++;
        }
        else if(s[i] == 'w' || s[i] == 'W'){
            counter[22]++;
        }
        else if(s[i] == 'x' || s[i] == 'X'){
            counter[23]++;
        }
        else if(s[i] == 'y' || s[i] == 'Y'){
            counter[24]++;
        }
        else if(s[i] == 'z' || s[i] == 'Z'){
            counter[25]++;
        }
    }
}

int main(){
    int n = 1200;
    char str[n];
    int x;

    for(int i = 0; i < 26; i++){
        counter[i] = 0;
    }

    while(1){
        x  = scanf("%[^\n]%*c", str);//空白も読み込む
        if(x != 1){
            break;
        }
        else{
            char_count(str);
        }
    }
    
    printf("a : %d\n", counter[0]);
    printf("b : %d\n", counter[1]);
    printf("c : %d\n", counter[2]);
    printf("d : %d\n", counter[3]);
    printf("e : %d\n", counter[4]);
    printf("f : %d\n", counter[5]);
    printf("g : %d\n", counter[6]);
    printf("h : %d\n", counter[7]);
    printf("i : %d\n", counter[8]);
    printf("j : %d\n", counter[9]);
    printf("k : %d\n", counter[10]);
    printf("l : %d\n", counter[11]);
    printf("m : %d\n", counter[12]);
    printf("n : %d\n", counter[13]);
    printf("o : %d\n", counter[14]);
    printf("p : %d\n", counter[15]);
    printf("q : %d\n", counter[16]);
    printf("r : %d\n", counter[17]);
    printf("s : %d\n", counter[18]);
    printf("t : %d\n", counter[19]);
    printf("u : %d\n", counter[20]);
    printf("v : %d\n", counter[21]);
    printf("w : %d\n", counter[22]);
    printf("x : %d\n", counter[23]);
    printf("y : %d\n", counter[24]);
    printf("z : %d\n", counter[25]);


    return 0;
}