Assignment 01 - README
======================

1. Overview
-----------
This archive contains three C programs for Assignment 01 (Data Structures).

  Assignment01_code1_STUDENTID_NAME.c
      Problem 1. Transpose of a sparse matrix stored as non-zero elements
      (row, column, value) in a row-wise manner. The transposed matrix is
      also stored in a row-wise manner. The program prints B and B^T in
      dense matrix form to verify the result.

  Assignment01_code2_STUDENTID_NAME.c
      Problem 2. Merging two linked lists a and b, each sorted in ascending
      order, into one linked list c sorted in ascending order.
      Example input: a = {1,2,5,10,15,20,25}, b = {3,7,8,15,18,30}

  Assignment01_code3_STUDENTID_NAME.c
      Problem 3. List ADT implemented with a linked list whose header
      (ListType) keeps head, tail and length. Implements init, is_empty,
      get_length, get_node_at, add, delete, get_entry, display, is_in_list,
      add_first, add_last, delete_first and delete_last, and runs the example
      main code given in the assignment.


2. Requirements
---------------
  - Language : C
  - Compiler : gcc (e.g. MinGW-w64 gcc on Windows, or gcc on Linux/macOS)
  - No external libraries are needed (only stdio.h and stdlib.h).

  NOTE: Please compile with gcc (C compiler), not g++.
        Problem 3 defines a function named "delete" as required by the
        assignment, and "delete" is a reserved keyword in C++.


3. How to compile and run
-------------------------
Open a terminal in the folder that contains the source files.

  [Problem 1]
    gcc Assignment01_code1_2466051_JungDain.c -o code1
    ./code1            (Windows: .\code1.exe)

  [Problem 2]
    gcc Assignment01_code2_2466051_JungDain.c -o code2
    ./code2            (Windows: .\code2.exe)

  [Problem 3]
    gcc Assignment01_code3_2466051_JungDain.c -o code3
    ./code3            (Windows: .\code3.exe)


4. Parameters
-------------
No command-line arguments are required.
All input data are written in the main() function of each file.
To test other inputs, edit the arrays / function calls in main() and
compile again.


5. Expected output (Problem 3)
------------------------------
  ( 10 20 70 30 40  )
  ( 20 30  )
  TRUE
  20