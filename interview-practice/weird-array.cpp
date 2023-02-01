/*
PROBLEM

A weird number x and size of array is atleast 2. A number x is weird if the count of x is greater than the count of any other element in array
Eg [1,2,1,3,3,4,1,2] is a weird array with 1 as the weird number (x).
Find the minimum size of weird subarray array or
return 0 if no subarray exists.

Function mast return the minimum size of weird subarray array or return 0 if no subarray exists.

'weird_array' has the following parameter (s) :
input: - list of numbers
n:- length of list or array

**EXAMPLE: **
Input: - [3 3 1 3 3]
Output: - 2
Explanation: - [3,3] is the minimum subarray possible

Input: - [5]
Output: - 0
Explanation: - No weird subarray is possible.

*/ 

#include<bits/stdc++.h>
using namespace std;
