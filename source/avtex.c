#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define and &&
#define or ||
#define CLOCK_TO_MILI 1000
#define CHARLIMIT 200
void print_usage(void) {
  printf(
  "Usage: avtex [flags] executable_name [command line args]\n"
  "Flags:\n"
  "\t-s : Surpress Individual Execution Output. Input not Surpressed.\n"
  "\t-n : The next argument is an integer representing the number of \n"
  "\t     executions to perform.\n"
  );
}
int FLAG_SURPRESS_OUTPUT, FLAG_CUSTOM_ITERATION, CUSTOM_COUNT_TAKEN;
int main(int argc, char *argv[]) {
  int iteration_count = 10;

  if (argc == 1) print_usage();
  else {
    //Check for supplied flags:
    int flagsize, str_length(char *);
    char flag;
    while (--argc && (*++argv)[0] == '-') {
      //Flag Supplied.
      //Go to next letter in the flag string
      *argv += 1;
      flagsize = str_length(*argv) + 1;
      //Only minus sign was provided
      if (flagsize == 1) {
        print_usage();
        return -1;
      }
      while (--flagsize) {
        flag = **argv;
        switch(flag) {
          case 's':
            if (!FLAG_SURPRESS_OUTPUT) {
              FLAG_SURPRESS_OUTPUT = 1;
            } else {
              print_usage();
              return -1;
            }
            break;
          case 'n':
            if (!FLAG_CUSTOM_ITERATION) {
              FLAG_CUSTOM_ITERATION = 1;
            } else {
              print_usage();
              return -1;
            }
            break;
          default:
            print_usage();
            return -1;
            //Future Proof
            break;
        }
        //Go to next letter in same flag
        *argv += 1;
      }
      if (FLAG_CUSTOM_ITERATION and !CUSTOM_COUNT_TAKEN) {
        //Take the next argument as  custom Input
        if (!(--argc) or !(iteration_count = atoi(*++argv))) {
          print_usage();
          return -1;
        }
        CUSTOM_COUNT_TAKEN = 1;
      }
    }
    if (argc) --argv, ++argc;
    // printf("Custom: %d Surpress: %d\n", FLAG_CUSTOM_ITERATION, FLAG_SURPRESS_OUTPUT);
    // if (CUSTOM_COUNT_TAKEN) printf("Custom Iteration Count: %d\n", iteration_count);

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
        return -1;
      }
      str_copy_at(*argv, command, currentBufferLength);
      str_copy_at(space, command,  currentBufferLength + currentArgumentLength);
      currentBufferLength += currentArgumentLength + 1;
    }
    //Remove last space
    --currentBufferLength;
    command[currentBufferLength] = '\0';

    char surpress[] = " > /dev/null";
    if (FLAG_SURPRESS_OUTPUT) {
      int extra = str_length(surpress);
      if (currentBufferLength + extra > 200) {
        printf("Error: Command should have less than %d characters.\n", CHARLIMIT);
        return -1;
      }
      void str_append(char * source, char * destination);
      str_append(surpress, command);
      currentBufferLength += extra;
    }
    printf("avtex: executing \"%s\" %d times.\n", command, iteration_count);
    double *iteration_results = (double *) malloc(sizeof(double) * iteration_count);
    for (int i=0; i<iteration_count; ++i) {
      clock_t clock(void);
      clock_t initClock = clock();
      int failedToExecute = system(command);
      clock_t finalClock = clock();
      if (!failedToExecute) {
        clock_t delta = finalClock - initClock;
        iteration_results[i] = ((double)delta)/CLOCK_TO_MILI;
        printf("avtex: execution %d took: %.4f ms\n", i+1,  iteration_results[i]);
      }
      else return failedToExecute;
    }
    double sum(double *, long), average(double *, long), stdev(double *, long);
    //Results
    printf(
      "\n"
      "avtex: total execution time       : %.4f ms\n"
      "avtex: average execution time     : %.4f ms\n"
      "avtex: deviation in execution time: %.4f ms\n"
      "\n"
      ,
      sum (iteration_results, iteration_count),
      average(iteration_results, iteration_count),
      stdev(iteration_results, iteration_count)

  );
  }
}
