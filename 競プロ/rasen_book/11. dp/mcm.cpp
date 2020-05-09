#include <iostream>
#include <cstdio>
using namespace std;



int main(){
    int n;
    scanf("%d", &n);

    int m[n + 1][n + 1];
    int p[n + 1];

    for(int i = 0; i< n; i++){
        scanf("%d %d", &p[i], &p[i + 1]);
    }

    //初期化
    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }

    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = 1000000;
            for(int k = i; k < j; k++){
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j]);
            }
        }
    }

    printf("%d\n", m[1][n]);
    return 0;
}
