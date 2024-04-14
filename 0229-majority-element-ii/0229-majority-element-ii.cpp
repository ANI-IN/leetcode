class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int e1=0,c1=0;
        int e2=0,c2=0;
        int count=n/3;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(c1==0 && e2!=nums[i])
            {
                c1=1;
                e1=nums[i];
            }
            else if(c2==0 && e1!=nums[i])
            {
                c2=1;
                e2=nums[i];
            }
            else if(e1==nums[i])
            {
                c1++;
            }
            else if(e2==nums[i])
            {
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(e1==nums[i])
                c1++;
            else if(e2==nums[i])
                c2++;
            
        }
        
        if(c1>count)
            ans.push_back(e1);
        if(c2>count)
            ans.push_back(e2);
        
        return ans;
        
        
    }
};