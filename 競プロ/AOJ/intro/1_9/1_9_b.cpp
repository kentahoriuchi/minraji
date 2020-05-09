#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char str[200];
    char str2[10][200];
    int shuffle;
    int h;
    int length;
    int count = 0;
    while(1){
        scanf("%s", str);
        //printf("%lu\n", strlen(str));
        if(strlen(str) == 1 and str[0] == '-'){
            break;
        }
        else{
            scanf("%d", &shuffle);
            count++;
            length = strlen(str);
            //printf("length %d\n", length);
            for(int i = 0; i < shuffle; i++){
                scanf("%d", &h);
                char front[h];
                char back[length - h];

                for(int j = 0; j < h; j++){
                    front[j] = str[j];
                }
                for(int j = 0; j < length - h; j++){
                    back[j] = str[h + j];
                }

                for(int j = 0; j < length; j++){
                    if(j < length - h){
                        str[j] = back[j];
                    }
                    else{
                        str[j] = front[j - length + h];
                    }
                }
                //printf("fron %s\n", front);
                //printf("back %s\n", back);

                //printf("str %s\n", str);

                /*
                strncpy(front, str, h);
                printf("fron %s\n", front);
                printf("length - h %d\n", length - h);
                strncpy(back, &str[h], length - h);
                printf("back %s\n", back);
                strcat(back, front);
                strcpy(str, back);
                printf("str %s\n", str);
                */
            }
            //printf("%s\n", str);
            strcpy(str2[count - 1], str);

        }
    }

    for(int i = 0; i < count; i++){
        printf("%s\n", str2[i]);
    }
    return 0;
}

