/*
The problem statement given is as follows :

I have N buckets having 0 fruits in each bucket initially. 
I will give you n numbers denoting fruits required at nth position But you need to keep two simple rules:

Either you can increment fruit count by 1 in each bucket i.e. 
Incremental Operation or you can double the fruits in each bucket i.e. Doubling operation.

SAMPLE:

Input :
[2,3]

Output :
4

Explanation :
Initial state -> [0,0]
[1,0]
[1,1]
[2,2]
[2,3]

*/

#include <bits/stdc++.h>
using namespace std;

void increment(vector<int>& i,int pos){
    i[pos-1]+=1;
}
void doub(vector<int>& i){
    for(auto &x:i){
        x=x*2;
    }
}


int main()
{

    int size;
    cin>>size;
    
    vector<int>target(size,0);
    for(auto &i:target)
     cin>>i;
    
    // decrement the number of buckets by 1 if incremental (odd)
    // divide the number of buckets by 2 if doubling (even)

    int ct=0;

    //loop continues till all elements become 0
    while(count(target.begin(),target.end(),0)!=size){

        //check for odd initially and make all elements even
        for(int i=0;i<target.size();i++){
            if(target[i]%2==1){
                target[i]-=1;
                ct++;
            }
        }

        //since all are even divide by 2
        for(int i=0;i<target.size();i++)
            target[i]/=2;
        ct++;
    }

    cout<<"min operations="<<ct-1<<endl;

          
    return 0;
}