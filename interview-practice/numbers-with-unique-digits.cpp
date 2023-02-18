#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        string num=to_string(i);
        set<char>digs(num.begin(),num.end());
        if(digs.size()==num.size())
            cout<<i<<" ";
    }
}