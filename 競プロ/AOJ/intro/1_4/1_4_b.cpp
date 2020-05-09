#include <iostream>
#include <stdio.h>
#include <math.h>/*M_PI*/
using namespace std;

int main(){
    double r;
    cin >> r;

    double s, l;

    s = M_PI * r * r;
    l = M_PI * 2 * r;

    printf("%f %f\n", s, l);
    return 0;
}
