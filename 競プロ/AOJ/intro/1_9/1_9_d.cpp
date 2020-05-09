#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    char str[1000];
    int n;
    char instruct[100];
    char str_re[1000];

    int a, b;
    int i;

    scanf("%s", str);
    scanf("%d", &n);
    //cin >> n;

    for(i = 0; i < n; i++){
        //printf("n is %d\n", n);
        scanf("%s", instruct);
        //printf("n is %d\n", n);
        //printf("instruct ok\n");
        //printf("n is %d\n", n);

        if(strcmp(instruct, "replace") == 0){
            //printf("n is %d\n", n);
            cin >> a >> b;
            //printf("n is %d\n", n);
            //printf("a b ok\n");
            scanf("%s", str_re);
            //printf("str_re ok %s\n", str_re);

            for(int j = a; j <= b; j++){
                str[j] = str_re[j - a];
            }
            //printf("replace %s\n", str);

        }

        else if(strcmp(instruct, "reverse") == 0){
            cin >> a >> b;
            reverse(&str[a], &str[b+1]);
            //printf("reverse %s\n", str);
        }

        else if(strcmp(instruct, "print") == 0){
            cin >> a >> b;

            for(int j = a; j <= b; j++){
                printf("%c", str[j]);
            }
            cout << endl;
        }
        //printf("n is %d\n", n);
        //printf("i : %d\n", i);
        //printf("n is %d\n", n);
    }
    return 0;

}