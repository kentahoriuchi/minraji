#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n = 10000;
    int N = 0;
    int H[n];
    int W[n];
    int h, w;

    for(int i = 0; i < n; i++){
        cin >> H[i] >> W[i];
        N++;
        if(H[i] == 0 and W[i] == 0){
            break;
        }
    }

    for(int i = 0; i < N - 1; i++){
            for(int y = 0; y < H[i]; y++){
                for(int x = 0; x < W[i]; x++){
                    printf("#");
                }
                printf("\n");
            }
            printf("\n");
        
       
    }
    return 0;
}