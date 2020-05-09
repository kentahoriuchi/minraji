#include <iostream>
#include <stdio.h>
using namespace std;

void call(int n){
  int i = 1;
 CHECK_NUM:
  int x = i;
  if ( x % 3 == 0 ){
    cout << " " << i;
    goto END_CHECK_NUM;
  }
 INCLUDE3:
  if ( x % 10 == 3 ){
    cout << " " << i;
    goto END_CHECK_NUM;
  }
  x /= 10;
  //printf("x %d ", x);
  //printf("i %d\n", i);
  if ( x != 0) goto INCLUDE3;
 END_CHECK_NUM:
  if ( ++i <= n ) goto CHECK_NUM;

  cout << endl;
}


void call0(int n){
    int i = 1;
    //printf("a\n");
    while(1){
        //printf("aa\n");
        int x = i;
        //printf("aaa\n");
        if(x % 3 == 0){
            cout << " " << i;
            if(++i > n){
                break;
            }
        }
        else{
            while(1){
                if(x % 10 == 3){
                    cout << " " << i;
                    break;
                }
                else{
                    x = x/10;
                    if (x == 0){
                        break;
                    }
                }
                //printf("included3");
            }
            if(++i > n){
                break;
            }
        }
    }
    cout << endl;
}


int main(){
    //call(30);

    //printf("\n");
    int n;
    cin >> n;
    call0(n);

    return 0;

}