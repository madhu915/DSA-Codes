class Solution {
public:
    bool isPowerOfFour(int n) {
       
        return n>0 && ceil(log(n)/log(4))==floor(log(n)/log(4));
    }
};