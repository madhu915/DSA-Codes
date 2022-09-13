class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int ct=0;
        for(auto i:data){
            if(ct==0){
               if((i>>5)==0b110)
                   ct=1;
               else if((i>>4)==0b1110)
                   ct=2;
               else if((i>>3)==0b11110)
                   ct=3;               
               else if(i>>7)
                   return false;
            }

            else{
               
                if((i>>6)!=0b10)
                    return false;
                ct--;
            }       
            
        }
        return ct==0;
    }
};