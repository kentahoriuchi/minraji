#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    long double a, b;
    cin >> a;
    cin >> b;
    
    int d = int(a)/ int(b);
    int r = int(a)% int(b);
    long double f = a / b;
    printf("%d %d %Lf\n",d, r, f);

    return 0;
}