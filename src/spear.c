#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int i = 0, j = 0;

  while(i < n){       //nほんの棒がある
    j+=A[i]/x;        //ながさA[i]の棒からながさxのやりが採れます
    i++;
  }
  printf("j = %d (x=%d)\n", j, x);
  if(j>=k) return 0;   //結局k本採れたのか?
  return 1;            //とれなかった...
}

int main(){
  int i, lb, ub;

  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;              //ぜったいp(lb)=0になる初期値
  ub = 1000000001;     //ぜったいp(ub)=1になる初期値
  while(ub - lb > 1){
    int m = (lb + ub) / 2;
    if(p(m)){
      ub = m;
    }
    else{
      lb = m;
    }
  }
  printf("lb:%d\nub:%d\n", lb, ub);
  printf("%d\n", lb);
  return 0;
}
