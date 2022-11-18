/*
Problem
Initially, Chef is at coordinate 00 on X-axis. For each i = 1, 2, \dots, Ni=1,2,…,N in order, Chef does the following:

If Chef is at a non-negative coordinate, he moves ii steps backward (i.e, his position's coordinate decreases by ii), otherwise he moves ii steps forward (i.e, his position's coordinate increases by ii).
You are given the integer NN. Find the final position of Chef on the X-axis after NN operations.

Input Format
The first line of input contains an integer TT, denoting the number of test cases. The TT test cases then follow:
The first and only line of each test case contains an integer NN.
Output Format
For each test case, output in a single line the final position of Chef on the X-axis after NN operations.

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
1 \leq N \leq 10^91≤N≤10 
9
 
Sample 1:
Input
Output
3
1
2
3
-1
1
-2
Explanation:
Test case 11: Initially, Chef is at coordinate 00 on X-axis. As 00 is non-negative, during the first operation Chef moves 11 step backward and reaches the coordinate -1−1.

Test case 22: Chef is at coordinate -1−1 on X-axis after the first operation. As -1−1 is negative, during the second operation Chef moves 22 steps forward and reaches the coordinate 11.
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
    // throws TLE 
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	   int res=0,i=0;
	   while(++i<=n){
	       if(res>=0)
	        res-=i;
	       else
	        res+=i;
	   }	 
	   cout<<res<<endl;
	}
	return 0;
}

void alter(){
    int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	  
	    if(n%2==0)
	     cout<<n/2<<endl;
	    else
	     cout<<-n/2-1<<endl;
	}
}
