#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
    char s[200];
    char p[100];

    scanf("%s", s);
    scanf("%s", p);

    int length = strlen(s);
    for(int i = 0; i < length; i++){
        s[i + length] = s[i];
    }

    string s_str = s;//translate char to string
    string p_str = p;

    if(s_str.find(p_str) != string::npos){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}