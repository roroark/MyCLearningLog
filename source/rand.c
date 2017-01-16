#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]) {
  if (argc >2) {
    printf("Usage: rand [, count]\n");
  } else {
    int count = 0;
    if (argc == 2) count = atoi(argv[1]);
    if (count == 0) count = 1;
    srand(time(NULL));
    //Get rid of the first not so random number
    rand();
    while (count--) {
      printf("%.6f\n", ((double) rand()) / RAND_MAX);
    }
  }
  return 0;
}
