#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, pos;
vector<int> pre, in, post;

void rec(int l, int r){
    /*
    lとrはinorderの位置
    */
    if(l >= r){
        return;
    }
    int root = pre[pos++];//preOrderからrootを求める

    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    //findはインデックスを返す
    //distanceは2つの距離

    rec(l, m);//左を復元
    rec(m + 1, r);//右を復元
    post.push_back(root);//postOrderでrootをpush_back
}

void solve(){
    pos = 0;
    rec(0, pre.size());
    for(int i = 0; i < n; i++){
        if(i > 0){
            cout << " ";
        }
        cout << post[i];
    }
    cout << endl;
}

int main(){
    int k;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> k;
        pre.push_back(k);
    }

    for(int i = 0; i < n; i++){
        cin >> k;
        in.push_back(k);
    }

    solve();

    return 0;
}