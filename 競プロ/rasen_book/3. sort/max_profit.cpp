#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 200000;

int main(){
    int R[MAX];
    int n;
    cin >> n;//標準入力
    for(int i = 0; i < n; i++){
        cin >> R[i];//標準入力
    }
    int maxv = -200;
    int minv = R[0];
    for (int i = 1; i < n; i++){
        maxv = max(maxv, R[i] - minv);
        minv = min(minv, R[i]);
    }

    cout << maxv << endl;
    return 0;
}