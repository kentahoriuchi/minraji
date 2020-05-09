#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

struct Node{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

Node * treeMinimum(Node *x){
    //左に行きまくる
    while(x->left != NIL){
        x = x->left;
    }
    return x;
}

Node * treeSuccessor(Node *x){
    /*
    if(x->right != NIL){
        return treeMinimum(x->right);
    }
    Node *y = x->parent;
    while( y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y*/
    return treeMinimum(x->right);
}

void treeDelete(Node *z){
    Node *y;//削除する対象
    Node *x;//yの子

    //削除する節点を決める
    if(z->left == NIL || z->right == NIL){
        y = z;//子が0か1
    }
    else{
        //子が2
        y = treeSuccessor(z);
    }

    //yの子xを決める
    if(y->left != NIL){
        x = y->left;
    }
    else{
        x = y->right;
    }

    //xの親をyの親にする 下から上に繋ぐ
    if(x != NIL){
        x->parent = y->parent;
    }

    //上から下に繋ぐ
    if( y->parent == NIL){
        root = x;//yがrootならxはroot
    }
    else{
        if(y == y->parent->left){
            y->parent->left = x;
        }
        else{
            y->parent->right = x;
        }
    }

    if( y != z){
        z->key = y->key;//入れ替える
    }

    free(y);//yを削除する
}

Node * find(Node *u, int k){
    //u is root
    //return is node
    while(u != NIL && k != u ->key){
        if(k < u->key){
            u = u->left;
        }
        else{
            u = u->right;
        }
    }
    return u;
}


void insert(int k){
    Node *y = NIL;//親
    Node *x = root;//rootから探索する 現在のノード
    Node *z;//挿入するノード

    z = (Node *)malloc(sizeof(Node));//初期化
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;//1つ前,つまり親
        if(z->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }

    z->parent = y;//下から上に繋ぐ

    //上から下に繋ぐ
    if(y == NIL){
        root = z;
    }
    else{
        if(z->key < y->key){
            y->left = z;
        }
        else{
            y->right = z;
        }
    }
}

void inorder(Node *u){
    if(u == NIL){
        return;
    }
    inorder(u->left);
    printf("%d ", u->key);
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL){
        return;
    }
    printf("%d ", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(){
    int n, x;
    string com;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        cin >> com;
        if(com == "insert"){
            scanf("%d", &x);
            insert(x);
        }
        else if(com == "print"){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
        else if(com == "find"){
            scanf("%d", &x);
            Node *t = find(root, x);
            if(t != NIL){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
        else if(com == "delete"){
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }
    return 0;
}


