SENG 225 - Data Structures and Algorithms | C Lab Examples

FILES
01_pointer_swap.c            Pointer-based swap
02_reverse_array.c          Reverse an array in-place with pointers
03_student_struct.c         Array of structs and the -> operator
04_linked_list_basics.c     Allocate, append, traverse, free
05_linked_list_insert_delete.c  Prepend and delete first matching node
06_student_exercises.c     Four student TODO functions (intentionally incomplete)
07_exercise_solutions.c    Instructor reference implementations with assertions

BUILD & RUN (GCC or Clang, terminal in this directory)
  gcc -std=c11 -Wall -Wextra -pedantic 01_pointer_swap.c -o example01
  ./example01
On Windows PowerShell, run .\example01.exe after compilation.
To compile a different example, replace the input filename and output name.

Compile all programs with GCC (Bash):
  for f in *.c; do gcc -std=c11 -Wall -Wextra -pedantic "$f" -o "${f%.c}"; done

Use AddressSanitizer where supported:
  gcc -std=c11 -g -fsanitize=address,undefined -fno-omit-frame-pointer 05_linked_list_insert_delete.c -o example05_asan

NOTES
- All .c files are standalone and each has its own main() function; compile each independently.
- Exercise starter is intentionally unfinished; it compiles but its results are placeholders.
- The instructor solution file should not be distributed before students attempt the exercises.
- findMax requires a non-empty list.
