#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main(){
    char com[20];

    int x;

    priority_queue<int> PQ;

    while(1){
        scanf("%s", com);
        if(com[0] == 'i'){
            cin >> x;
            PQ.push(x);
        }
        else if(com[0] == 'e' and com[1] == 'x'){
            printf("%d\n", PQ.top());
            PQ.pop();
        }
        else{
            break;
        }
    }

    return 0;
}