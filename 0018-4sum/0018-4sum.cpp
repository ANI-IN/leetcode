class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            for(int j=i+1;j<n;j++)
            {
                if(j!=(i+1) && nums[j]==nums[j-1])
                    continue;
                
                int k=j+1;
                int z=n-1;
                
                while(k<z)
                {   
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[z];
                    if(sum<target)
                    {
                        k++;
                    }
                    else if(sum>target)
                    {
                        z--;
                    }
                    else
                    {
                        vector<int> temp={nums[i],nums[j],nums[k],nums[z]};
                        ans.push_back(temp);
                        
                        k++;
                        z--;
                        
                        while(k<z && nums[k]==nums[k-1])
                            k++;
                        while(z>k && nums[z]==nums[z+1])
                            z--;
                    }
                }
            }
            
        }
        return ans;
    }
};