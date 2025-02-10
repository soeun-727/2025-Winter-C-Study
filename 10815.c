#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, M;
    scanf("%d", &N);
    
    int *arr1 = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }

    qsort(arr1, N, sizeof(int), compare);

    scanf("%d", &M);
    
    int *result = (int *)malloc(M * sizeof(int));

    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);
        
        if (bsearch(&target, arr1, N, sizeof(int), compare)) {
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        printf("%d ", result[i]);
    }

    free(arr1);
    free(result);
    return 0;
}
