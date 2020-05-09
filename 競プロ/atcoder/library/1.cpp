#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/* 累積和
int n;
int a[n];

for(int i = 0; i < n; i++){
    a[i] = i;
}

 //aのi番目までの総和を求める
vector<long> S(N + 1, 0);
for(int i = 0; i < N; i++){
    S[i + 1] = S[i] + a[i];
}
//leftからright番目の和は
S[right] - S[left]
*/

//最大公約数
int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

//最小公倍数
int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}



#include <functional>
#include <iostream>

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
  foreach_comb(5, 3, [](int *indexes) {
    std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
  });
}

//文字の数字をint型の数字に変換する
int ctoi(const char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

/*
//bit全探索
i < (1 << n)が2のn乗

for(int i = 0; i < (1 << n); i++){
  if(i & (1 << j)){
    
  }
}
*/