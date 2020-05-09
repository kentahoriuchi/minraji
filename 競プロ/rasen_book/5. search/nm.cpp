#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 100000

int n, k;//nは荷物の数、kはトラックの数
long long T[MAX];//荷物を入れる配列

int check(long long P){
    /*積載量Pのk台のトラックから積める荷物の数を返す*/
    int num = 0;
    long long sum_w;
    for(int j = 0; j < k; j++){
        sum_w = 0;
        while(sum_w + T[num] <= P){
            sum_w += T[num];
            num++;
            if(num == n){
                return n;
            }
        }
    }
    return num;
}

int solve(){
    long long left = 0;
    long long right = 100000 * 10000;//荷物の個数 * 1個あたりの最大重量
    long long mid;
    while(right - left > 1){
        mid = (right + left) / 2;
        //printf("mid %lld\n", mid);
        int v = check(mid);//vは荷物の個数
        if(v >= n){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    return mid;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> T[i];
        //printf("%lld\n", T[i]);
    }
    long long ans = solve();
    cout << ans << endl;
    return 0;
}