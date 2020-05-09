#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a;
    vector<int> b;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int count_game = 0;
    int victory_a = 0;

    do{
        do{
            int count_a = 0;
            int count_b = 0;
            for(int i = 0; i < n; i++){
                if(a[i] > b[i]){
                    count_a++;
                }
                else{
                    count_b++;
                }
            }
            count_game++;
            if(count_a > count_b){
                victory_a++;
            }
        }while(next_permutation(b.begin(), b.end()));

    }while(next_permutation(a.begin(), a.end()));


    printf("%f\n", (double) victory_a/count_game);

    return 0;
}