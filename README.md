prog number1
aim-To find the number of dips the ball will take so that its speed become zero in every dip the speed of the ball become half its intial speed
working--
1-take integer count and intialise it with zero
2-take float speed and ask for the speed from the user
3-use the while loop  and take the condition  that speed>0.001
4-inside the wile loop use the condition  as given in the problem that speed=speed/2
5-count=count++
6-at last print the number of count calculated by using the while loop


prog number2
aim-Find the roots of the quadratic equation whether it is real ,imaginary or equal and print the roots of the quadratic equation
working--
1-take the three integer a,b,c and ask the input from the user 
2-take float d and find its value from the formula b² − 4ac
3-take two float value float root1 and root2
4-now write the if condition that if d>0
5-now find now now find the root 1 and root 2 using the formula (-b ± √(b)) / 2a. 
6-now print the value of root 1 and root 2. 
7-write an `else if` condition: `b = 0`, then find the root1 = root2 = -b/2a, and then print the root1. 
8-now write the else condition. Take the float parameter real part and apply the formula -b/(2a) and another float parameter imaginary part, and apply the formula √(-d)/2a. Print the roots of the equation:
- root 1 = real part + imaginary part
- root 2 = real part - imaginary part

prog number3
aim-write a program to accept an array and insert a number in the beginning, in the middle, and at the last, and delete the given element. 
working --
1-take the integer parameter arr[100],n,i,num,pos,del
2-take the input n from the user and also accept the elements of the array from the user using a for loop. 
3-now take the number from the user, which needs to be put in the beginning of the array. 
4-now write the for loop with the condition that i = n and i > 0. Shift the array backward by one position, and at arr[0], enter the number which we have taken input from the user, which needs to be put in the beginning of the array. Also write the condition n++. at last
5-now print an array after inserting the element at the beginning of the array. 
6-now take the position from the user where we want to input the number in the array. 
7-now ask the user about the number which we want to input in the given position. 
8-now we will write the for loop using the condition that i = n and i >= pos ,i++ and. Shift the array backward by one position and insert the number in the given position. At last, we will write the array after inserting the element in the middle.
9-now we will accept the number from the user, which we want to put in the array at the last. 
10-we will directly write `arr[n] = num`, and in the second condition we will write `n++`. After this, we will directly  using a for loop we will print the array after inserting the element at the end. 
11-now we will ask the user for the element we want to delete. 
12-now we will initialize one integer parameter, found=zero. Now we will write a for loop, and inside the for loop we will apply a condition that i = 0, i < n, i++.And inside the for loop, we will use the condition that if (arr[i] = del) found = 1, then we will write another for loop from j = i, j < n - 1,j++ and in that loop, we will shift the one element forward. Using the condition `arr[j] = arr[j + 1]` and at end we will write n__ and break;
13-now we will apply an if condition and inside if we will write(found==0) and print the statement "number not found"
14-now we will write an `else` condition, and inside the `else` condition we will print the statement `array` after deletion, and then we will apply a `for` loop inside of the for loop, we will apply a condition that i = 0, i < n, i++. We will print the statement arr[i].

prog number4
aim--write a program to find the maximum height, range, and time of flight in the projectile motion. 
working--
1-ask the value of theta and initial speed from the user and take the float parameter theta and u. And ask the value of theta and u from the user. take the float parameter g=9.8;
2-take the float parameter theta_rad and convert theta into radian using the formula theta × π/180. 
3-now take the float parameter max height and use the formula u × u × (sin(theta_rad) × sin(theta_rad)  )/2g, and in place of theta use the value theta_rad. 
4-now take the float parameter max height and calculate using the formula u*u*sin(theta_rad)/g. 
5-now take the flow parameter time of flight and calculate using the formula 2 × u × sin(theta_rad) / g 
6-now print the maximum height, time of flight, and the range. 

prog number5
aim--accept an array from the user and shift the zero to the end of the array. 
working--
1-first, make the void function swap, and inside the swap, accept the two integer elemeant and swap that element
2-take int a[10],n,sum as the parameter
3-now, write the for loop using the condition that `i = 0`, `i <n, and `i++`, and take the element of the array from the user as an input.
4-now again write a for loop, and inside the for loop write the condition that `int i = 0; i < n; i++`. Write the condition that if (a[i] == 0), then `sum = i;. Again write a for loop and use the condition that `int j = sum; j < n - 1; j++`. Inside another for loop, use the condition that if (a[j] == 0), swap (a[j], a[j+1]).
5-now, at last, print the array after shifting all the zeros to the end of the array. 

prog number6
aim-find the first duplicate number in an array. 
working--
1-first take the integer parameter a[10] and accept the 10 element from the user using the for loop 
2-write a for loop, and inside the for loop use the condition that `int i = 0, i < 10, i++`. Then take another for loop, and inside that loop use the condition that `int j = i + 1, j < 10, j++`.
3-use the IF statement that if (a[i]==a[j])
4-print the statement that"first duplicate is" a[i]
5-use the break statement in outer loop 
6-at last print the duplicate element 
Program 6 — prog6.cpp

Aim

To find duplicate elements in an array using nested loops.

Concept Used

Array traversal

Nested loops

Comparison

Duplicate detection

Detailed Working

An array of 10 integers is created.

The user enters all 10 elements.

The outer loop selects an element a[i].

The inner loop starts from i + 1, so the selected element is compared only with elements after it.

If:

a[i] == a[j]

a duplicate has been found.

The duplicate value is printed.

The inner loop is stopped with break.

Complexity

Time: O(n²)

Space: O(1)

Important Note

The current program breaks only the inner loop, not the outer loop. Therefore, if multiple duplicate groups exist, it can print more than one duplicate. To stop after the very first duplicate, the outer loop would also need to be terminated.

2. Sorting Programs

Program 7 — selectionsort.cpp

Aim

To sort an array in ascending order using Selection Sort.

Concept

Selection Sort repeatedly selects the smallest element from the unsorted part of the array and places it at the beginning of that unsorted part.

Detailed Working

The array contains 10 predefined elements.

The outer loop starts from index 0.

smallestindex initially stores the current index.

The inner loop searches for a smaller element.

When a smaller element is found, smallestindex is updated.

After searching the unsorted part, the smallest element is swapped with a[i].

The process continues until the array is sorted.

Example:

Before:
23 1 45 67 12

After:
1 12 23 45 67

Complexity

Best: O(n²)

Average: O(n²)

Worst: O(n²)

Extra space: O(1)

Advantage

Selection Sort performs a small number of swaps.

Program 8 — insertionsort.cpp

Aim

To sort an array using Insertion Sort.

Concept

Insertion Sort treats one part of the array as sorted and inserts each new element into its correct position.

Detailed Working

The first element is considered sorted.

The next element is selected as the current element.

Elements larger than the current element are shifted to the right.

The current element is inserted into the empty position.

The process repeats for every element.

Example:

8 3 5 2

After inserting 3:
3 8 5 2

After inserting 5:
3 5 8 2

After inserting 2:
2 3 5 8

Complexity

Best: O(n) for an already sorted array

Average: O(n²)

Worst: O(n²)

Space: O(1)

Best Use

Insertion Sort works well for small or nearly sorted arrays.

Program 9 — mergesort.cpp

Aim

To sort an array using the Merge Sort algorithm.

Concept

Merge Sort follows the Divide and Conquer technique.

Detailed Working

The array is divided into two halves.

Each half is recursively divided.

This continues until individual elements remain.

Individual elements are considered sorted.

Two sorted portions are merged by comparing their elements.

The smaller element is copied first.

The merged result is copied back into the original array.

Finally, the complete array becomes sorted.

Main Functions

merge() — combines two sorted sections.

mergeSort() — recursively divides the array.

Complexity

Best: O(n log n)

Average: O(n log n)

Worst: O(n log n)

Extra space: O(n)

Important Idea

Merge Sort is stable when the merge operation preserves equal elements in their original order.

Program 10 — quicksort2.cpp

Aim

To sort an array using Quick Sort.

Concept

Quick Sort is another Divide and Conquer algorithm.

Detailed Working

The first element of the current portion is selected as the pivot.

i starts from the element after the pivot.

j starts from the end.

i moves forward while elements are smaller than the pivot.

j moves backward while elements are larger than the pivot.

Elements at i and j are swapped when necessary.

Finally, the pivot is swapped into its correct position.

The position of the pivot divides the array into two parts.

Quick Sort is recursively applied to both parts.

Complexity

Average: O(n log n)

Worst: O(n²)

Recursive stack: approximately O(log n) average

Important Note

The choice of the first element as pivot can produce poor performance when the input is already sorted or nearly sorted.

Program 11 — binsort.cpp

Aim

To sort non-negative integer values using a frequency/bin array.

Concept

Instead of repeatedly comparing elements, the program counts how many times each value occurs.

Detailed Working

The max() function finds the largest element.

A bin array is created with indices from 0 to the largest value.

Initially every bin contains zero.

For every array element:

bini[a[i]]++;

The program then traverses the bins from smallest index to largest.

If a bin contains a value greater than zero, its index is printed that many times.

Therefore, values appear in ascending order.

Example:

Input:
4 2 4 1

Frequency:
1 -> 1
2 -> 1
4 -> 2

Output:
1 2 4 4

Complexity

Time: O(n + k)

Space: O(k)

where k is the maximum value plus one.

Important Note

This implementation assumes non-negative values, because negative numbers cannot be used directly as array indices.

Program 12 — bucketsort.cpp

Aim

To sort an array using the Bucket Sort technique.

Concept

Bucket Sort distributes elements into different groups called buckets. Each bucket is sorted separately.

Detailed Working

A two-dimensional array bucket[10][10] is created.

count[10] stores the number of elements in each bucket.

For every element:

index = a[i] / 10;

The element is placed in the bucket represented by index.

Every bucket is individually sorted using nested loops and swapping.

The sorted buckets are traversed from bucket 0 to bucket 9.

Their elements are copied back into the original array.

The final array is printed.

Example:

29 -> bucket 2
25 -> bucket 2
3  -> bucket 0
49 -> bucket 4

Complexity

Depends on the distribution of values and the sorting used inside buckets.

Important Note

The current implementation is designed around 10 buckets and values whose quotient by 10 remains within the bucket range.

Program 13 — countsort.cpp

Aim

The filename suggests Counting Sort, but the current source code actually implements a Stack using an array.

Actual Concept Used

Stack

Array

LIFO

push

pop

peek

Overflow and underflow

Detailed Working

A Stack class is created.

It contains:

a[100] — stack storage.

top — index of the top element.

Initially:

top = -1;

push() increases top and inserts the element.

If top == 99, the stack is full and Stack Overflow is displayed.

pop() removes the top element and decreases top.

If top == -1, Stack Underflow is displayed.

peek() displays the current top element without removing it.

display() prints elements from top to bottom.

Complexity

Push: O(1)

Pop: O(1)

Peek: O(1)

Display: O(n)

Note

If the intention was to create Counting Sort, this file should be renamed/replaced with a Counting Sort implementation.

Program 14 — radixsortusinglinklist.cpp

Aim

To sort integers using Radix Sort with linked-list buckets.

Concept

Radix Sort processes numbers digit by digit, starting from the least significant digit.

Data Structure

Ten linked-list buckets are used:

Bucket 0
Bucket 1
...
Bucket 9

Each bucket maintains:

front

rear

Detailed Working

The user enters the number of elements and the elements.

getMax() finds the largest value.

The program starts with:

place = 1

representing the units digit.

For every number, the current digit is calculated:

digit = (a[i] / place) % 10;

The number is inserted into the corresponding linked-list bucket.

Buckets are collected from 0 through 9.

The array is updated.

place becomes 10, then 100, then 1000, etc.

The process continues until all digit positions have been processed.

Complexity

Approximately:
O(d(n + k))

where:

d = number of digits

n = number of elements

k = number of buckets, here 10.

Important Note

The implementation is intended for non-negative integers.

3. Linked List Programs

Program 15 — linklist.cpp

Aim

To implement a singly linked list with insertion, deletion, searching, and display operations.

Concept

A singly linked list consists of nodes where every node stores:

data

address of the next node

Structure:

[Data | Next] -> [Data | Next] -> NULL

Main Operations

push_front()

push_back()

push_midle()

pop_front()

pop_back()

search()

print()

Detailed Working

Push Front

A new node is created and connected before the current head.

New -> Old Head -> ...

Push Back

A new node is attached after the current tail.

Head -> ... -> Tail -> New

Push Middle

The program traverses to the desired position and inserts the new node between existing nodes.

Pop Front

The head node is removed and the head pointer moves to the next node.

Pop Back

The program traverses to the node before the tail, deletes the tail, and makes the previous node the new tail.

Search

The program traverses the list and checks each node's data.

Complexity

Insert at front: O(1)

Insert at back with tail pointer: O(1)

Delete front: O(1)

Delete back: O(n)

Search: O(n)

Traversal: O(n)

Program 16 — doublelinklist.cpp

Aim

To implement a doubly linked list.

Concept

Every node contains three parts:

[Previous | Data | Next]

Example:

NULL <- [10] <-> [20] <-> [30] -> NULL

Detailed Working

A node contains:

data

prev

next

head points to the first node.

tail points to the last node.

push_front() inserts at the beginning and updates the previous pointer.

push_back() inserts at the end and connects the new node in both directions.

pop_front() removes the first node.

pop_back() removes the last node.

print() displays the list.

Advantage

A doubly linked list can move in both directions.

Complexity

Insert front: O(1)

Insert back: O(1)

Delete front: O(1)

Delete back: O(1)

Search: O(n)

Program 17 — circularlinklist.cpp

Aim

To implement a circular singly linked list.

Concept

In a circular linked list, the last node does not point to NULL. Instead:

tail->next = head

Example:

Head -> 10 -> 20 -> 30
        ^         |
        |_________|

Detailed Working

The list maintains head and tail.

For the first node:

head = tail = newnode;
tail->next = head;

push_front() adds a node before the current head and updates tail->next.

push_back() adds a node after the current tail and connects it back to head.

pop_front() removes the first node.

pop_back() finds the node before the tail and makes it the new tail.

print() uses traversal until it reaches the head again.

Complexity

Insert front: O(1)

Insert back: O(1)

Delete front: O(1)

Delete back: O(n)

Traversal: O(n)

4. Stack Programs

Program 18 — stackusingarray.cpp

Aim

To implement a stack using an array.

Concept

A stack follows:

LIFO — Last In, First Out

Example:

Push 10
Push 20
Push 30

Top -> 30
       20
       10

If we perform pop(), 30 is removed first.

Detailed Working

An array of size 100 is created.

top keeps track of the top element.

Initially:

top = -1;

push():

checks overflow,

increases top,

stores the value.

pop():

checks underflow,

displays the top value,

decreases top.

peek() displays the top value without deleting it.

display() prints elements from top to bottom.

Complexity

Push: O(1)

Pop: O(1)

Peek: O(1)

Display: O(n)

Program 19 — stackusinglinklist.cpp

Aim

To implement a stack using a linked list.

Concept

A linked-list stack dynamically creates nodes rather than using a fixed-size array.

Detailed Working

Every node contains data and next.

head and tail are maintained.

push() creates a node and attaches it to the end.

pop() traverses to the node before the tail.

The tail node is deleted.

print() displays all nodes.

Important Observation

The current implementation performs pop() from the tail, but because the list is singly linked, it must traverse the list to find the previous node.

Complexity

Push: O(1)

Pop: O(n) in the current implementation

Display: O(n)

A more efficient linked-list stack would normally perform push and pop at the head, making both operations O(1).

5. Queue Programs

Program 20 — queueusingarray.cpp

Aim

To implement a queue using an array.

Concept

A queue follows:

FIFO — First In, First Out

Example:

Front -> 10 20 30 40 <- Rear

10 will be removed first.

Detailed Working

An array of size 100 is created.

r represents the rear position.

f represents the front position.

Initially:

r = -1;
f = -1;

enqueue() increases r and stores the value.

dequeue() checks whether the queue is empty.

If not empty, f is increased and the corresponding element is removed.

display() prints elements from f + 1 to r.

Complexity

Enqueue: O(1)

Dequeue: O(1)

Display: O(n)

Important Note

This is a simple linear queue. It does not reuse positions at the beginning after multiple deletions. A circular queue solves this limitation.

Program 21 — queueusinglinklist.cpp

Aim

To demonstrate queue-like insertion and deletion using a linked list.

Concept Used

Dynamic nodes

Linked list

Insertion at rear

Deletion at front

Detailed Working

A node contains data and next.

head points to the first node.

tail points to the last node.

push() inserts a node at the tail.

pop() removes the node from the head.

print() displays the list.

Complexity

Push: O(1)

Pop: O(1)

Display: O(n)

Important Note

Although the class in the source is named stack, its operation pattern is actually queue-like:

insertion at rear,

deletion from front.

Program 22 — queueusingdoublelinklist

Aim

To implement a queue using a doubly linked list.

Concept

Each node contains:

prev | data | next

The queue maintains:

head — front

tail — rear

Detailed Working

Enqueue

Create a new node.

If the queue is empty, both head and tail point to it.

Otherwise:

new node's prev points to tail,

old tail's next points to new node,

tail becomes the new node.

Dequeue

Check whether the queue is empty.

Store the head in a temporary pointer.

Move head to the next node.

Set the new head's prev to NULL.

Delete the old node.

If only one node existed, both head and tail become NULL.

Front

Displays the element at the head.

Rear

Displays the element at the tail.

Display

Traverses from head to tail.

Complexity

Enqueue: O(1)

Dequeue: O(1)

Front: O(1)

Rear: O(1)

Display: O(n)

Program 23 — cqa.cpp

Aim

To implement a circular queue using an array.

Concept

A circular queue connects the end of the array back to the beginning.

The modulo operator is used:

(rear + 1) % 5

Detailed Working

The queue has an array of size 5.

front and rear are initially -1.

Before insertion, the program checks:

(rear + 1) % 5 == front

If true, the queue is full.

For the first element, both front and rear become 0.

For subsequent elements, rear moves circularly.

dequeue() removes the front element.

Front also moves circularly.

If the last remaining element is deleted, both indices are reset to -1.

display() traverses from front to rear using modulo arithmetic.

Complexity

Enqueue: O(1)

Dequeue: O(1)

Display: O(n)

Advantage

A circular queue efficiently reuses empty positions created after deletion.

Program 24 — cicularqueuel.cpp

Aim

To implement a circular queue using a linked list.

Concept

The last node points back to the first node:

rear->next = front

Detailed Working

A node contains data and a next pointer.

The queue maintains front and rear.

For the first insertion:

front = rear = new node
rear->next = front

For later insertions:

new node is attached after rear,

rear is updated,

rear is connected back to front.

During deletion:

if empty, display queue empty,

if only one node exists, delete it and reset both pointers,

otherwise move front to the next node and reconnect rear to front.

display() uses a do-while loop because the list is circular.

Complexity

Enqueue: O(1)

Dequeue: O(1)

Display: O(n)

Program 25 — cicularqueueusinglinklist.cpp

Aim

To implement a circular queue using linked-list nodes.

Detailed Working

The source code follows the same circular linked-list queue structure as cicularqueuel.cpp.

A node stores data and next.

front represents the first element.

rear represents the last element.

rear->next always points to front.

enqueue() inserts at the rear.

dequeue() removes from the front.

display() traverses until it reaches the front again.

Complexity

Enqueue: O(1)

Dequeue: O(1)

Display: O(n)

Program 26 — cqll.cpp

Aim

To implement a circular queue using a linked list.

Concept

The program uses dynamic memory and maintains a circular connection between the rear and front nodes.

Detailed Working

Create a node using dynamic memory.

Maintain front and rear.

When the first node is inserted:

front = rear = node
rear->next = front

When another node is inserted:

attach it after rear,

update rear,

connect rear back to front.

During deletion, remove the front node.

If there is only one node, reset the queue.

Display the elements by traversing until the pointer reaches front again.

Complexity

Enqueue: O(1)

Dequeue: O(1)

Display: O(n)

Note

This file is another circular linked-list queue implementation in the repository.

6. Recursion Program

Program 27 — towerofhanoi.cpp

Aim

To solve the Tower of Hanoi problem using recursion.

Concept

Tower of Hanoi is a classic example of recursion.

There are three rods:

Source

Auxiliary

Destination

Rules

Only one disk can be moved at a time.

Only the top disk can be moved.

A larger disk cannot be placed on a smaller disk.

Detailed Working

For n disks:

Move n - 1 disks from source to auxiliary.

Move the largest disk from source to destination.

Move n - 1 disks from auxiliary to destination.

The function is:

towerOfHanoi(n, source, auxiliary, destination)

Base Case

When:

n == 1

the disk is directly moved from source to destination.

Recursive Case

For n > 1:

Move n-1 disks:
Source -> Auxiliary

Move disk n:
Source -> Destination

Move n-1 disks:
Auxiliary -> Destination

Minimum Number of Moves

2^n - 1

For example:

n = 1 -> 1 move
n = 2 -> 3 moves
n = 3 -> 7 moves
n = 4 -> 15 moves

Complexity

Time: O(2^n)

Space: O(n) recursion stack
