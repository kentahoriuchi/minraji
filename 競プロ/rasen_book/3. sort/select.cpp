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

int select_sort(int A[], int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        //printf("minj %d\n", minj);
        int tmp;
        for(int j = i; j < N; j++){
            if( A[j] < A[minj]){
                minj = j;
            }
        }
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        if ( i != minj){
            count++;
            //printf("count %d\n", count);
        }
        
    }
    return count;
}

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int count;
    count = select_sort(A, N);
    trace(A, N);
    cout << count << endl;

    return 0;

}

