#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct Card{
    char mark;
    int number;
    int flag;
} C;

int main(){
    C cards[52];
    int n;
    char str;
    int x;
    
    for(int i = 0; i < 52; i++){
        if(i < 13){
            cards[i].mark = 'S';
            cards[i].number = i + 1;
            cards[i].flag = 0;
        }
        else if(i > 12 and i < 26){
            cards[i].mark = 'H';
            cards[i].number = i - 12;
            cards[i].flag = 0;
        }
        else if(i > 25 and i < 39){
            cards[i].mark = 'C';
            cards[i].number = i - 25;
            cards[i].flag = 0;
        }
        else{
            cards[i].mark = 'D';
            cards[i].number = i - 38;
            cards[i].flag = 0;
        }
    }
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str >> x;
        for(int j = 0; j < 52; j++){
            if(cards[j].mark == str and cards[j].number == x){
                cards[j].flag = 1;
            }
        }
    }

    for(int i = 0; i < 52; i++){
        if(cards[i].flag  == 0){
            printf("%c %d\n", cards[i].mark, cards[i].number);
        }
    }

    return 0;
}


