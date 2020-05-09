#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int max_A = A[0];
    int min_A = A[0];
    long count = 0;

    for(int i = 0; i < n; i++){
        count = count + A[i];
        if(max_A < A[i]){
            max_A = A[i];
        }
        if(min_A > A[i]){
            min_A = A[i];
        }
    }

    cout << min_A << " " << max_A << " " << count << endl;

    return 0;
}