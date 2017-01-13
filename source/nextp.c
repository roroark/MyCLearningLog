#include<stdio.h>
int main (int argc, char *argv[]) {
  void nextp(char *);
  if (argc == 1)
    printf("Usage: nextp String1 String2 ...\n");
  else {
    while (--argc) {
      //Debug
      //Part 1.
      // printf("Entered Permutation: %s\n", *++argv);
      nextp(*++argv);
      //Part 2.
      printf("%s\n", *argv);
    }
  }
}

void nextp(char *input) {
  //12:3,45 -> 123,54 -> 12435 -> 12453 -> 12534 -> 12,543
  //Find the first non-decreasing term from the right
  int strlen(char *), length = strlen(input);
  int lengthIndex1 = length, lengthIndex2 = length;
  //Reduce Length to appropriate size
  for (--lengthIndex1; lengthIndex1 > 0 && input[lengthIndex1-1] >= input[lengthIndex1]; --lengthIndex1);
  //If next permutation is possible:
  if (lengthIndex1 > 0) {
    //Find the first term from the right that is greater than this term
    for (--lengthIndex2; input[lengthIndex2] <= input[lengthIndex1-1]; --lengthIndex2);
    //No safety measures needed for lengthIndex2 as it enters this if statement
    //only if a next permutation is possible.

    //Swap these terms (Note the decreasing order is preserved)
    //Invert or sort the decreasing terms
    void swapchar(char *, char *), strrev(char *);
    swapchar(input + lengthIndex1 - 1, input + lengthIndex2);
    strrev(input + lengthIndex1);
  } else {
    printf("%s is the last permutation.", input);
    //Make it so that the printf statement in main can't print %s as it is an
    //empty string.
    input[0]='\0';
  }
}
