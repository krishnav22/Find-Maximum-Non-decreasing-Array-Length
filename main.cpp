class Solution {
public:    
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        
        
        vector<long long> pref(n + 1); 
        pref[0] = 0;
        for(int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i]; 
        
        vector<pair<int, long long>> dp(n + 2); 
        
        
        dp[0].first = 1; 
        for(int i = 1; i <= n; i++) {
            
            dp[i] = max(dp[i], dp[i - 1]); 
            
            
            int idx = lower_bound(pref.begin(), pref.end(), 2 * pref[i] - dp[i].second) - pref.begin();
            
            
            dp[idx] = max(dp[idx], {dp[i].first + 1, pref[i]}); 
        }
        return dp[n].first; 
    }
};
