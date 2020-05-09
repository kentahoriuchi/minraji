#include <iostream>
#include <stdio.h>
using namespace std;

int search(int A[], int n, int key){
    int i = 0;
    A[n] = key;//番兵
    while(A[i] != key){
        i++;
    }
    //printf("%d\n", i != n);
    return i != n;
}

int main(){
    int A[10001];
    int n;
    int q;
    int Q[10001];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];;
    }

    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> Q[i];;
    }

    int count = 0;

    for(int i = 0; i < q; i++){

        count = count + search(A, n, Q[i]);
    }

    cout << count << endl;

    return 0;
    
    }
