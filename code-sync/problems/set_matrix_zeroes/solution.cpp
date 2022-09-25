class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool RowZero = false,ColZero = false;
        //keep row0 and col0 as flags
        int n=matrix.size(),m=matrix[0].size();
        for (int i = 0; i < m; i++)
        { 
            if (matrix[0][i] == 0) 
            {
                RowZero = true;
                break;
            } 
        }
        
        for (int i = 0; i < n; i++)
        { 
            if (matrix[i][0] == 0) 
            {
                ColZero = true;
                break;
            } 
        }
        
        for (int i = 1; i < n; i++)
        { 
            for (int j = 1; j < m; j++) 
            {    
                if (matrix[i][j] == 0) 
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }        
            }
        }
        
        for (int i = 1; i < n; i++) //process except the first row and column 
        {
           for (int j = 1; j < m; j++)
           {
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
               {
                   matrix[i][j] = 0;
           
               }
           }
        }
        
        //zeroes in row0 
        if(RowZero)
        { 
            for (int i = 0; i < m; i++) 
            {
                matrix[0][i] = 0;
            }
        }
        
        //zeroes in col0
        
        if (ColZero) //handle the first column
        { 
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};