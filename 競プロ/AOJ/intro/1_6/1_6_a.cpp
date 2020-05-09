#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n;
    

    cin >> n;
    int A[n];

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = n - 1; i >= 0; i--){
        if(i == 0){
            printf("%d\n", A[i]);
        }
        else{
            printf("%d ", A[i]);
        }

    }
    return 0;
}