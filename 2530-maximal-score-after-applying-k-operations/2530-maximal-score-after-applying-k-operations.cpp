class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size() ; 
        
        priority_queue<int>pq; 
        
        for(auto it : nums) 
            pq.push(it) ; 
        
       long long ans = 0 ; 
        
        while (k--) { 
           int maxi = pq.top() ; 
            
            
            ans += maxi ; 
            
            if (maxi ==  1) 
                return ans + k  ; 
            
            pq.pop() ; 
            
            pq.push((maxi +2)/3)  ; 
        }
        return ans ; 
    }
};