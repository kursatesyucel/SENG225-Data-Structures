C Pointers – Obsidian Lecture Package

Contents
--------
1. C_Pointers_Data_Structures_English_Obsidian.md
   - Clean Obsidian-compatible Markdown
   - Mermaid code blocks use standard ```mermaid fences
   - Examples are numbered 01–30
   - Each numbered example references its matching .c file

2. examples/
   - 30 standalone C source files for live classroom execution

Suggested compile command
-------------------------
gcc examples/01_address_operator.c -o ex01

Linux/macOS:
./ex01

Windows PowerShell:
.\ex01.exe

Recommended compiler flags for teaching
---------------------------------------
gcc -std=c11 -Wall -Wextra -Wpedantic examples/01_address_operator.c -o ex01

Obsidian
--------
Open the Markdown file in Live Preview or Reading View to render Mermaid diagrams.


Additional compiler demonstration
---------------------------------
examples/31_compiler_pipeline_demo.c

Useful GCC stages:
gcc -E examples/31_compiler_pipeline_demo.c -o compiler_demo.i
gcc -S examples/31_compiler_pipeline_demo.c -o compiler_demo.s
gcc -c examples/31_compiler_pipeline_demo.c -o compiler_demo.o
gcc compiler_demo.o -o compiler_demo

The lecture note now also includes:
- compiler / interpreter distinction
- preprocessing, compilation, assembly, and linking
- function declarations vs definitions
- why a function prototype appears before use
- call-stack / stack-frame conceptual model
- why C parameters receive copied values
- why passing a pointer is still pass-by-value
- object lifetime and invalid pointers
