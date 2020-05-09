#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define N 100

int n, matrix[N][N];
int color[N], d[N], f[N], tt;
int nt[N];

int next(int u){
    for(int v = nt[u]; v < n; v++){
        nt[u] = v + 1;
        if(matrix[u][v] == 1){
            return v;
        }
    }
    return -1;
}

void dfs_visit(int r){
    for(int i = 0; i < n; i++){
        nt[i] = 0;
    }

    stack<int> S;
    S.push(r);
    color[r] = gray;
    d[r] = ++tt;

    while(!S.empty()){
        int u = S.top();
        int v = next(u);
        if(v != -1){
            if(color[v] == white){
                color[v] = gray;
                d[v] = ++tt;
                S.push(v);
            }
        }else{
            S.pop();
            color[u] = black;
            f[u] = ++tt;
        }
    }
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