#include <iostream>

using namespace std;

struct Card{
    char suit;
    char value;
};//構造体の定義

void bubble(struct Card A[], int N){
    Card tmp;
    for(int i = 0; i < N; i++){
        for(int j = N - 1; j > i; j--){
            if(A[j].value < A[j - 1].value){
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
            }
        }
    }
}

void select(struct Card A[], int N){
    Card tmp;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j].value < A[minj].value){
                minj = j;
            }
        }
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
    }
}

void print(struct Card A[], int N){
    for(int i = 0; i < N; i++){
        if(i > 0){
            cout << " ";
        }
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}

bool isStable(struct Card C1[], struct Card C2[], int N){
    for(int i = 0; i < N; i++){
        if(C1[i].suit != C2[i].suit){
            return false;
        }
    }
    return true;
}

int main(){
    int N;

    cin >> N;

    Card C1[N];
    Card C2[N];

    for(int i = 0; i < N; i++){
        cin >> C1[i].suit >> C1[i].value;
    }

    for(int i = 0; i < N; i++){
        C2[i] = C1[i];
    }

    bubble(C1, N);
    select(C2, N);

    print(C1, N);
    cout << "Stable" << endl;
    print(C2, N);
    if(isStable(C1, C2, N) == true){
        cout << "Stable" << endl;
    }
    else{
        cout << " Not Stable" << endl;

    }

    return 0;
}