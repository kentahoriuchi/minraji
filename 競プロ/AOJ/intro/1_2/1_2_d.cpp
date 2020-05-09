#include <iostream>

using namespace std;

int main(){
    int W, H, x, y, r;
    cin >> W;
    cin >> H;
    cin >> x;
    cin >> y;
    cin >> r;

    if((0 <= x - r) and (0 <= y - r) and (x + r <= W) and (y + r <= H)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}