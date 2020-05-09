#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;


void insert(int A[], int n, int g){
    int count = 0;
    for(int i = g; i < n; i++){
        int v = A[i];
        int j = i - g;
        while(j >= 0 and v < A[j]){
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        } 
        A[j + g] = v;
    }
}

void shell_sort(int A[], int n){
    for(int h = 1; ;){
        if(h > n){
            break;
        }
        G.push_back(h);
        h = 3*h + 1;
    }
    for(int i = G.size() - 1; i >=0; i--){
        insert(A, n, G[i]);
    }
}

void print(int A[], int N){
    for(int i = 0; i < N; i++){
        if(i > 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int main(){
   
    cin >> n;//標準入力

    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);//標準入力
    }

    cnt = 0;
    shell_sort(A, n);

    cout << G.size() << endl;

    for(int i = G.size() - 1; i >=0; i--){
        if(i != 0){
            printf("%d ", G[i]);
        }
        else{
            printf("%d\n", G[i]);
        }
    }

    cout << cnt << endl;
    print(A, n);

    return 0;
}