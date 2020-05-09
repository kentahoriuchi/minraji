#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int mansion[4][3][10];//4mansions 3floors 10rooms

    for(int z = 0; z < 4; z++){
        for(int y = 0; y < 3; y++){
            for(int x = 0; x < 10; x++){
                mansion[z][y][x] = 0;
            }
        }
    }//初期化

    int informations;
    
    cin >> informations;

    int man[informations];
    int floor[informations];
    int room[informations];
    int people[informations];

    for(int i = 0; i < informations; i++){
        cin >> man[i]>> floor[i] >> room[i] >> people[i];
    }
    //標準入力完了

    for(int i = 0; i < informations; i++){
        mansion[man[i] - 1][floor[i] - 1][room[i] - 1] += people[i];

    }
    //情報を入力完了

    for(int z = 0; z < 4; z++){
        for(int y = 0; y < 3; y++){
            for(int x = 0; x < 10; x++){
                if (x != 9){
                printf(" %d", mansion[z][y][x]);
                }
                else{
                    printf(" %d\n", mansion[z][y][x]);
                }
            }
        }
        if(z < 3){
            printf("####################\n");
        }
    }
    //printf("%d\n", mansion[4])
    return 0;

}