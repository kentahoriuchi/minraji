#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main(){
    int n;
    cin >> n;//配列の長さ

    int A[n];
    int B[n];
    int C[n];

    for(int i = 0; i < n; i++){
        C[i] = 0;//Cの初期化
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        C[A[i]]++;
    }

    /*
    printf("C : \n");
    for(int i = 0; i < n; i++){
        printf("%d\n", C[i]);
    }
    printf("finish\n");
    */

    //printf("C : \n");
    for(int i = 0; i < n; i++){
        if(i > 0){
            C[i] = C[i] + C[i - 1];//累計にする
        }
        //printf("%d\n", C[i]);
    }
    //printf("finish\n");


    for(int i = 0; i < n; i++){
        B[C[A[i]]-1] = A[i];//1つずれることに注意
        //printf("%d\n", B[C[A[i]]]);
        C[A[i]]--;
    }
    //printf("finish\n");

    for(int i = 0; i < n; i++){
        printf("%d\n", B[i]);
    }


    return 0;


    
}
