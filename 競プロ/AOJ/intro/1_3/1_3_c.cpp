#include <iostream>
using namespace std;

int main(){
    int n = 3000;
    int tmp;
    int x;
    int y;
    for(int i = 0; i < n; i++){
        cin >> x;
        cin >> y;

        if(x == 0 and y == 0){
            break;
        }

        if (y < x){
            tmp = x;
            x = y;
            y = tmp;
        }

        cout << x << " " << y << endl;
    }
    return 0;
}