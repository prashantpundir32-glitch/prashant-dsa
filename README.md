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
