class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n,'.');
        vector<string>board(n,s);
        nqueen(0,board,res,n);
        return res;
    }
    void nqueen(int col,vector<string>&board,vector<vector<string>>&res,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){ //i as row no
            if(safe(col,i,board,n)){
                board[i][col]='Q';
                nqueen(col+1,board,res,n);
                board[i][col]='.';
            }
        }
    }
    
    bool safe(int col,int row,vector<string>&board,int n){
        int x=row,y=col;
        while(x>=0&&y>=0)    //left diagonal
            if(board[x--][y--]=='Q')
                return false;
        x=row;
        y=col;
        while(x<n&&y>=0)    //right diag
            if(board[x++][y--]=='Q')
                return false;
        while(col>=0)
            if(board[row][col--]=='Q')
                return false;
        return true;
    }  
};