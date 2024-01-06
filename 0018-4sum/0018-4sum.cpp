class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1])
                    continue;
                int k=j+1;
                int h=n-1;
                
                while(k<h)
                {
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[h];
                    
                    if(sum<target)
                    {
                        k++;
                    }
                    else if(sum>target)
                    {
                        h--;
                    }
                    else
                    {
                        vector<int> temp{nums[i],nums[j],nums[k],nums[h]};
                        ans.push_back(temp);
                        
                        k++;
                        h--;
                        
                        while(k<h && nums[k]==nums[k-1])
                            k++;
                        
                        while(h>k && nums[h]==nums[h+1])
                            h--;
                    }
                }
            }
           
                
        }
         return ans;
    }
};