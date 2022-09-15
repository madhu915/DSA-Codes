class Solution {
public:
    int totalNQueens(int n) {        
        vector<vector<string>> res;
        string s(n,'.');
        vector<string>board(n,s);
        vector<int> rows(n,0),left(2*n-1,0),right(2*n-1,0);
        nqueen(0,board,res,rows,left,right,n);
        return res.size();
    }
    void nqueen(int col,vector<string>&board,vector<vector<string>>&res,vector<int> rows,vector<int> left,vector<int> right,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){ //i as row no
            if(rows[i]==0&&left[i+col]==0&&right[n-1+col-i]==0){
                board[i][col]='Q';
                rows[i]=1;
                left[i+col]=1;
                right[n-1+col-i]=1;
                nqueen(col+1,board,res,rows,left,right,n);
                board[i][col]='.';
                rows[i]=0;
                left[i+col]=0;
                right[n-1+col-i]=0;
            }
        }
    }        
};