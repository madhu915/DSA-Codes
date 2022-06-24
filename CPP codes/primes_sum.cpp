#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
   	long long int prime_Sum(int n){
        vector<bool>vis(n+1, true);
   		long long int sum = 0;
   		for(int i = 2; i * i <= n; i++)
   			if(vis[i])
   				for(int j = i*i; j <= n; j+=i)
   					vis[j] = false;
   		for(int i = 2; i <= n; i++)
   			if(vis[i])
   				sum += i;
   		return sum; 
   	}    
};

// { Driver Code Starts.
int main(){
	
		int n;
		cin >> n;
		Solution ob;
		long long int ans = ob.prime_Sum(n);
		cout << ans <<"\n";
	  
		return 0;
}  // } Driver Code Ends