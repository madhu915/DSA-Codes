class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {efficiency[i], speed[i]};
        }
        sort(arr.rbegin(), arr.rend()); //sorted in reverse order
        priority_queue<int, vector<int>, greater<int>>pq; //minheap
        long ans = INT_MIN, sum = 0;
        for(int i=0; i<n; i++){
            int eff = arr[i].first, speed = arr[i].second;
            sum += speed;
            pq.push(speed);
            
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop(); //least is eliminated to calc max performance
            }
            ans = max(ans, sum*eff);
        }
        return ans%((int)1e9+7);
    }
};