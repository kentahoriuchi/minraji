#include <iostream>

using namespace std;

int main(){
    int x = 10000;
    int n;
    for(int i = 0; i < x; i++){
        cin >> n;
        if(n == 0){
            break;
        }
        cout << "Case " << i + 1 << ": " << n << endl;

    }
    return 0;
}