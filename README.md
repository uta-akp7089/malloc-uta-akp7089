[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/0hZ6CpRd)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10681920)

# malloc Assignment

## Description

In this assignment you will build your own implementation of malloc and free. That is, you will need to implement a library that interacts with the operating system to perform heap management on behalf of a user process as demonstrated in class. The code you submit for this assignment will be verified against a database consisting of kernel source, github code, stackoverflow, previous student’s submissions and other internet resources. Code that is not 100% your own code will result in a grade of 0 and referral to the Office of Student Conduct. This project must be completed, in C, on a course Codespace.

## Building and Running the Code

The code compiles into four shared libraries and six test programs. To build the code, change to your top level assignment directory and type:
```
make
```
Once you have the library, you can use it to override the existing malloc by using
LD_PRELOAD. The following example shows running the ffnf test using the First Fit shared library:
```
$ env LD_PRELOAD=lib/libmalloc-ff.so tests/ffnf
```

To run the other heap management schemes replace libmalloc-ff.so with the appropriate library:
```
Best-Fit: libmalloc-bf.so
First-Fit: libmalloc-ff.so
Next-Fit: libmalloc-nf.so
Worst-Fit: libmalloc-wf.so
```
## Program Requirements

Using the framework of malloc and free provided on the course github repository:
1. Implement splitting and coalescing of free blocks. If two free blocks are adjacent then
combine them. If a free block is larger than the requested size then split the block into two.
2. Implement three additional heap management strategies: Next Fit, Worst Fit, Best Fit (First
Fit has already been implemented for you).
3. Counters exist in the code for tracking of the following events:

* Number of times the user calls malloc successfully
* Number of times the user calls free successfully
* Number of times we reuse an existing block
* Number of times we request a new block
* Number of times we split a block
* Number of times we coalesce blocks
* Number blocks in free list
* Total amount of memory requested
* Maximum size of the heap

The code will print the statistics ( THESE STATS ARE FAKE) upon exit and should look like similar to:
```
mallocs: 8
frees: 8
reuses: 1
grows: 5
splits: 1
coalesces: 1
blocks: 5
requested: 7298
max heap: 4096
```

You will need to increment these counters where appropriate.

4. Eight test programs are provided to help debug your code. They are located in the tests
directory.
5. Implement realloc and calloc.

6. You must also benchmark your four implementations of an allocator against the standard system call malloc(). Design and develop a suite of programs and capture execution time for your four implementations of the arena allocator and compare their performance against the same programs using malloc(). At a minimum your suite of tests must evaluate the programs based on:
* Performance
* Relative comparision of number of splits and heap growth
* Heap fragmentation
* Max heap size
7. A report must be generated with the findings.  At a minimum the report must contain:
* Executive summary
* Description of the algorithms implemented.
* Test implementation
* Test results for all five candidates ( malloc and your four algorithm implementations )
* Explanation and interpretation of the results including any anomalies in the test results.
* Conclusion.
The report must be submitted as a PDF file.  Any other formats will result in a grade of 0 for the report.
The rubric for grading your report is contained within the rubric directory.

## Important Warning
This program involves a lot of pointers and pointer arithmetic. You will seg fault your code if you are not careful with your pointers. Verify ALL pointers pointers before you
dereference them.
```
Bad: if ( ptr -> next )
Good: if( ptr && ptr->next )
```
You will need to use gdb to find and fix your pointers errors

## Debugging
While running the tests, you may encounter some segfaults and other memory errors. Because we are side-loading our own malloc implementation, you will need to do the following to debug a test application using gdb.
```
$ gdb ./tests/ffnf
...
(gdb) set exec-wrapper env LD_PRELOAD=./lib/libmalloc-ff.so
(gdb) run
...
(gdb) where
```
Basically, you want to first load gdb with the test program that is crashing. Next, you need to tell gdb to utilize the appropriate malloc library by creating an exec-wrapper that loads it into memory. Next, simply run the program. Once it segfaults, you can print a stack trace by using the where command. From there, you can explore the state of your program and see if you can determine what went wrong.

## How to submit code and report.

1. Your program source code and report are to be turned in via the Feedback GitHub pull request. **Do not merge this pull request**.  Submission time is determined by the GitHub system time. You may push your code as often as you wish. Only your last submission will be graded.  

## Administrative

This assignment must be coded in C. Any other language will result in 0 points. Your programs will be compiled and graded on the course GitHub Codespace. Code that does not compile with the provided makefile will result in a 0.

There are coding resources and working code you may use in the course GitHub repositories.  You are free to use any of that code in your program if needed. You may use no other outside code.

## Academic Integrity
This assignment must be 100% your own work. No code may be copied from friends,  previous students, books, web pages, etc. All code submitted is automatically checked 
against a database of previous semester’s graded assignments, current student’s code and common web sources. By submitting your code on GitHub you are attesting that 
you have neither given nor received unauthorized assistance on this work. Code that is copied from an external source or used as inspiration, excluding the 
course github, will result in a 0 for the assignment and referral to the Office of Student Conduct.
