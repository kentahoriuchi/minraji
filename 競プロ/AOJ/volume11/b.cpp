#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int c[50][50];
bool visited[50][50] = {false};
int w, h;


void search(int x, int y){
    if(x < 0 || x >= w || y < 0 || y >= h || c[y][x] == 0){
        return;
    }
    if(visited[y][x] == true){
        return;
    }

    visited[y][x] = true;

    search(x-1, y);
    search(x+1, y);
    search(x, y-1);
    search(x, y+1);
    search(x+1, y+1);
    search(x+1, y-1);
    search(x-1, y+1);
    search(x-1, y-1);
}

void init(){
    for(int y = 0; y < 50; y++){
        for(int x = 0; x < 50; x++){
            visited[y][x] = false;
        }
    }
}


int main(){
    int count;
    int n = 0;
    vector<int> ans;

    while(1){
        cin >> w >> h;

        if(w == 0 and h == 0){
            break;
        }

        n++;
        count = 0;

        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                cin >> c[y][x];
            }
        }

        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                if(c[y][x] == 1 and visited[y][x] == false){
                    search(x, y);
                    count++;
                }
            }
        }

        ans.push_back(count);
        
        init();
    }

    for(int j = 0; j < n; j++){
        printf("%d\n", ans[j]);
    }

    return 0;

}