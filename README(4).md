# Prashant DSA — Detailed Program Guide

A collection of C++ programs for practising Data Structures and Algorithms (DSA), sorting, searching, linked lists, stacks, queues, binary trees, heaps, recursion, and basic mathematical problems.

> **Important:** This guide describes the behaviour of the source files in this repository. Some files have names that do not match their actual contents, and a few implementations have edge cases or bugs. Those are called out in the relevant sections so the explanation stays faithful to the code rather than describing an idealised version.

## Table of Contents

1. [Repository Overview](#repository-overview)
2. [Basic Problems and Arrays](#1-basic-problems-and-arrays)
3. [Sorting and Searching](#2-sorting-and-searching)
4. [Linked Lists](#3-linked-lists)
5. [Stacks](#4-stacks)
6. [Queues](#5-queues)
7. [Binary Trees, BSTs, AVL Trees, and Heaps](#6-binary-trees-bsts-avl-trees-and-heaps)
8. [Recursion](#7-recursion)
9. [Complexity Quick Reference](#complexity-quick-reference)
10. [Compile and Run](#compile-and-run)
11. [Suggested Improvements](#suggested-improvements)

---

# Repository Overview

The repository contains standalone C++ practice programs. Most `.cpp` files have their own `main()` function, so compile and run them separately rather than combining every file into one executable.

| File | Main topic |
|---|---|
| `numberoftips.cpp` | Repeatedly halve a speed until it is below a threshold |
| `findroot.cpp` | Classify roots of a quadratic equation |
| `projectilr.cpp` | Projectile motion calculations using a class |
| `insertion _in_arrayas_adt` | Insert/delete operations in an unsorted array |
| `zeroatlast.cpp` | Move zero values towards the end of an array |
| `firstduplicate.cpp` | Search for a repeated array value |
| `selectionsort.cpp` | Selection sort on an array |
| `insertionsort.cpp` | Insertion sort on an array |
| `mergesort.cpp` | Merge sort on an array |
| `quicksort2.cpp` | Quick sort on an array |
| `k_small.cpp` | Partition-based search related to the k-th/smallest values |
| `binsort.cpp` | Bin/frequency-based integer sorting |
| `bucketsort.cpp` | Bucket sort |
| `countsort.cpp` | **The current file implements a stack, not counting sort** |
| `heapsort.cpp` | Heap sort using an array representation of a heap |
| `radixsortusinglinklist.cpp` | Radix sort using linked-list buckets |
| `linklist.cpp` | Singly linked-list operations |
| `doublelinklist.cpp` | Doubly linked-list operations |
| `circularlinklist.cpp` | Circular singly linked list |
| `insertion_sortLL.cpp` | Insertion sort on a linked list |
| `selectionsortLL.cpp` | Selection sort on a linked list |
| `stackusingarray.cpp` | Stack implemented with an array |
| `stackusinglinklist.cpp` | Stack implemented with a singly linked list |
| `stackusingdoublelinklist` | Stack implemented with a doubly linked list |
| `queueusingarray.cpp` | Queue implemented with an array |
| `queueusinglinklist.cpp` | Despite its filename, the current code behaves like a linked-list stack |
| `queueusingdoublelinklist` | Queue implemented with a doubly linked list |
| `cqa.cpp` | Circular queue implemented with an array |
| `cqll.cpp`, `cicularqueuel.cpp`, `cicularqueueusinglinklist.cpp` | Circular queue implemented with a linked list |
| `binarytree.cpp` | Binary-tree creation, traversal, insertion, and deletion |
| `binary2.cpp` | Binary-tree height, sum, and node count |
| `BST.cpp` | Binary search tree insertion, deletion, and inorder traversal |
| `avl.cpp` | AVL tree operations through a menu |
| `binarytreeavl.cpp` | AVL insertion and traversals |
| `heapusinglinklist.cpp` | Complete binary tree built with a queue, then heap operations |
| `towerofhanoi.cpp` | Recursive Tower of Hanoi |
| `insertion _in_arrayas_adt` | Array ADT operations (insert at beginning/middle/end and delete) |

---

# 1. Basic Problems and Arrays

## 1.1 `numberoftips.cpp` — Repeatedly Halve a Speed

### Aim
Find how many times a ball's speed can be halved before it becomes smaller than or equal to `0.001`.

### Main logic
- The function `noOFTips(float speed)` receives the starting speed.
- `count` is initialised to `0`; it records the number of halvings.
- A `while` loop continues while `speed > 0.001`.
- During each iteration:
  1. Increment `count`.
  2. Divide `speed` by `2`.
- When the loop condition becomes false, print `count`.
- `main()` calls `noOFTips(30)`, so the starting speed is fixed at `30`; the program does not ask the user for input.

### Important concepts
- `while` loop
- Floating-point values
- Loop counters
- Stopping condition / threshold

### Complexity
If the initial speed is `s`, the number of iterations is proportional to `log₂(s / 0.001)`, when `s` is above the threshold. Extra space is `O(1)`.

---

## 1.2 `findroot.cpp` — Roots of a Quadratic Equation

### Aim
Determine whether the roots of `ax² + bx + c = 0` are real and equal, real and distinct, or imaginary.

### Formula
The discriminant is:

`d = b² - 4ac`

- `d == 0`: roots are real and equal.
- `d > 0`: roots are real and distinct.
- `d < 0`: roots are complex/imaginary.

### Working according to the code
- `findRoots(int a, int b, int c)` receives the three coefficients.
- It calculates `d = b*b - 4*a*c`.
- It calculates `x` and `y` using expressions containing `sqrt(d)`.
- If `d == 0`, it prints that both roots are equal.
- If `d > 0`, it prints the two distinct real roots.
- Otherwise, it prints that the roots are imaginary.
- `main()` calls `findRoots(1, 8, 12)`.

### Important code note
The current expressions are written as `(-b + sqrt(d))/2*a` and `(-b - sqrt(d))/2*a`. In C++, multiplication and division have equal precedence and are evaluated left-to-right, so these expressions do **not** implement division by `2*a` as intended. The standard formula should use `(-b + sqrt(d)) / (2.0*a)` and `(-b - sqrt(d)) / (2.0*a)`. Also, `sqrt(d)` is evaluated before the program checks whether `d` is negative. For a robust implementation, calculate the roots only in the appropriate discriminant branch and handle `a == 0`.

### Complexity
`O(1)` time and `O(1)` extra space.

---

## 1.3 `projectilr.cpp` — Projectile Motion

### Aim
Calculate the maximum height, horizontal range, and time of flight of a projectile launched with an initial velocity and angle.

### Input and class structure
- The `Projectile` class stores `theta` (launch angle in degrees), `u` (initial velocity), and `g = 9.8`.
- `getData()` asks the user to enter `theta` and `u`.
- Each calculation method converts the angle from degrees to radians before calling the trigonometric functions.

### Working in points
1. Create a `Projectile` object in `main()`.
2. Call `getData()` to read the angle and initial velocity.
3. `maxHeight()` calculates `u² sin²(theta) / (2g)`.
4. `horizontalRange()` calculates `u² sin(2theta) / g`.
5. `timeOfFlight()` calculates `2u sin(theta) / g`.
6. `display()` calls these methods and prints all three results.

### Concepts
- Classes and objects
- Private data members and public member functions
- Trigonometric functions from `<cmath>`
- Degree-to-radian conversion
- Returning calculated values from functions

### Assumptions
These standard formulas assume ideal projectile motion, constant gravity, no air resistance, and launch and landing at the same vertical level.

### Complexity
`O(1)` time and `O(1)` extra space.

---

## 1.4 `insertion _in_arrayas_adt` — Array ADT Operations

### Aim
Create an unsorted array and perform one selected operation: insert at the beginning, insert at a position, insert at the end, or delete a value.

### Working in points
- `unsortedADT(int n)` creates a local array and reads `n` elements from the user.
- The current array is printed before the operation menu.
- The user chooses one option through a `switch` statement.
- **Option 1 — insert at beginning:**
  1. Read the new value.
  2. Move existing elements one index to the right, starting from the end.
  3. Place the new value at `arr[0]`.
  4. Increase `n` and print the array.
- **Option 2 — insert at a position:**
  1. Read the new value and the index `pos`.
  2. Shift elements right while `i > pos`.
  3. Store the new value at `arr[pos]`.
  4. Increase `n` and print the array.
- **Option 3 — insert at end:**
  1. Read the new value.
  2. Store it at `arr[n]`.
  3. Increase `n` and print the array.
- **Option 4 — delete by value:**
  1. Read the value to delete.
  2. Search for its first occurrence.
  3. If found, shift later values one position left.
  4. Decrease `n`.
  5. Print the resulting array; if not found, print a message.

### Important code notes
- The program calls `unsortedADT(5)`, so it initially asks for five values.
- The array is declared with `int arr[n]`, a variable-length array. This is accepted by some compilers as an extension but is not standard C++.
- The code does not check whether `pos` is within a valid range or whether the array has spare capacity. Those checks should be added to prevent invalid access.
- Positions are zero-based: `0` means the beginning.

### Complexity
Insertion or deletion can take `O(n)` time because elements may need to shift. Searching for a value to delete is `O(n)`.

---

## 1.5 `zeroatlast.cpp` — Moving Zeros to the End

### Aim
Move zero values towards the end of an array.

### Working according to the current code
- `main()` creates the fixed array `{1, 0, 0, 4, 6, 3}` and calls `shiftZero(arr, 6)`.
- `shiftZero()` starts with `pos = -1`.
- The loop scans for zero values and updates `pos` when a zero is found.
- When `pos` is set, a nested loop shifts later elements one position left.
- The local logical length `n` is decreased after shifting.
- At the end, the code writes a zero at `arr[n]` and prints six values.

### Important code note
This is the current source's attempted approach, but the loop changes `n` while continuing to scan the array and can skip values or move elements incorrectly. The condition `pos == -1` is also checked inside the scanning loop. Therefore, this version should not be assumed to move every zero correctly for all inputs. A common reliable approach is to copy non-zero values forward and then fill the remaining positions with zeros.

### Complexity
The nested shifting approach can take `O(n²)` time in the worst case. Extra space is `O(1)`.

---

## 1.6 `firstduplicate.cpp` — Finding a Duplicate

### Aim
Read six integers and attempt to find a repeated value using nested loops.

### Working according to the source
- `main()` sets `n = 6` and creates an array of six integers.
- `findDuplicate()` calls `createArr()` to read the values.
- The outer loop selects `arr[i]`.
- The inner loop compares it with each later value `arr[j]`, starting at `i + 1`.
- When `arr[i] == arr[j]`, the value is printed and the inner loop stops.

### Important code note
There is a `break` after the inner loop that is placed inside the outer loop. As a result, the outer loop always stops after its **first iteration**, even if no duplicate was found for `arr[0]`. The program only compares the first array element with the elements after it. To find the first duplicate anywhere in the array, the outer loop must continue until a duplicate is found.

### Complexity
Nested comparisons are `O(n²)` in the general case, but the current misplaced `break` makes this particular implementation perform only the first outer-loop pass.

---

# 2. Sorting and Searching

## 2.1 `selectionsort.cpp` — Selection Sort on an Array

### Aim
Sort the predefined array in ascending order.

### Working in points
- `main()` creates an array of 10 integers.
- `selection(a, n)` starts the outer loop at index `0` and stops at `n - 2`.
- At the start of each pass, `smallestindex = i`.
- The inner loop checks every value from `i + 1` to `n - 1`.
- If a smaller value is found, `smallestindex` is updated.
- After the inner loop finishes, `swap(a[i], a[smallestindex])` puts the smallest remaining value at index `i`.
- Once all passes finish, `print()` displays the array.

### Key idea
The array is divided conceptually into a sorted prefix and an unsorted suffix. Each pass selects the smallest value from the suffix.

### Complexity
Best, average, and worst time: `O(n²)`. Extra space: `O(1)`.

### Code note
`print()` always prints 10 elements. That matches the current `main()`, but it would be better to pass `n` into `print()` so it can work with arrays of other sizes.

---

## 2.2 `insertionsort.cpp` — Insertion Sort on an Array

### Aim
Sort a predefined array in ascending order using insertion sort.

### Working in points
- The first element is treated as the initially sorted part.
- The outer loop begins at `i = 1`.
- `curent` stores the element currently being inserted.
- `prev = i - 1` points to the element immediately before it.
- While `prev >= 0` and `a[prev] > curent`, larger values are shifted to the right.
- The current value is placed into the correct position as the loop progresses.
- The process repeats for each remaining element.
- `print()` displays the final array.

### Key idea
Insertion sort grows a sorted portion from left to right, inserting each next value into its proper place.

### Complexity
- Best case: `O(n)` for already sorted data.
- Average and worst case: `O(n²)`.
- Extra space: `O(1)`.

### Code note
The code moves `curent` into `a[prev + 1]` during each shift. It works toward inserting the value, although the more common implementation shifts larger values and writes the key once after the loop.

---

## 2.3 `insertion_sortLL.cpp` — Insertion Sort on a Singly Linked List

### Aim
Sort a singly linked list in ascending order without converting it into an array.

### Structure
- `Node` stores `data` and a `next` pointer.
- `InsertionSort` maintains `head` and `tail`.
- `insert()` adds each new node at the beginning of the list.
- `printLL()` traverses from `head` to `NULL` and prints each node.

### Sorting procedure
1. Set `sorted = NULL`; this pointer represents the sorted list built so far.
2. Set `current = head` to process the original list.
3. Before changing any links, save `current->next` in `nextNode`.
4. If the sorted list is empty, or the current value belongs before its first node, link `current` at the beginning of `sorted`.
5. Otherwise, use a temporary pointer to find the insertion position in the sorted list.
6. Link `current` between the appropriate nodes.
7. Move to the saved `nextNode` and repeat.
8. When all original nodes have been processed, assign `head = sorted`.
9. Traverse the sorted list to update `tail`.

### Why save `nextNode`?
Inserting `current` changes its `next` pointer. Saving the original next node first ensures the program can continue processing the unsorted part.

### Complexity
Worst and average time: `O(n²)`. The algorithm rearranges links and uses `O(1)` extra pointer space, excluding the nodes already in the list.

---

## 2.4 `selectionsortLL.cpp` — Selection Sort on a Singly Linked List

### Aim
Sort linked-list values in ascending order using selection sort.

### Working in points
- The list is populated through calls to `insert()`. Each new node is inserted at the head, so the initial order is the reverse of insertion order.
- `current` marks the first node of the portion that still needs to be sorted.
- `minNode` initially points to `current`.
- `temp` scans the remaining nodes.
- Whenever `temp->data` is smaller than `minNode->data`, `minNode` is updated.
- After the scan, the data values in `current` and `minNode` are swapped if they are different nodes.
- `current` advances by one node.
- The process repeats until the end of the list.
- `main()` prints the list before and after sorting.

### Important distinction
This version swaps the **data values**, not the node links. The node order stays the same while the values are rearranged.

### Complexity
Time: `O(n²)`. Extra space: `O(1)`.

---

## 2.5 `mergesort.cpp` — Merge Sort

### Aim
Sort an array in ascending order using divide and conquer.

### `mergeSort()` working
- The function receives the array and a range `low` through `high`.
- If `low < high`, calculate `mid = (low + high) / 2`.
- Recursively sort the left half: `low` through `mid`.
- Recursively sort the right half: `mid + 1` through `high`.
- Call `merge()` to combine both sorted halves.

### `merge()` working
- `i` starts at the beginning of the left half.
- `j` starts at the beginning of the right half (`mid + 1`).
- `k` tracks the position to fill in temporary array `B`.
- Compare `A[i]` and `A[j]`; copy the smaller value to `B[k]`.
- Continue until one half is exhausted.
- Copy any remaining elements from either half into `B`.
- Copy the merged range from `B` back into `A`.

### Complexity
Time: `O(n log n)` in best, average, and worst cases. The temporary array uses `O(n)` space for the supported range.

### Code note
`B[100]` has a fixed capacity. The current implementation is not safe for arrays larger than that capacity. It also uses a strict `<` comparison; using `<=` when selecting from the left half would preserve the original order of equal elements and make the merge stable.

---

## 2.6 `quicksort2.cpp` — Quick Sort

### Aim
Sort an eight-element array using quick sort.

### Working in points
- `quicksort()` runs only while `low < high`.
- `partition()` chooses the first element, `a[low]`, as the pivot.
- Pointer `i` begins at `low + 1`; pointer `j` begins at `high`.
- `i` advances while values are smaller than the pivot.
- `j` moves backwards while values are greater than the pivot.
- If `i < j`, the values at `i` and `j` are swapped.
- When the pointers meet or cross, the pivot is swapped with `a[j]`.
- The pivot's final index is returned.
- `quicksort()` recursively sorts the portions before and after the pivot.
- `main()` sorts `{6, 2, 7, 4, 8, 1, 9, 0}` and prints the result.

### Complexity
Average time: `O(n log n)`. Worst time: `O(n²)`, especially when the pivot repeatedly divides the data very unevenly. Recursive stack space is typically `O(log n)` on average and can reach `O(n)` in the worst case.

### Code note
The partition loops do not explicitly check `i <= high` or `j >= low` in their inner conditions. The current sample should be tested carefully, and bounds checks should be added to make the partition implementation safer for edge cases.

---

## 2.7 `k_small.cpp` — Partition-Based Selection Attempt

### Aim
Use quick-sort-style partitioning to narrow down a section of an array related to the requested `k` value.

### Working in points
- `partition()` selects the first value as the pivot and rearranges values around it.
- The returned `part` is the pivot's final position.
- `smallest()` compares `part` with `k`.
- If `part == k`, it prints the first `k` array values.
- If `k < part`, it recursively searches the left partition.
- If `k > part`, it recursively searches the right partition.
- `main()` uses the array `{6, 2, 7, 4, 8, 1, 9, 0}` and calls `smallest(a, 0, 7, 3)`.

### Important code note
The implementation is a selection-style attempt rather than a complete, clearly defined k-th-smallest API. It uses zero-based array indices for `part`, but prints the first `k` elements when `part == k`; that output is not necessarily the single k-th smallest element, and the first `k` values are not guaranteed to be sorted. Clarify whether `k` means an index, the k-th smallest value, or the smallest `k` values before adapting this program.

### Complexity
Partition-based selection can be average `O(n)`, but this implementation's performance and correctness depend on the partition logic and the meaning assigned to `k`.

---

## 2.8 `binsort.cpp` — Bin/Frequency Sort

### Aim
Sort integer values by counting how many times each value appears.

### Working in points
- The `max()` function finds the maximum value in the input array.
- A bin array is allocated for indices from zero through the maximum value.
- All bins begin with a frequency of zero.
- Each input value increments the bin at its own index.
- The program scans bins from low to high.
- For each bin, it prints the index as many times as that value occurred.

### Example concept
If the input is `4 2 4 1`, the frequencies are: value `1` occurs once, `2` once, and `4` twice. Printing bins in ascending index order produces `1 2 4 4`.

### Complexity
If `n` is the number of values and `k` is the maximum value, time and space are `O(n + k)`.

### Limitations
- Values must be non-negative because they are used as array indices.
- A very large maximum value requires a large bin array.
- The source should be checked for allocation and input-size limits before using it with arbitrary data.

---

## 2.9 `bucketsort.cpp` — Bucket Sort

### Aim
Distribute values into buckets, sort each bucket, and combine the results.

### Working in points
- The program creates a fixed two-dimensional bucket array and a count array.
- For each value, it calculates a bucket index using integer division by `10`.
- The value is placed at the next free position in that bucket.
- Each bucket is sorted internally using comparisons and swaps.
- The program visits buckets in increasing index order.
- It copies the bucket contents back into the original array.
- The sorted array is then displayed.

### Complexity
Performance depends on how values are distributed among buckets and on the algorithm used to sort each bucket.

### Limitations
The implementation uses a fixed number and size of buckets. The values must map to valid bucket indices; values outside the assumed range can cause invalid indexing. It is not a general-purpose bucket sort for arbitrary real numbers.

---

## 2.10 `countsort.cpp` — Stack Using an Array (Filename Does Not Match)

### Aim
Demonstrate stack operations using an array. Despite the filename, this source does **not** implement counting sort.

### Working in points
- The `Stack` class contains an integer array of size `100` and an integer `top`.
- The constructor sets `top = -1`, indicating an empty stack.
- `push(value)` checks whether `top == 99`. If full, it prints `Stack Overflow`; otherwise, it increments `top` and stores the value.
- `pop()` checks whether `top == -1`. If empty, it prints `Stack Underflow`; otherwise, it prints the top value and decrements `top`.
- `peek()` prints the current top value without removing it.
- `display()` prints values from `top` down to index `0`.
- `main()` pushes five values, displays the stack, peeks at the top, pops two values, and displays the remaining stack.

### Key concept
Stack follows **LIFO — Last In, First Out**. The last value pushed is the first value popped.

### Complexity
`push`, `pop`, and `peek` are `O(1)`. Display is `O(n)`. Storage is `O(1)` fixed capacity of 100 elements.

---

## 2.11 `heapsort.cpp` — Heap Sort Using an Array

### Aim
Sort an array in ascending order using a max heap.

### `heapify(arr, n, i)`
- Treat index `i` as the root of a subtree.
- Calculate the left child index `2*i + 1` and right child index `2*i + 2`.
- Compare the root with its existing children.
- Store the index of the largest value.
- If the largest value is not at `i`, swap it with the root and recursively heapify the affected subtree.

### `heapSort(arr, n)`
1. Start at the last non-leaf node, `n/2 - 1`.
2. Call `heapify()` for each node moving backwards to index `0`; this builds a max heap.
3. The maximum element is now at the root, `arr[0]`.
4. Swap the root with the final element of the current heap.
5. Reduce the heap size by one.
6. Heapify the root again.
7. Repeat until the heap contains one element.

### Complexity
Building the heap is `O(n)`. The full sort is `O(n log n)` time and `O(1)` auxiliary space, excluding the recursion stack used by `heapify()`.

---

## 2.12 `radixsortusinglinklist.cpp` — Radix Sort with Linked-List Buckets

### Aim
Sort non-negative integers by processing one decimal digit at a time and storing values in linked-list buckets.

### Components
- `Node` stores an integer and a pointer to the next node.
- `Bucket` maintains `front` and `rear` pointers.
- `Bucket::insert()` adds a value to the rear of a bucket.
- `Bucket::remove()` removes and returns the front value.
- `Bucket::isEmpty()` checks whether the bucket has any nodes.
- `RadixSort` stores up to 100 input values.

### Sorting steps
1. Read the number of values and the values themselves.
2. Find the maximum value with `getMax()` to determine how many digit positions are required.
3. Start with `place = 1`, which represents the ones digit.
4. For each value, extract the current digit using `(a[i] / place) % 10`.
5. Insert the value into the bucket for that digit.
6. Collect values from buckets `0` through `9` in order, restoring the array.
7. Multiply `place` by `10` and repeat for tens, hundreds, and further positions until all digits in the maximum value have been processed.
8. Print the sorted values.

### Complexity
For `d` decimal digits and `n` values, the expected running time is `O(d(n + 10))`; the buckets require additional node storage during each pass.

### Limitations
This implementation assumes non-negative integers and at least one input element. It should validate `n` and reject negative values to avoid invalid bucket indexing or accessing `a[0]` when the input is empty.

---

# 3. Linked Lists

## 3.1 `linklist.cpp` — Singly Linked List

### Aim
Demonstrate inserting, deleting, searching, and printing nodes in a singly linked list.

### Node structure
- Each `node` stores `data` and `next`.
- `next` points to the following node.
- The final node has `next == NULL`.
- The `list` class stores `head` and `tail`.

### Operations
- **Constructor:** sets `head` and `tail` to `NULL`.
- **`push_front(val)`:** creates a node and links it before the current head. If the list is empty, both head and tail point to the new node.
- **`push_back(val)`:** connects the current tail to the new node and updates tail. If empty, both pointers point to the new node.
- **`push_midle(val, pos)`:** attempts to insert at a position by walking to the preceding node and changing links.
- **`pop_front()`:** saves the old head, advances head to the next node, and deletes the old head.
- **`pop_back()`:** walks to the node immediately before tail, disconnects the old tail, deletes it, and updates tail.
- **`search(keyi)`:** traverses the list and returns the zero-based index when the value is found.
- **`print()`:** walks from head to `NULL` and prints each node's data.

### Important code notes
- `search()` does not return a defined value when the key is absent.
- `push_midle()` needs boundary checks for an empty list and positions beyond the list length; as written, it can dereference a null pointer for invalid positions.
- `pop_front()` should also set `tail = NULL` when removing the only node.
- `pop_back()` should handle the single-node case separately.
- These are important edge cases to fix before using the list as a general-purpose implementation.

### Complexity
- Insert at head: `O(1)`.
- Insert at tail: `O(1)` because tail is maintained.
- Search: `O(n)`.
- Delete at tail: `O(n)` in a singly linked list.

---

## 3.2 `doublelinklist.cpp` — Doubly Linked List

### Aim
Implement a list whose nodes point both forwards and backwards.

### Node structure
- `data` stores the value.
- `next` points to the next node.
- `prev` points to the previous node.
- The list maintains `head` and `tail`.

### Operations in the source
- `push_front(val)` inserts a node before head and updates the old head's `prev`.
- `push_back(val)` connects the new node after tail and updates its `prev`.
- `print()` moves forward from head, printing each node.
- `pop_front()` removes the first node and advances head.
- `pop_back()` walks to the node before tail, disconnects and deletes the old tail, then updates tail.
- `main()` inserts values, prints the list, removes values from both ends, and prints again.

### Important code note
The current `pop_front()` does not handle the single-node case safely: after advancing head, it accesses `head->prev` without checking whether head became `NULL`. `pop_back()` also needs a separate single-node case. Correct doubly linked-list deletion must keep both `head` and `tail` valid.

### Complexity
Insertion at either end is `O(1)`. Printing is `O(n)`. Deleting the last node is `O(n)` in this implementation because it searches for the preceding node rather than using `tail->prev`.

---

## 3.3 `circularlinklist.cpp` — Circular Singly Linked List

### Aim
Create a singly linked list in which the last node points back to the first node.

### Main idea
In an ordinary singly linked list, the final node points to `NULL`. Here, `tail->next` points to `head`, forming a circle.

### Operations
- `push_front(val)` inserts a node before head and reconnects `tail->next` to the new head.
- `push_back(val)` connects the new node after tail and then points its `next` to head.
- `pop_front()` removes head and reconnects the tail to the new head.
- `pop_back()` walks to the node before tail, removes the old tail, and reconnects the new tail to head.
- `print()` uses a loop that stops when it returns to the head.
- The program's `main()` demonstrates insertion, deletion, and printing.

### Important code note
`print()` assumes the list is non-empty and will dereference `head` when the list is empty. Add an empty-list check before traversal. The circular link must be maintained after every insertion or deletion.

### Complexity
Insert at head/tail is `O(1)` with maintained head/tail pointers. Deleting the last node is `O(n)` because the predecessor must be found.

---

## 3.4 `insertion_sortLL.cpp` — Linked-List Insertion Sort

See [Insertion Sort on a Singly Linked List](#23-insertion_sortllcpp--insertion-sort-on-a-singly-linked-list). This file maintains a sorted chain by relinking existing nodes and updates the tail after sorting.

---

# 4. Stacks

## 4.1 `stackusingarray.cpp` — Stack Using an Array

### Aim
Implement the LIFO stack data structure with a fixed-size array.

### Working
- The array has capacity `100`.
- `top = -1` represents an empty stack.
- `push(value)` checks for overflow, increments top, and writes the value.
- `pop()` checks for underflow, prints the top value, and decreases top.
- `peek()` reads the top value without removing it.
- `display()` prints from top to bottom.
- The `main()` function pushes five values, displays them, reads the top, pops two elements, and displays the remaining values.

### Complexity
Push, pop, and peek: `O(1)`. Display: `O(n)`. Storage: fixed `O(100)`.

---

## 4.2 `stackusinglinklist.cpp` — Stack Using a Singly Linked List

### Aim
Implement stack operations with dynamically allocated linked-list nodes.

### Working according to the source
- `node` contains a value and a `next` pointer.
- `stack` maintains `head` and `tail`.
- `push(val)` inserts each new node at the tail.
- `print()` traverses from head to tail and prints values in insertion order.
- `pop()` walks from head until it reaches the node immediately before tail, deletes tail, and updates tail.
- `main()` pushes a series of values, prints the list, pops twice, and prints again.

### Important code notes
- Because push inserts at the tail, pop removes the tail, so the newest value is removed first: this follows LIFO.
- `pop()` does not check whether the stack is empty.
- If there is only one node, the loop `while(temp->next != tail)` does not provide a safe single-node deletion path; it may dereference invalid pointers or leave head inconsistent.
- For an efficient linked-list stack, it is simpler to push and pop at the head, making both operations `O(1)`.

### Complexity
Push: `O(1)` in this code. Pop: `O(n)` because it searches for the previous node. Display: `O(n)`.

---

## 4.3 `stackusingdoublelinklist` — Stack Using a Doubly Linked List

### Aim
Implement stack operations with nodes that contain both `prev` and `next` pointers.

### Working
- Each node stores `data`, `prev`, and `next`.
- `head` and `tail` identify the two ends.
- `push(value)` appends a new node at tail and updates both links.
- `pop()` removes tail, because tail represents the top of the stack.
- `peek()` prints the tail value without deleting it.
- `display()` starts at tail and moves backwards using `prev`, so the top element is printed first.
- `main()` pushes four values, displays the stack, peeks, pops twice, and displays the remaining values.

### Complexity
Push, pop, and peek: `O(1)` because the doubly linked list supports direct access to the tail. Display: `O(n)`.

---

# 5. Queues

## 5.1 `queueusingarray.cpp` — Queue Using an Array

### Aim
Demonstrate FIFO queue operations with an array.

### Working
- The queue uses `a[100]`, `f` (front index), and `r` (rear index).
- Both indices begin at `-1`.
- `enqueue(val)` increments rear and stores the new value.
- `dequeue()` checks whether `f == r`; if so, the queue is empty. Otherwise, it increments front, prints the removed value, and sets that array slot to zero.
- `display()` prints the elements from `f + 1` through `r`.
- `main()` enqueues several values, displays the queue, dequeues three values, and displays the remaining queue.

### FIFO meaning
**FIFO — First In, First Out:** the earliest inserted value is removed first.

### Important code notes
- The implementation does not check whether the array is full before enqueueing.
- The rear index never wraps around, so removed positions cannot be reused.
- A circular queue is more suitable when the array should reuse freed positions.

### Complexity
Enqueue and dequeue: `O(1)`. Display: `O(n)`.

---

## 5.2 `queueusinglinklist.cpp` — Linked-List Stack in the Current Source

### Aim
The filename suggests a queue, but the source declares `class stack` and implements `push()`, `pop()`, and `print()`.

### Working according to the code
- Each node stores `data` and `next`.
- `head` and `tail` start as `NULL`.
- `push(val)` appends a new node at tail.
- `pop()` removes the head node.
- `print()` traverses and prints all nodes.
- `main()` calls `push()` several times, prints the list, calls `pop()` twice, and prints again.

### Important distinction
This particular combination—insert at tail and remove at head—behaves like a **FIFO queue**, even though the class is named `stack`. However, the file does not use queue-style method names such as `enqueue()` and `dequeue()`. It also lacks an empty check in `pop()`.

### Complexity
Push/enqueue at tail: `O(1)`. Pop/dequeue at head: `O(1)`. Display: `O(n)`.

---

## 5.3 `queueusingdoublelinklist` — Queue Using a Doubly Linked List

### Aim
Implement a FIFO queue with a doubly linked list.

### Working
- The queue stores `head` (front) and `tail` (rear).
- `enqueue(value)` creates a node at the rear. If empty, both pointers refer to it; otherwise, it links the new node after tail and updates tail.
- `dequeue()` removes the node at head.
- If the removed node was the only node, both head and tail become `NULL`.
- Otherwise, head advances and the new head's `prev` becomes `NULL`.
- `front()` displays the first value.
- `rear()` displays the last value.
- `display()` traverses from head to `NULL`.
- `main()` demonstrates inserting values, reading front/rear, removing values, and displaying the queue.

### Complexity
Enqueue, dequeue, front, and rear: `O(1)`. Display: `O(n)`.

---

## 5.4 `cqa.cpp` — Circular Queue Using an Array

### Aim
Implement a fixed-capacity circular queue using an array of size five.

### Working
- `front` and `rear` start at `-1`.
- The queue is full when `(rear + 1) % 5 == front`.
- On the first enqueue, both indices become `0`.
- On later enqueues, rear advances with `(rear + 1) % 5`, allowing it to wrap around to the beginning of the array.
- `dequeue()` removes the front element.
- If the queue becomes empty, both indices return to `-1`; otherwise, front advances with modulo arithmetic.
- `display()` starts at front and continues until it has printed the rear element.

### Why circular queues are useful
They reuse empty positions created by dequeues, unlike a simple linear array queue whose rear only moves forward.

### Complexity
Enqueue and dequeue: `O(1)`. Display: `O(n)`. Capacity: five values.

---

## 5.5 `cqll.cpp`, `cicularqueuel.cpp`, and `cicularqueueusinglinklist.cpp` — Circular Queue with a Linked List

### Aim
Implement a circular FIFO queue where the last node links back to the first node.

### Working
- Each node stores `data` and `next`.
- `front` points to the first value; `rear` points to the last.
- On the first enqueue, front and rear both point to the new node and `rear->next = front`.
- On later enqueues, the new node is linked after rear, rear is updated, and `rear->next` is reset to front.
- `dequeue()` removes the front node.
- If front and rear are the same node, deleting it makes both pointers `NULL`.
- Otherwise, front advances and `rear->next` is updated to point to the new front.
- `display()` uses a `do-while` loop and stops when traversal returns to front.
- The sample `main()` inserts values, removes two values, and displays the queue.

### Complexity
Enqueue: `O(1)`. Dequeue: `O(1)`. Display: `O(n)`.

### Code note
These files appear to contain substantially the same circular-queue implementation. Keep one canonical version if the duplication is unintentional, and ensure every copy receives the same bug fixes.

---

# 6. Binary Trees, BSTs, AVL Trees, and Heaps

## 6.1 `binarytree.cpp` — Binary Tree Creation, Traversal, Insertion, and Deletion

### Aim
Create a general binary tree, display it using inorder traversal, insert a value, and delete a requested value.

### Key idea
A general binary tree does not require the left child to be smaller than the root or the right child to be larger. Its shape is not governed by the BST ordering rule.

### Working according to the source
- The `node` class stores a value and pointers to the left and right children.
- The tree is created through `createbinarytree()`.
- `inorder(root)` visits the left subtree, prints the root, then visits the right subtree.
- `inserti(root, value)` inserts a new node in the next available position using level-order traversal with a queue.
- `deletion(root, value)` searches level by level for the target and the deepest rightmost node.
- If the target is found, the target node's value is replaced by the deepest node's value.
- `deleteDeepest()` removes the deepest rightmost node from its parent.
- The tree is printed again using inorder traversal after insertion and deletion.

### Why use a queue?
A queue makes it possible to visit nodes level by level. This allows insertion into the first available left or right child position.

### Complexity
Traversal and level-order search are `O(n)`. Insertion and deletion are `O(n)` because the tree may need to be traversed.

---

## 6.2 `binary2.cpp` — Height, Sum, and Number of Nodes in a Binary Tree

### Aim
Calculate three properties of a binary tree:
- Height of the tree
- Sum of all node values
- Total number of nodes

### Working
- A sample tree is manually constructed in `main()`.
- `height(root)` recursively finds the height of the left and right subtrees and returns the larger height plus one.
- `sumOfNodes(root)` recursively adds the root value, the left-subtree sum, and the right-subtree sum.
- `countNodes(root)` returns one for the current node plus the counts of the two subtrees.
- The results are printed.

### Base case
For a null pointer, recursion should return:
- `0` for height (depending on the chosen height convention),
- `0` for sum,
- `0` for node count.

### Important code note
The current source declares `sumOfNodes()` and `countNodes()` as `void`, even though the functions return integer values and their results are used in arithmetic. Their return types must be changed to `int`. The code also needs a consistent definition of height: this implementation appears to count nodes along the longest path, not edges.

### Complexity
Each node is visited once, so the intended time complexity is `O(n)`. Recursive stack space is `O(h)`, where `h` is the tree height.

---

## 6.3 `BST.cpp` — Binary Search Tree Insertion and Deletion

### Aim
Build a Binary Search Tree (BST), insert values, delete selected values, and display the tree in sorted order.

### BST property
- Values smaller than a node belong in its left subtree.
- Values greater than a node belong in its right subtree.
- Inorder traversal (left, root, right) visits values in ascending order when the BST property is maintained.

### Working according to the source
- The `BST` class stores a root pointer.
- `insertvalue(value)` calls the recursive insertion helper and assigns the returned pointer to root.
- The insertion helper creates a node when it reaches a null child and otherwise follows the left or right branch based on the value.
- `deletevalue(value)` calls the deletion helper and updates root with the returned pointer.
- Deletion must handle the target node's structural case: no child, one child, or two children.
- `display()` calls inorder traversal.
- `main()` inserts several sample values, prints the BST, deletes values `90` and `50`, and prints the result again.

### Why return the subtree root?
Insertion and deletion may change the root of a subtree. Returning the updated pointer allows the parent node—or the tree object—to reconnect the correct subtree.

### Complexity
Average search/insert/delete: `O(log n)` in a reasonably balanced tree. Worst case: `O(n)` in a highly skewed tree. Inorder traversal: `O(n)`.

---

## 6.4 `avl.cpp` — Interactive AVL Tree

### Aim
Provide menu-driven AVL tree operations: insertion, deletion, searching, and preorder traversal.

### AVL tree concept
An AVL tree is a self-balancing BST. At every node, the height difference between the left and right subtrees must remain within `-1` and `+1`.

### Working
- The program creates an AVL tree object.
- A menu is displayed repeatedly inside a `do-while` loop.
- Option `1` reads a value and inserts it.
- Option `2` reads a value and removes it.
- Option `3` searches for a value.
- Option `4` displays preorder traversal.
- Option `0` exits.
- After insertion or deletion, AVL logic updates node heights and checks balance factors.
- If a node becomes unbalanced, rotations restore balance.

### Four rotation cases
- **LL:** right rotation.
- **RR:** left rotation.
- **LR:** left rotation on the left child, then right rotation.
- **RL:** right rotation on the right child, then left rotation.

### Complexity
Search, insertion, and deletion are `O(log n)` when the AVL invariants are correctly maintained. Preorder traversal is `O(n)`.

---

## 6.5 `binarytreeavl.cpp` — AVL Insertion and Traversals

### Aim
Demonstrate AVL insertion and inspect the resulting tree through preorder and inorder traversals.

### Working in points
- `Node` stores the value, child pointers, and height information.
- `insert()` recursively inserts the value using the BST ordering rule.
- Duplicate values are ignored by the current implementation.
- The node's height is updated after insertion.
- The balance factor is calculated.
- The program checks the four AVL imbalance patterns:
  - LL: right rotation.
  - LR: left rotation on the left child, then right rotation.
  - RR: left rotation.
  - RL: right rotation on the right child, then left rotation.
- `main()` inserts `10`, `20`, `30`, `40`, `50`, and `25`.
- It prints preorder traversal, inorder traversal, and the height.

### Traversals
- Preorder: root, left, right.
- Inorder: left, root, right. For a valid BST, this prints values in ascending order.

### Complexity
Each insertion is `O(log n)` for a correctly balanced AVL tree. Traversals take `O(n)`.

---

## 6.6 `heapusinglinklist.cpp` — Heap Operations on a Binary Tree

### Aim
Build a binary tree level by level, convert its values into a max heap, and demonstrate heap-sort-style processing.

### Structure
- Each `Node` contains `data`, `left`, and `right`.
- `insert(root, value)` uses a queue to find the first available child position, keeping the tree shape complete.
- `heapify(root)` compares the root's value with its children, swaps with the largest child if necessary, and continues down the affected subtree.
- `buildHeap(root)` traverses the tree in an order that allows subtrees to be heapified.
- `display(root)` uses level-order traversal to print the tree.
- `heapSort(root)` repeatedly performs heap-related operations to order the stored values.
- `deleteTree(root)` recursively frees nodes.
- `main()` reads a number of nodes and their values, displays the original tree, builds and displays a max heap, then displays the result after the heap-sort operation.

### Important distinction: array heap vs linked binary tree
An array-based heap identifies children by index (`2*i+1` and `2*i+2`). A linked binary tree identifies children through `left` and `right` pointers. Because this source uses pointers, it must explicitly traverse the tree to find nodes and maintain the complete-tree shape.

### Complexity note
Level-order insertion is `O(n)` per inserted value in this implementation because it scans from the root. A full tree traversal is `O(n)`. Heap-sort complexity depends on how the code locates and extracts values; a linked-tree implementation is not automatically `O(n log n)` just because it uses a heap concept.

---

# 7. Recursion

## 7.1 `towerofhanoi.cpp` — Tower of Hanoi

### Aim
Print the sequence of moves required to transfer `n` disks from a source peg to a destination peg using an auxiliary peg.

### Rules of the puzzle
- Move only one disk at a time.
- Only the top disk of a peg may be moved.
- A larger disk cannot be placed on top of a smaller disk.

### Recursive working
- `towerOfHanoi(n, source, auxiliary, destination)` receives the disk count and the three peg labels.
- **Base case:** if `n == 1`, print a move from source to destination and return.
- Move `n - 1` disks from source to auxiliary, using destination as the helper.
- Move the largest remaining disk from source to destination.
- Move the `n - 1` disks from auxiliary to destination, using source as the helper.
- `main()` reads the number of disks and calls the function with pegs `A`, `B`, and `C`.

### Number of moves
For `n` disks, the minimum number of moves is `2ⁿ - 1`.

### Complexity
Time: `O(2ⁿ)`. Recursive stack space: `O(n)`.

### Code note
The input should be a positive integer. The current code only explicitly handles `n == 1` as its base case; an input of zero or a negative number is not validated.

---

# Complexity Quick Reference

| Program / operation | Typical time complexity | Extra space |
|---|---:|---:|
| Array insertion/deletion by shifting | `O(n)` | `O(1)` |
| Linear search in a linked list | `O(n)` | `O(1)` |
| Selection sort | `O(n²)` | `O(1)` |
| Insertion sort on array | Best `O(n)`, worst `O(n²)` | `O(1)` |
| Insertion sort on linked list | `O(n²)` worst case | `O(1)` auxiliary |
| Merge sort | `O(n log n)` | `O(n)` |
| Quick sort | Average `O(n log n)`, worst `O(n²)` | Recursion stack |
| Heap sort on array | `O(n log n)` | `O(1)` auxiliary |
| Radix sort | `O(d(n + 10))` for decimal digits | Bucket storage |
| Stack push/pop on array | `O(1)` | Fixed array |
| Queue enqueue/dequeue with linked list | `O(1)` | `O(n)` nodes |
| Binary-tree traversal | `O(n)` | `O(h)` recursive stack |
| BST operations | Average `O(log n)`, worst `O(n)` | Depends on recursion |
| AVL search/insert/delete | `O(log n)` | Depends on recursion |
| Tower of Hanoi | `O(2ⁿ)` | `O(n)` |

*Complexities describe the standard operation or intended algorithm. Where the current source has implementation issues, the actual behaviour may differ.*

---

# Compile and Run

## Compile one C++ file

Install a C++ compiler such as GCC, then open a terminal in the repository folder.

Example for merge sort:

```bash
g++ mergesort.cpp -o mergesort
```

Run on Windows:

```bash
.\mergesort.exe
```

Run on Linux/macOS:

```bash
./mergesort
```

For a file without the `.cpp` extension, pass its exact filename to the compiler. For example:

```bash
g++ "insertion _in_arrayas_adt" -o array_adt
```

If your compiler expects a C++ standard, you can specify one:

```bash
g++ -std=c++17 mergesort.cpp -o mergesort
```

## Open the repository in VS Code

1. Extract the ZIP file.
2. Open VS Code.
3. Select **File → Open Folder**.
4. Choose the extracted `prashant-dsa-main` folder.
5. Open the source file you want to practise.
6. Compile and run that file separately.

---

# Suggested Improvements

These notes are based on the current source files and are useful next steps:

1. **Rename files to match their contents.** `countsort.cpp` currently contains a stack implementation; `queueusinglinklist.cpp` contains a class named `stack` but its insert-at-tail/remove-at-head behaviour is FIFO.
2. **Add empty-list checks.** Linked-list `pop`, `print`, and search functions should handle empty lists.
3. **Handle single-node deletion.** When deleting the only node, both `head` and `tail` must become `NULL`.
4. **Validate array bounds.** Array ADT insertion should check capacity and validate the requested position.
5. **Fix missing return values.** `binary2.cpp` should declare `sumOfNodes()` and `countNodes()` with return type `int`.
6. **Fix quadratic-root arithmetic.** Use parentheses around `2*a` and avoid calling `sqrt()` on a negative discriminant for real-root calculations.
7. **Review the zero-shifting implementation.** `zeroatlast.cpp` changes the logical length while scanning and may skip or misplace values.
8. **Review duplicate detection.** `firstduplicate.cpp` has an outer-loop `break` that prevents checking all starting positions.
9. **Add bounds checks to quick sort partitioning.** The pointer scans in `quicksort2.cpp` and `k_small.cpp` should guard against moving outside the current range.
10. **Use standard C++ arrays or vectors where appropriate.** Variable-length arrays such as `int arr[n]` are not part of standard C++.
11. **Add complexity and sample output to each program.** This makes the repository easier to revise for practical exams and interviews.
12. **Use consistent naming and formatting.** Choose consistent names such as `Node`, `head`, `tail`, `enqueue`, and `dequeue` to make the data structures easier to understand.

---

## Learning Order

A useful order for studying the programs is:

1. Basic loops and mathematical programs.
2. Array operations and linear search.
3. Sorting algorithms: selection, insertion, merge, quick, heap, radix, and bucket sort.
4. Singly, doubly, and circular linked lists.
5. Stacks and queues using arrays.
6. Stacks and queues using linked lists.
7. Binary-tree traversal and properties.
8. Binary search trees.
9. AVL trees and rotations.
10. Heaps and recursive problems such as Tower of Hanoi.

The goal of this repository is not only to memorise code, but also to understand **why each pointer changes, how each loop progresses, what the base cases do, and how the data structure changes after every operation**.
