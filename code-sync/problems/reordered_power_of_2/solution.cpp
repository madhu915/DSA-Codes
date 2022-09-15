class Solution {
public:
    vector<int>counts(int n){
        vector<int> res(10,0);
        while(n){
            res[n%10]++;
            n/=10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        vector<int>dig=counts(n);
        for(int pows=1,i=1;i<=30;i++,pows<<=1){
            if(dig==counts(pows))
                return true;
        }
        return false;
    }
};