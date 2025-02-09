#include <stdio.h>
#include <stdlib.h>

int main(){
  int N;
  long n =0;
  int M;
  long m = 0;
  
  
  scanf("%d\n", &N);
  long *arr1 = (long *)malloc(N*sizeof(long));
  for(int i=0; i<N; i++){
    scanf("%lu ", &n);
    arr1[i]=n;
  }

  scanf("%d\n", &M);
  long *arr2 = (long *)malloc(M*sizeof(long));
  for(int i = 0; i<M; i++){
    scanf( "%lu ", &m);
    arr2[i]= m;
  }

for (int i = 0; i < N; i++) {
  for (int j = 0; j < M; j++){
    if (arr1[i] == arr2[j]) {
        arr1[i] = 1;
        break;
    } else {
        continue;
    }
  }
  arr1[i] = 0;
}

  for (int i = 0; i<N;i++){
    printf("%lu ", arr1[i]);
  }

  free(arr1); free(arr2);
  return 0;
}
