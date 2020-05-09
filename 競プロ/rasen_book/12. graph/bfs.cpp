#include <iostream>
#include <queue>

using namespace std;
static const int N = 100;
static const int INFTY = (1<<21);

int n, matrix[N][N];
int d[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    
    //初期化
    for(int i = 0; i < n; i++){
        d[i] = INFTY;
    }
    d[s] = 0;//始点
    int u;

    //printf("while\n");
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }*/

    while(!q.empty()){
        //printf("while 2\n");
        u = q.front();
        q.pop();
        //printf("while 3\n");
        for(int v = 0; v < n; v++){
            if(matrix[u][v] == 0){
                //printf("matrix[u][v] == 0 continue\n");
                continue;
            }
            if(d[v] != INFTY){
                
                //printf("d != INFNY continue\n");
                continue;
            }
            //printf("aaa\n");
            d[v] = d[u] + 1;
            //printf("d[v] %d\n", d[v]);
            q.push(v);
        }
    }
    //printf("while finish\n");

    for(int i = 0; i < n; i++){
        printf("%d %d\n", i + 1, d[i]);
    }
}

int main(){
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }

    int u2, k;

    int a;


    for(int i = 0; i < n; i++){
        cin >> u2 >> k;
        if(k > 0){
            for(int j = 0; j < k; j++){
                cin >> a;
                matrix[u2 - 1][a - 1] = 1;
            }
        }
    }
    
   

    bfs(0);

    return 0;
}
