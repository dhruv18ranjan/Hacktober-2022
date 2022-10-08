#define mod 10**9+7

class Solution {
public:
    
    long long solve(int dices,int faces, int target,vector<vector<long long>> &dp){
        
        if(target < 0) return 0  ;
        if(target==0 && dices!=0) return 0;
        if(target!=0 && dices==0) return 0 ;
        if(target==0 && dices==0) return 1 ;
        
        if(dp[dices][target]!=-1) return dp[dices][target];
        
        long long ans=0;
        for(int i=1; i<=faces; i++)
            ans=ans+solve(dices-1,faces,target-i,dp) %1000000007 ;
        
        return dp[dices][target]= ans%1000000007;
        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<long long>> dp(n+1,vector<long long> (target+1,-1));
        return solve(n,k,target,dp) %1000000007 ;
                               
                    
        
    }
};
