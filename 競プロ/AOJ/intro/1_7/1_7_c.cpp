#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int r, c;

    cin >> r >> c;

    int A[r + 1][c + 1];

    int sum_x;
    
    for(int y = 0; y < r; y++){
        sum_x = 0;
        for(int x = 0; x < c + 1; x++){
            if(x < c){
            cin >> A[y][x];
            sum_x = sum_x +  A[y][x];
            }
            else{
                A[y][x] = sum_x;
            }
        }
    }

    int sum_y;

    for(int x = 0; x < c + 1; x++){
        sum_y = 0;
        for(int y = 0; y < r; y++){
            sum_y = sum_y + A[y][x];
        }
        A[r][x] = sum_y;
    }

    for(int y = 0; y < r + 1; y++){
        for(int x = 0; x < c + 1; x++){
            if(x > 0){
                printf(" %d", A[y][x]);
            }
            else{
                printf("%d", A[y][x]);
            }
        }
        printf("\n");
    }

    return 0;
}