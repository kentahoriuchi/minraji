#include <iostream>
#include <stdio.h>
#include <string>


using namespace std;

int main(){
    int n = 1000;
    int a, b;
    int x;
    //char c[1];
    string c;
    int A[100];
    int count = 0;

    for(int i = 0; i < n; i++){
        cin >> a >> c >> b;
        //printf("a %d\n", a);
        //printf("aaa\n");
        //cout << c << endl;
        if("+" == c){
            //printf("bbb\n");
            x = a + b;
            A[i] = x;
            //printf("ccc\n");
        }
        else if("-" == c){
            x = a - b;
            A[i] = x;
        }
        else if("*" == c){
            x = a * b;
            A[i] = x;
        }
        else if ("/" == c){
            x = a / b;
            A[i] = x;
        }
        else if("?" == c){
            break;
        }
        
        count++;
        //printf("ddd\n");
   
    }
    
    for(int i = 0; i < count; i++){
        printf("%d\n", A[i]);
    }
    

    return 0;
    
}