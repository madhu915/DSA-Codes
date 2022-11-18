#include <bits/stdc++.h>
using namespace std;


void type2(int x,int m,vector<int>arr){
    int ct=0;
    for(auto &i:arr){
        if(i%m==x)
         ct++;
    }
    cout<<ct<<"\n";
}

int main() {
	// your code goes here
	long long n,m;
	int x=0;
	cin>>n>>m;
	vector<long long>arr(n);
	map<int, long long>index;
	
	for(auto &i:arr){
	    cin>>i;
	    index[x++]=i;
	}
	long long q;
	cin>>q;
	vector<long long>mps(1e5+1,0);
	for(int i=0;i<n;i++){
	    mps[arr[i]%m]++;
	}
	int q1,q2,q3;
	while(q--){
	    cin>>q1;
	    if(q1==2){
	        cin>>q2;
	        cout<<mps[q2]<<"\n";
	    }
	    else{
	        
	        cin>>q2>>q3;
	        long long pval=index[q2-1];
	        mps[pval%m]--;
	        index[q2-1]=q3;
	        mps[q3%m]++;
	    }
	}
	
	return 0;
}
