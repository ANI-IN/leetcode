class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int e1=0,c1=0;
        int e2=0,c2=0;
        int c=n/3;
        
        
        for(int i=0;i<n;i++)
        {
            if(c1==0 && e2!=nums[i])
            {
                e1=nums[i];
                c1=1;
            }
            else if(c2==0 && e1!=nums[i])
            {
                e2=nums[i];
                c2=1;
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
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(e1==nums[i])c1++;
            else if(e2==nums[i])c2++;
        }
        if(c1>c)
            ans.push_back(e1);
        if(c2>c)
            ans.push_back(e2);
        
        return ans;
    }
};