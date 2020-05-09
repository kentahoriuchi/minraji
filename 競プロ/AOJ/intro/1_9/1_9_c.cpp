#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int n;
    int point_a = 0;
    int point_b = 0;
    char char_a[100];
    char char_b[100];
    string str_a, str_b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", char_a);
        scanf("%s", char_b);

        str_a = char_a;
        str_b = char_b;
        if( str_a < str_b){
            point_b = point_b + 3;

        }
        else if(str_a > str_b){
            point_a = point_a + 3;
        }
        else{
            point_a++;
            point_b++;
        }
    }
    printf("%d %d\n", point_a, point_b);

    return 0;
}