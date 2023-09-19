#include<bits/stdc++.h>
#include<vector>
using namespace std;

string pascal(vector<int>arr){
    queue<int>q;
     
    for(auto x: arr){
        q.push(x);
    }
    
    while(q.size() != 2){
        int n = q.size();
        while(--n){
            // take the adjacent elements
            int a= q.front();
            q.pop();

            int b = q.front();
            // compute sum
            int sum = (a%10) + (b%10);
            sum = sum%10;
            q.push(sum);
        }
        // pop the last digit as well since no more adjacent elements left
        q.pop();
    }
     
    int a= q.front();
    q.pop();
    int b = q.front();
    string ans = "";
    ans+=to_string(a);
    ans+=to_string(b);
     
    return ans;
}
int main(){
    vector<int> numbers = {1,9,4};
    cout << "Pascal's Triangle : "<<pascal(numbers)<<endl;
    return 0;
}