#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int c[1001][1001];

int lcs(char X[], char Y[]){
    int len_x = strlen(X);
    int len_y = strlen(Y);

    for(int i = 0; i <= len_x; i++){
        c[0][i] = 0;
    }

    for(int i = 0; i <= len_y; i++){
        c[i][0] = 0;
    }
    for(int y = 1; y <= len_y; y++){
        for(int x = 1; x <= len_x; x++){
            if(X[x] == Y[y]){
                c[y][x] = c[y - 1][x - 1] + 1;
            }
            else{
                c[y][x] = max(c[y][x-1], c[y - 1][x]);
            }
        }
    }

    return c[len_y][len_x];

}

int main(){

    int n;
    char X[1000], Y[1000];

    cin >> n;

    for(int i = 0; i < n; i++){
        scanf("%s %s", X, Y);
        printf("%d\n", lcs(X, Y));

    }

    return 0;

}