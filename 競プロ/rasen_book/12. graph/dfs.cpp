#include <iostream>
#include <cstdio>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define N 100

int n, matrix[N][N];
int color[N], d[N], f[N], tt;


void dfs_visit(int u){
    int v;
    color[u] = gray;
    d[u] = ++tt;
    for(v = 0; v < n; v++){
        if(matrix[u][v] == 0){
            continue;//ループの終わりに飛ぶ
        }
        if(color[v] == white){
            dfs_visit(v);
        }
    }
    color[u] = black;
    f[u] = ++tt;
}

void dfs(){
    int u;
    for(u = 0; u < n; u++){
        color[u] = white;
    }
    tt = 0;
    
    for(u = 0; u < n; u++){
        if(color[u] == white){
            dfs_visit(u);
        }
    }
   // dfs_visit(0);

    for(u = 0; u < n; u++){
        printf("%d %d %d\n", u + 1, d[u], f[u + 1]);
    }
}

int main(){
    
    scanf("%d", &n);

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
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }*/

    dfs();

    return 0;
}