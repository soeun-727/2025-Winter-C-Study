#include <stdio.h>

int main(){
  int N;
  long n =0;
  int M;
  long m = 0;
  
  
  scanf("%d\n", N);
  long arr1[] = N;
  for(int i=0; i<N; i++){
    scanf("%d ", n);
    arr1[i]=n;
  }

  scanf("%d\n", M);
  long arr2[] = M;
  for(int i = 0; i<M; i++){
    scanf( "%d ", m);
    arr2[i]= m;
  }

  for (int i = 0; i<N; i++){
    for(int j = o; j<M; J++){
      if( arr1[i] == arr2[j]){
        arr1[i] = 1;
      }
      else{
        arr1[i] = 0;
      }
    }
  }

  for (int i = 0; i<N;i++){
    printf("%d ", arr1[i]);
  }
}
