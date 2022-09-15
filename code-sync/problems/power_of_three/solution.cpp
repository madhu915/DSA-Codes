class Solution {
public:
    bool res=false;
    bool isPowerOfThree(int n) {
        if(n<1)
            return false;
        if(n==1)
            return true;
        if(n%3==0){
            res=isPowerOfThree(n/3);
        }
        else
            return false;
        return res;
    }
};