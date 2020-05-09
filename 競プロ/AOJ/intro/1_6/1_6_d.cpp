#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int A[n][m];
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            scanf("%d", &A[y][x]);
        }
    }

    int b[m];
    for(int x = 0; x < m; x++){
        scanf("%d", &b[x]);
    }

    int sum;
    for(int y = 0; y < n; y++){
        sum = 0;
        for(int x = 0; x < m; x++){
            sum = sum + A[y][x] * b[x];
        }
        printf("%d\n", sum);
    }
    return 0;
    }