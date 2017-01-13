#include<stdio.h>
int main (int argc, char *argv[]) {
  void nextp(char *), strrev(char *);
  if (argc == 1)
    printf("Usage: nextp String1 String2 ...\n");
  else {
    while (--argc) {
      printf("Entered Permutation: %s\n", *++argv);
      strrev(*argv);
      printf("Next Permutation: %s\n", *argv);
    }
  }
}
void nextp(char *input) {
  //12:3,45 -> 123,54 -> 12435 -> 12453 -> 12534 -> 12,543
  // starting from the right, at any index, if terms on right are in decreasing order, involve the next term.
  // if still in decreasing order, keep involving next terms
  // if not, sort the terms on the right in increasing order and keep shifting our guy right until in

}
