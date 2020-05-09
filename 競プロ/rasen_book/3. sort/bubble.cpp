#include <iostream>

using namespace std;

int bubble_sort(int A[], int N){
    bool flag = 1;
    int i = 0;
    int tmp;
    int count = 0;
    while (flag == 1){
        flag = 0;
        for(int j = N - 1; j > i; j--){
            if(A[j] < A[j - 1]){
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                count++;
                flag = 1;
                //printf("%d\n", flag);
            }
        }
        i++;
        //printf("%d\n", flag);
    }
    return count;
}

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
    int count;
    count = bubble_sort(A, N);//バブルソートをする

    trace(A, N);
    //printf("%d\n", count);
    cout << count << endl;//標準出力
    

    return 0;

}