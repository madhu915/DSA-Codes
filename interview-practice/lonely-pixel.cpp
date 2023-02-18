/*
PROBLEM STATEMENT

Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.
A black lonely pixel is a character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:
Input: picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
Output: 3
Explanation: All the three 'B's are black lonely pixels.
*/
#include<bits/stdc++.h>
using namespace std;

int lpixie(vector<vector<char>>pix,int m,int n){
    // create 2 vectors for tracking rows and cols of Bs
    vector<int>rows(m,0);
    vector<int>cols(n,0);
    int ans=0;

    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
         if(pix[i][j]=='B'){
            rows[i]++;
            cols[j]++;
         }
          
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pix[i][j]=='B' and rows[i]==1 and cols[j]==1)
             ans++;
        }
    }

    return ans;

    
}
int main(){
    vector<vector<char>>pix{{'W','W','W'},{'W','W','W'},{'B','B','W'}};

    cout<<lpixie(pix,3,3);

    return 0;
}