#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int i = 0,j=0,l=0;

  while(i < n){        //n人について話がすむまで繰り返します
    while(x*j < A[i]){  //iさんはxこ入りの袋jこですみます
      j++;
    }
    l+=j;               //iさん一人で使った袋の数
    i++;                //次の人の話に移ります
  }
  if(l <= k){
    return 1;           //xこ入りで十分
  }else{
    return 0;           //xこ入りでは袋が足りない
  }
}

int main(){
  int i, lb, ub;

  lb = 0;               //ぜったいp(lb)=0になる初期値
  ub = 100001;          //ぜったいp(ub)=1になる初期値
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while(ub - lb > 1){
    int m = (lb + ub) / 2;
    if(p(m)){
      ub = m;
    }
    else{
      lb = m;
    }
  }
  printf("%d\n", ub);
  return 0;
}
