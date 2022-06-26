#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int rows;
    cin>>rows;
    vector<vector<int> > ans(rows);
    for(int i=0; i<rows; i++) {
        vector<int> row(i+1,1);
        int mid=i >> 1;
        for(int j=1; j<=mid; j++) {
            int val=ans[i-1][j-1] + ans[i-1][j];
            row[j] = val;
            row[row.size()-j-1] = val;
        }
        ans[i]=row;
    }
    int spaces=rows;
    for(int i=0;i<ans.size();i++) {
        int k=spaces;
        while(k-->0){
            cout<<" ";
        }
        spaces--;
        for(int j=0;j<ans[i].size();j++) 
            cout << ans[i][j] << " ";
        cout<<endl;    
    }
    return 0;
}