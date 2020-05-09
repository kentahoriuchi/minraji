#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    if(a < b and b < c ){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}