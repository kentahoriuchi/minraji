#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10000
#define NIL -1

struct Node{
    int parent;
    int left;
    int right;
};
struct Node T[MAX];
int n;

void preParse(int u){
    if(u == NIL){
        return;
    }
    printf("%d", u);
    preParse(T[u].left);
    preParse(T[u].right);
}

void inParse(int u){
    if(u == NIL){
        return;
    }
    inParse(T[u].left);
    printf("%d", u);
    inParse(T[u].right);
}

void postParse(int u){
    if(u == NIL){
        return;
    }
    postParse(T[u].left);
    postParse(T[u].right);
    printf("%d", u);
}

int main(){
    int right, left;
    int root;
    int v;

    cin >> n;//nodeの数

    for(int i = 0; i < n; i++){
        T[i].parent = NIL;
    }

    for(int i = 0; i < n; i++){
        cin >> v >> left >> right;
        T[v].left = left;
        T[v].right = right;
    }

    printf("input finish\n");

    for(int i = 0; i < n; i++){
        if(T[i].left != NIL){
            T[T[i].left].parent = i;
        }
        if(T[i].right != NIL){
            T[T[i].right].parent = i;
        }
    }

    for(int i = 0; i < n; i++){
        if(T[i].parent == NIL){
            root = i;
            break;
        }
    }
    printf("Preorder\n");
    preParse(root);
    cout << endl;
    printf("Inorder\n");
    inParse(root);
    cout << endl;
    printf("Postorder\n");
    postParse(root);
    cout << endl;

    return 0;
    
}