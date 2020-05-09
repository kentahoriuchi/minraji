#include <iostream>
#include <vector>
#include <stack>
using namespace std;
static const int MAX = 100000;
static int NIL = -1;

int n;
vector<int> G[MAX];
int color[MAX];

void dfs(int r, int c){
    stack<int> S;
    S.push(r);
    color[r] = c;
    while(!S.empty()){
        int u = S.top();
        S.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            if(color[v] == NIL){
                color[v] = c;
                S.push(v);

            }
        }
    }
}

void assignColor(){
    int id = 1;
    for(int i = 0; i < n; i++){
        color[i] = NIL;
    }
    for(int u = 0; u < n; u++){
        if(color[u] == NIL){
            dfs(u, id++);
        }
    }
}

int main(){
    int m;
    int a, b;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    assignColor();

    //printf("information input finish\n");

    int mm;

    cin >> mm;

    for(int i = 0; i < mm; i++){
        cin >> a >> b;
        if(color[a] == color[b]){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }

    return 0;
    
}

