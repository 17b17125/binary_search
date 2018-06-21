#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int i=0,j=1,tmp=0;

  while(i < n){           //全ての仕事を分担し終えるまで繰り返す
    if(tmp + A[i] <= x){
      tmp+=A[i];          //まだ働いてもいいよ
    }else{
      j++;                //選手交代
      tmp = A[i];         //次の人の労働時間を数え始める
    }
    i++;
  }
  return j <= k;          //実在する人員に仕事の分担が収まったら真、人員不足の時は偽
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;                 //ぜったいp(lb)=0になる初期値
  ub = 1000000000;        //ぜったいp(ub)=1になる初期値
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
