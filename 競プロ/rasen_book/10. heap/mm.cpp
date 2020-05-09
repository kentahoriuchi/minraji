#include <iostream>
#include <cstring>
using namespace std;
#define MAX 2000000
#define INFTY (1<<30)

int H, A[MAX+1];

void maxHeapify(int i){
    int left, right, largest;
    left = 2 * i;
    right = 2 * i + 1;

    if(left <= H && A[left] > A[i]){
        largest = left;
    }
    else{
        largest = i;
    }

    if(right <= H && A[right] > A[largest]){
        largest = right;
    }
    

    if(largest != i){
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int extract(){
    int maxv;
    if( H < 1){
        return - INFTY;
    }
    maxv = A[1];//最大値を取り出す
    A[1] = A[H];
    H--;
    maxHeapify(1);//ヒープを保つように整順

    return maxv;
}

void increaseKey(int i, int key){
    if(key < A[i]){
        return;
    }
    A[i] = key;
    while(i > 1 && A[i/2] < A[i]){
        swap(A[i/2], A[i]);
        i = i/2;
    }
}

void insert(int key){
    H++;
    A[H] = -INFTY;
    increaseKey(H, key);
}

int main(){
    //int H;
    char com[10];

    //cin >> H;
    H = 0;

    int key;

    
    while(1){
        scanf("%s", com);
        if(com[0] == 'i'){
            scanf("%d", &key);
            insert(key);
        }
        else if(com[0] == 'e' and com[1] == 'x'){
            printf("%d\n", extract());
        }
        else{
            break;
        }
    }

    return 0;
}