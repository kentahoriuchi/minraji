#include <iostream>

using namespace std;

void select_sort(int A[], int N){
    int tmp;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
        }

    }
}

int main(){
    int A[3];

    cin >> A[0];
    cin >> A[1];
    cin >> A[2];

    select_sort(A, 3);

    for(int i = 0; i < 3; i++){
        if(i > 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;

    return 0;
}