# Data Structures Lab — Singly Linked List (C)

## General rules
- Each question is a standalone C file. Use the C11 standard.
- Complete only the function bodies marked with TODO. The struct definition, memory allocation, printing, list cleanup, and main are already provided.
- `head` points to the first node; an empty list is represented by `NULL`. The `next` field of the last node must be `NULL`.
- Do not use global variables, convert the list to an array, or use a ready-made list library.
- The function bodies in the starter files are intentionally empty; do not run them before completing the functions. In particular, empty functions that return a value do not produce a valid result.
- The provided main functions are sample scenarios; your solution must work for any integer values and any list length.

## Question 1 — Appending to the end and counting nodes (Easy)
Complete the `append` and `countNodes` functions in `01_append_count.c`.

1. `append(Node **head, int value)` must add a new node to the end of the list. It must also support appending to an empty list. `createNode` is already provided.
2. `countNodes(const Node *head)` must return the number of nodes in the list. For an empty list the result must be 0. It must not modify the list.

Example: Appending 10, 20, 30 in order to an empty list gives `10 -> 20 -> 30 -> NULL`; the node count is 3.

## Question 2 — Finding the position of the first match (Easy)
Complete the `findFirst(const Node *head, int target)` function in `02_search.c`.

Return the position where the target value first appears. The position of the first node is 0. If the value is not found or the list is empty, return -1. Do not modify the list.

Example: For `10 -> 20 -> 30 -> 20 -> NULL`, searching for 20 must return 1, and searching for 99 must return -1. For repeated values, the first match is taken.

## Question 3 — Deleting the first matching node (Medium)
Complete the `deleteFirst(Node **head, int target)` function in `03_delete_first.c`.

Delete only the first node that holds the target value. Release the deleted node's memory with `free`. Return 1 if a deletion happens, or 0 if the value is not found. If the head node is deleted, `head` must be updated. Empty lists, single-node lists, head/middle/tail nodes, and repeated values must all be handled correctly.

Example: Deleting 20 from `10 -> 20 -> 30 -> 20 -> NULL` gives `10 -> 30 -> 20 -> NULL` and returns 1. Trying to delete 99, which is not in the list, leaves the list unchanged and returns 0.

## Question 4 — Reversing the list in place (Medium)
Complete the `reverseList(Node **head)` function in `04_reverse.c`.

Reverse the list by changing the direction of the links, and update the head pointer. Do not create new nodes, do not change node data, and do not use arrays or recursion. Extra space must be O(1). Empty and single-node lists must also work.

Example: Reversing `10 -> 20 -> 30 -> 40 -> NULL` gives `40 -> 30 -> 20 -> 10 -> NULL`. Reversing it a second time must restore the original order.

## Building and running
Compile the file you completed (for example, question 1) in the terminal:

```sh
gcc -std=c11 -Wall -Wextra student/01_append_count.c -o question1
./question1
```

In Windows PowerShell, the run command is `.\question1.exe` (use `-o question1.exe` when compiling).
