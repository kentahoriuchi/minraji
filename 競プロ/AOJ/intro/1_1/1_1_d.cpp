#include <iostream>
using namespace std;

int main(){
    int S;
    cin >> S;
    int h;
    int m;
    int s;

    int amari;

    h = S / 3600;

    amari = S % 3600;

    m = amari / 60;

    s = amari % 60;

    cout << h << ":" << m << ":" << s << endl;

    return 0;

}