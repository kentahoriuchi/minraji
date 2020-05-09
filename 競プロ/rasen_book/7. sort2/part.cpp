#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100000

int A[MAX], n;

int partition(int p, int r){
    /*pは始点, rは終点*/
    int x, i, j, tmp;
    x = A[r];//基準

    i = p - 1;//iは基準より小さい値をもつindex

    for(j = p; j < r; j++){
        //jは今見てる場所
        if(A[j] <= x){
            i = i + 1;//基準より大きい値の先頭にする
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp; 

    return i + 1;
}

int main(){
    int i, q;
    
    scanf("%d", &n);
    for(i = 0; i < n;i++){
        scanf("%d", &A[i]);
    }

    q = partition(0, n - 1);

    for(i = 0; i < n; i++){
        if(i > 0){
            printf(" ");
        }
        if(i == q){
            printf("[%d]", A[i]);
        }
        else{
            printf("%d", A[i]);
        }
    }
    printf("\n");
    return 0;
}