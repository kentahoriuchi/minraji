#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(){
    int n, q, t;
    string name;
    queue<pair<string, int> > Q;

    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }
    pair<string, int> u;
    int elaps = 0, a;
    while(Q.empty() != true){
        u = Q.front();
        Q.pop();
        a = min(u.second, q);
        u.second = u.second - a;
        elaps = elaps + a;
        if(u.second > 0){
            Q.push(u);
        }
        else{
            printf("%s %d\n", u.first.c_str(), elaps);
        }
    }
    return 0;
}