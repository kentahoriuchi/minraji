#include <iostream>

using namespace std;

void trace(int A[], int N){
    for(int i = 0; i < N; i++){
        if(i > 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int main(){
    int N;
    cin >> N;//標準入力

    int A[N];//格納する配列

    for(int i = 0; i < N; i++){
        cin >> A[i];//標準入力
    }
    
    int v;
    int j;
    for(int i = 1; i < N; i++){
        v = A[i]; 
        j = i - 1;
        while(j >= 0 and v < A[j]){
            A[j+1] = A[j];
            j--;
            //cout << A << endl;
        }
        A[j+1] = v;
        trace(A, N);

    }
    return 0;
}

