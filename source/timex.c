#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CHARLIMIT 200
int main(int argc, char *argv[]) {
  if (argc == 1) printf("Usage: timex executable_name [command line args]\n");
  else {
    int str_length(char *);
    register int currentArgumentLength=0, currentBufferLength=0;
    void str_copy_at(char * source, char * destination, long offsetFromStart);
    char command[CHARLIMIT];
    char space[] = " ";
    while (--argc) {
      // Add space at the end.
      currentArgumentLength = str_length(*++argv);
      if (currentBufferLength + currentBufferLength > 200) {
        printf("Error: Command should have less than %d characters.\n", CHARLIMIT);
        return 2;
      }
      str_copy_at(*argv, command, currentBufferLength);
      str_copy_at(space, command,  currentBufferLength + currentArgumentLength);
      currentBufferLength += currentArgumentLength + 1;
    }
    //Remove last space
    command[currentBufferLength - 1] = '\0';
    printf("timex: executing \"%s\"\n", command);
    clock_t clock(void);
    clock_t initClock = clock();
    system(command);

    clock_t finalClock = clock();
    clock_t delta = finalClock - initClock;
    printf("timex: execution took: %.4f ms\n", ((double)delta)/1000);
    return 0;
  }
}
