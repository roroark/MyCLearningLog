My C Learning Log<br>
This repository contains the things I did when learning C.

I have worked on the following micro projects:<br>
1. Next Permutation of a string: source/nextp.c<br>
2. An executable "sysc" that executes its command-line arguments: source/sysc.c<br>
3. Modify "sysc" to "timex" to time the execution (using clock_t clock()): source/timex.c<br>
4. Implement C's time seeded pseudo random number generator that accepts an optional command line argument to generate n random numbers: source/rand.c<br>
5. Modify "timex" to "avtex" to time the execution n times, specified by the argument immediately after the -n flag [10 default]. Additionally, if the -s flag is provided (before executions) the output of individual executions will be redirected to /dev/null: source/avtex.c<br>
6. Modify "rand" to first output the count of the command-line arguments if the -i flag is set. Pipe this output to "sort" which accepts an optional (single) flag that specifies which sort is carried out (-q: QuickSort, -h: HeapSort, -m: MergeSort, -i: InsertionSort): source/sort.c<br>


<!-- Variadic and Callback Functions [Under Construction]
4. Timing various sorts on Random Input [Scheduled]
5. Multithreaded Merge Sort [Scheduled]
6. Google Search API [Scheduled] -->
