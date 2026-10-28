Assignment 02 - Readme
Data Structures

----------------------------------------------------------------
1. Files
----------------------------------------------------------------
- Assignment02_code1_[StudentID]_[Name].cpp
  Problem 1. Linked stack re-implemented with a circular doubly
  linked list (with a head node). Functions: init, is_empty, push,
  pop, peek.

- Assignment02_code2_[StudentID]_[Name].cpp
  Problem 2. Finding the inorder successor of a node in a binary
  tree using parent pointers (tree_successor).

- Assignment02_code3_[StudentID]_[Name].cpp
  Problem 3. Deletion in a binary search tree. Case 3 (a node with
  two children) is revised to use the inorder predecessor in the
  left subtree instead of the successor in the right subtree.

- Assignment02_technical_report_[StudentID]_[Name].pdf
  Explanation of the code and the experimental results.

----------------------------------------------------------------
2. How to compile and run
----------------------------------------------------------------
The code is written in C++ and uses only standard C libraries
(stdio.h, stdlib.h, string.h). No additional files are needed.

[g++ (MinGW / MSYS2 / Linux / macOS)]
  g++ Assignment02_code1_[StudentID]_[Name].cpp -o code1
  ./code1            (Windows: code1.exe)

  g++ Assignment02_code2_[StudentID]_[Name].cpp -o code2
  ./code2            (Windows: code2.exe)

  g++ Assignment02_code3_[StudentID]_[Name].cpp -o code3
  ./code3            (Windows: code3.exe)

[Visual Studio]
  Create an empty C++ console project, add one .cpp file,
  and run it (Ctrl + F5).

----------------------------------------------------------------
3. Expected output
----------------------------------------------------------------
- code1: pushes 1, 2, 3 and pops three times.
    3
    2
    1

- code2: prints the nodes in inorder by calling tree_successor
  repeatedly from the leftmost node.
    A C B G D F E   (one per line)

- code3: prints the tree in inorder before and after deletion.
  Original tree (inorder):
    3 7 10 12 18 22 24 26 30 35 68 99
  After deletion, the deleted key disappears and the remaining
  keys stay in ascending order (same result as the original code).

----------------------------------------------------------------
4. How to adjust parameters (code3)
----------------------------------------------------------------
The key to be deleted is the second argument of delete_node()
in main():

    delete_node(&root, 18);

Change this value to 18, 35, or 7 to test the three examples
in the assignment, then compile and run again.
