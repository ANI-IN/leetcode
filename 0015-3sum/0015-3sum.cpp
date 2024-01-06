class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {   
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int j=i+1;
            int k=n-1;
            int x=nums[i];
            while(j<k)
            {
                int sum=x+nums[j]+nums[k];
                
                if(sum>0)
                {
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
                else
                {
                    vector<int>temp{x,nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                        j++;
                    
                    while(k>j && nums[k]==nums[k+1])
                        k--;
                }
            }
        }
        return ans;
    }
};