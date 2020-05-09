#include <iostream>
#define MAX 2000000
using namespace std;

int FB[MAX];//メモする配列

int fb(int n){
    if(n == 0 || n == 1){
        //FB[n] = 1;
        return 1;
    }
    else{
        for(int i = 2; i <= n; i++){
            FB[i] = FB[i-1] + FB[i-2];
        }
    }

    return FB[n];
}

int main(){
    int n;
    cin >> n;

    FB[0] = 1;
    FB[1] = 1;

    printf("%d\n", fb(n));

    return 0;
}