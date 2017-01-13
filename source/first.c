#include<stdio.h>
int main(int argc, char *argv[]) {
  printf("%d\n", argc);
  printf("Command Line Arguments Received:\n");
  for (int i=0; i<argc; i++) {
    printf("%s\n", argv[i]);
  }
}
