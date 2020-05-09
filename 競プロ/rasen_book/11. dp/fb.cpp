#include <iostream>
#define MAX 2000000
using namespace std;

int FB[MAX];//メモする配列

int fb(int n){
    if(n == 0 || n == 1){
        FB[n] = 1;
        return 1;
    }
    if(FB[n] != 0 and n >= 2){
        return FB[n];
    }
    FB[n] = fb(n-1) + fb(n-2); 
    
    return FB[n];
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        FB[i] = 0;
    }//初期化
    printf("%d\n", fb(n));

    return 0;
}