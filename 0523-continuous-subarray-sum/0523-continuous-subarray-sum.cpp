class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map <int,int> m;
        int sum=0,rem=0;
        
        m[0]=-1;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum+=nums[i];
            rem=sum%k;
            
            if(m.find(rem)!=m.end() && i-m[rem] > 1) 
                return true;
            
            if(m.find(rem)==m.end())
                m[rem]=i;
        }
        return false;
    }
};