#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }

    int u, k;

    int a;


    for(int i = 0; i < n; i++){
        cin >> u >> k;
        if(k > 0){
            for(int j = 0; j < k; j++){
                cin >> a;
                matrix[u - 1][a - 1] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;

}