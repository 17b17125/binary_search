#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int i = 0,j=0,l=0;

  while(i < n){               //n人について話がすむまで繰り返します
    l+=A[i]/x;                //iさん一人で使った袋の数
    l+=A[i]%x?1:0;            //割り算して、あまりを入れる袋の分、切り上げ
    i++;                      //次の人の話に移ります
  }
  return l <= k;           //xこ入りで十分ならば真(非0)、不十分ならば偽(0)
}

int main(){
  int i, lb, ub;

  lb = 0;               //ぜったいp(lb)=0になる初期値
  ub = 1000000000;          //ぜったいp(ub)=1になる初期値
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
