*This project has been created as part of the 42 curriculum by icezar-s*

# Push\_swap

## Description
The `push_swap` project is a highly structured algorithmic challenge that introduces the concept of computational complexity and data sorting.

The goal of this project is to write a C program called 'push\_swap'that calculates and displays the shortest possible sequence of operations needed to sort a random set of integers in ascending order.

We are provided with two stacks (Stack A and Stack B) and a limited set of instructions (pushes, swaps, rotates, and reverse rotates) to manipulate the data.

## Implementation Details
To optimize performance and minimize the number of operations, this implementation utilizes a custom data structure and a combination of algorithms based on the input size:
* **Circular Stack-Within-A-Queue Architecture**: Under the hood, Stacks A and B are implemented using a circular queue (`t_queue`). This allows for a highly efficient rotation ('ra', 'rb') and reverse rotation ('rra', 'rrb') operations without the need to continuously shift large arrays in memory.
* **Data Normalization (Numbers to Ranks)**: Before sorting begins, the input integers are parsed and mapped to their respective "ranks" (from `0` to `n-1`). This is aimed as a simplification of the core sorting logic, as well as minimizing processing of large sums, as the algorithm only need to handle a continuous sequence of natural numbers.
* **Small Stacks**:
	* Inputs of $\le 3$ elements are sorted using a hardcoded, highly optimized algorithm (`juggler_3`).
	* Inputs of $\le 5$ elements are sorted using `juggler_5`, which splits the numbers between the stacks and applies `juggler_3`
* **Large Stacks**: For datasets larger than 5 elements, the program executes a custom **Buttefly Sort**. It pushes numbers from Stack A to Stack B in calculated chunks/ranges, creating a butterfly-like distribution. It then finds the maximum value in Stack B and strategically pushes it back to Stack A, efficiently sorting the list in minimal operations (500 elements in circa 4900 operations).

## Instructions

### Compilation
A `Makefile` is provided to compile the source files. The project strictly complies with the 42 Norm, and compiles with the standard `-Wall`, `-Wextra` and `-Werror` flags. Post-compilation, a strict analysis with `Valgrind` prompts no error or memory leaks.

To compile it, run:

```Bash
make
```

This will generate the `push_swap` binary executable.

To clean the object files and the executable, you can use:

```Bash
make clean
make fclean
make re
```

### Execution
Run the program by passing a list of integers as arguments. The first argument will be positioned at the top of Stack A. You can provide the numbers as separate arguments or as a single formatted string:

```Bash
#Executing with separate arguments:
./push_swap 5 6 1 3 2 4

#Executing with a single string:
./push_swap "5 6 1 3 2 4"
```
The program will output the shortest sequence of instructions needed to sort the stack, with each instruction separated by a newline (`\n`).

### Error Handling
* If no parameters are specified, the program displays nothing and returns to the prompt.
* In case of invalid input (e.g., non-integers, duplicate numbers, or numbers exceeding the standard integer limits), the program safely frees all allocated memory and displays `Error` on the stderror.

# Resources

### AI Usage
Artificial Intelligence (Google's Gemini and Anthropic's Claude) were utilized during the development of this project strictly as a debugging assistant and for peer-reviewing code blocks.

Specifically, AI helped with:

* Identifying and fixing logic errors within the `butterfly_sort` implementation (correcting dynamic max-value caching during stack rotations).
* Resolving invalid memory reads flagged by Valgrind in the argument parsing loop by addressing C's short-circuit evaluation order.
* Fixing 0-based indexing calculations for the custom circular queue array implementation.

### Articles and Data Structure Studies
As of implementing this program, I've come to write a few articles on sorting algorithms and data structures.

* [Articles in Sorting Algorithms](https://www.notion.so/Sorting-Algorithms-2eaeda9fb48a8082b0f9ef1ca1bd6121?source=copy_link)

Those were all inspired by the books:

* Algorithms in C, by Robert Sedgewick
* Data Structures Using C, by Reema Thareja

The Butterfly Sorting is a custom sorting algorithm, an extrapolation of the principles behind Bubble Sort and Bucket Sort (mainly the latter). This algorithm in specific was achieved through experimentation and was heavily contributed by Luis Paiva

Its efficient in this context is particularly neat due to the custom data structure. 

On Data Structures, I've wroted the article:

* [Article on Stacks](https://www.notion.so/Stacks-2f3eda9fb48a8008b284c18a1acdf124?source=copy_link)

But i was heavily inspired by the [LeetCode Problem 225](https://leetcode.com/problems/implement-stack-using-queues/description/). The array that is forced to be implemented as one of the most optimal solutions to this problem gave me an excellent idea as to how I'd implement a stack for the `push_swap` problem. 

### Acknowledgements
This project would not be possible without Luis Paiva's and Bruno Ramalho's contribution as peer-reviewers and supporters. 

A huge thanks to Kleyton Filho, Daniel Fonseca, Maria Paula, Thiago Cesar.

This is dedicated to my son Demian Asso, my mother, my father and my brother.
