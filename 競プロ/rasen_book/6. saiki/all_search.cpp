#include <iostream>
#include <stdio.h>
using namespace std;

int n, A[50];

int solve(int i, int m){
    if(m == 0){
        return 1;
    }
    if(i >= n){
        return 0;
    }
    int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    return res;
}

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int q;
    scanf("%d", &q);

    int m;

    for(int i = 0; i < q; i++){
        scanf("%d", &m);
        if(solve(0, m) == 1){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }

    return 0;

}