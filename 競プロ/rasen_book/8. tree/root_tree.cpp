#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node{
    int parent;//親
    int left;//左の子
    int right;//右の兄弟
};

Node T[MAX];//ノードを格納
int n;
int D[MAX];//各ノードのdepth

void print(int u){
    //u is node number
    int i, c;
    cout << "node" << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";
    if(T[u].parent == NIL){
        cout << "root, ";
    }
    else if(T[u].left == NIL){
        cout << "leaf, ";
    }
    else{
        cout << "internal node, ";
    }

    cout << "[";
    //子供をprintしている
    for(i = 0, c = T[u].left; c != NIL; i++, c = T[c].right){
        if(i > 0){
            cout << ", ";
        }
        cout << c;
    }
    cout << "]" << endl;
}

void rec(int u, int p){
    //u is node, p is depth 再帰的に深さを求める
    D[u] = p;
    if(T[u].right != NIL){
        rec(T[u].right, p);
    }
    if(T[u].left != NIL){
        rec(T[u].left, p + 1);
    }
}

int main(){
    int i, j, d, v, c, l, r;
    cin >> n;//ノードの数

    //ノードの初期化
    for(i = 0; i < n; i++){
        T[i].parent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }

    for(i = 0; i < n; i++){
        //printf("n %d\n", n);
        cin >> v >> d;//vは親ノード, dは子の数
        for(j = 0; j < d; j++){
            cin >> c;//子ノード
            //l = c;
            if(j == 0){
                T[v].left = c;
            }
            else{
                T[l].right = c;
            }
            l = c;
            T[c].parent = v;
        }
    }

    //rootを求めている
    for(i = 0; i < n; i++){
        if(T[i].parent == NIL){
            r = i;
        }
    }

    rec(r, 0);

    for(i = 0; i < n; i++){
        print(i);
    }

    return 0;
}