#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int m, f, r;
    while(1){
        cin >> m >> f >> r;
        if(m == -1 and f == -1 and r == -1){
            break;
        }
        else{
            if(m == -1 or f == -1){
                printf("F\n");
            }
            else if(m + f >= 80){
                printf("A\n");
            }
            else if(m + f >= 65 and m + f < 80){
                printf("B\n");
            }
            else if(m + f >= 50 and m + f < 65){
                printf("C\n");
            }
            else if(m + f >= 30 and m + f < 50){
                if(r >= 50){
                    printf("C\n");
                }
                else{
                    printf("D\n");
                }
            }
            else{
                printf("F\n");
            }

        }
    }
    return 0;
}