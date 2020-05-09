#include <iostream>
#include <stdio.h>

using namespace std;





int main(){

    long long n, m, l;
    
    cin >> n >> m >> l;

    long long A[n][m];
    long long B[m][l];
    long long C[n][l];

    for(long long y = 0; y < n; y++){
        for(long long x = 0; x < m; x++){
            cin >> A[y][x];
        }
    }

    for(long long y = 0; y < m; y++){
        for(long long x = 0; x < l; x++){
            cin >> B[y][x];
        }
    }

    long long sum = 0;

    for(long long x = 0; x < l; x++){
        for(long long y = 0; y < n; y++){
            sum = 0;
            for(long long z = 0; z < m; z++){
                sum = sum + A[y][z] * B[z][x];
            }
            C[y][x] = sum;
        }
    }

    for(long long y = 0; y < n; y++){
        for(long long x = 0; x < l; x++){
            if(x != l - 1){
                printf("%lld ", C[y][x]);
            }
            else{
                printf("%lld\n", C[y][x]);
            }
        }
    }

    return 0;


}