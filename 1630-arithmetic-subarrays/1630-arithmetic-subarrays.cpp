class Solution {
    bool solve(vector<int>nums)
    {   
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int d=nums[1]-nums[0];
        
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]!=d)
                return false;
        }
        return true;
    }
    
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        int m=l.size();
        
        vector<bool> result;
        for(int i=0;i<m;i++)
        {
            vector<int> arr(begin(nums)+l[i],begin(nums)+r[i]+1);
            
            result.push_back(solve(arr));
        }
        return result;
    }
};