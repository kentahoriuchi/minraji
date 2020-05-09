#include <iostream>
#include <stdio.h>

using namespace std;

int A[1000000], n;

int binarySearch(int A[], int key){
    int left = 0;
    int right = n;
    //printf("%d\n", right);
    int mid = 0;

    while(left < right){
        mid = (left + right)/2;
        if(A[mid] == key){
            return 1;
        }
        else if(key < A[mid]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }

    return 0;

}

int main(){
    //int A[10001];
    //int n;
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

        //printf("%d\n", binarySearch(A, Q[i]));
        count = count + binarySearch(A, Q[i]);
    }

    cout << count << endl;

    return 0;
    
    }
