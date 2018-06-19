#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  if(A[x] >= k) return 1;   //A[x]>=k なので1を返す
  return 0;                 //そうでない場合は0を返す
}

int main(){
  int i, lb, ub;

  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;                   //ぜったいp(lb)=0になる初期値
  ub = n-1;                 //ぜったいp(ub)=1になる初期値
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
