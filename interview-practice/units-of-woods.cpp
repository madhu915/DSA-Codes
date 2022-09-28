/*
PROBLEM STATEMENT:
We will be given heights of woods in an array and we need to get k units of wood

We need to cut at a certain point so that we minimum amount of wastage

{1,2,1,2} k=2

That means we need to collect 2 units of wood

The array is the heights of the wood

The ans is x=1 that is we need to cut at point 1 so that we get 2 units of wood and also wastage is 0
*/

#include<bits/stdc++.h>
using namespace std;

int woodcollected(vector<int>h,int n,int m){
    int sum=0;
    for (int i = n - 1; i >= 0; i--) {
        if (h[i] - m <= 0)
            break;
        sum += (h[i] - m);
    }
 
    return sum;
}

int collectKWood(vector<int> h,int n,int k){
    sort(h.begin(),h.end());
    int lu=0,ul=h[n-1];
    while(lu<=ul){
        int mid=lu+((ul-lu)/2);
        // calc amount of wood collected when cut made at mid
        int amt=woodcollected(h,n,mid);
        if(amt==k)
            return mid;
        else if(amt<k)
            ul=mid-1;
        else
            lu=mid+1;


    }
    return -1;
}
int main(){
    vector<int> height;
    int n,s,v ;
    int k ;
    cin>>s>>k;
    n=s;
    while(s-->0){
        cin>>v;
        height.push_back(v);
    }
     
    cout << collectKWood(height, n, k);
 
    return 0;
}
