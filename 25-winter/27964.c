#include <stdio.h>
#include <string.h>

int main(){
  int n;
  int pizza = 0;
  
  scanf("%d", &n);
  getchar();
  
  char arr[10100];
  fgets(arr, 10100, stdin);
  arr[strcspn(arr, "\n")] = 0;

  char *ptr = strtok(arr, " ");  
  while (ptr != NULL){          
  int len = strlen(ptr);
    if (ptr != NULL) {  
      int len = strlen(ptr);
      if (len >= 6 && strcmp(ptr + len - 6, "Cheese") == 0) {
        pizza++;
      }
    }
    ptr = strtok(NULL, " ");
  }
  
  printf(pizza >= 4 ? "yummy\n" : "sad\n");
  return 0;
}
