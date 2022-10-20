/*
The Next greater Element for an element x is the first greater element on the right side of x in the array. 
Elements for which no greater element exist, consider the next greater element as -1. 
*/
#include<bits/stdc++.h>
using namespace std;
int nge(vector<int> arr,int in){
    // brute-force
        for(int j=in+1; j<arr.size();j++){
            if(arr[j]>arr[in])
                return arr[j];
        }
    
    return -1;
}
void print(vector<int>arr){
    //stack
    stack<pair<int,int>>s;
    s.push({arr[0],0});
    for(int i=1; i<arr.size();){
        if(s.empty()){
        //     break;
            s.push({arr[i],i});
            i++;
        //     continue;
        }

        while(i<arr.size() && arr[i]<=s.top().first){
            s.push({arr[i],i});
            i++;
        }

        if(i<arr.size()){
        while(!s.empty() && arr[i]>s.top().first){
            int j=s.top().second;
            arr[j]=arr[i];
            s.pop();
        }
        }

    }

    while(!s.empty()){
        int j=s.top().second;
        arr[j]=-1;
        s.pop();
    }
    for(auto i:arr)
        cout<<i<<" ";

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<arr.size();i++)
        cout<<nge(arr,i)<<" ";;
    print(arr);
    return 0;
}