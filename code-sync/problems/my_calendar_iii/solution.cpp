class MyCalendarThree {
public:
    map<int,int>mp;
    int maxs=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++mp[start];
        --mp[end];
        int ct=0;
        for(auto kv:mp){
            ct+=(kv.second);
            maxs=max(ct,maxs);
        }
        return maxs;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */