class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int element1=0,element2=0,count1=0,count2=0;
        int n=nums.size();
        int c=n/3;
        for(int i=0;i<n;i++)
        {
            if(count1==0 && element2!=nums[i])
            {
                count1=1;
                element1=nums[i];
            }
            else if(count2==0 && element1!=nums[i])
            {
                count2=1;
                element2=nums[i];
            }
            else if(element1==nums[i])
            {
                count1++;
            }
            else if(element2==nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
            count1=0,count2=0;
            for(int i=0;i<n;i++)
            {
                if(element1==nums[i])
                    count1++;
                else if(element2==nums[i])
                    count2++;
            }
            
            if(count1>c)
                ans.push_back(element1);
            if(count2>c)
                ans.push_back(element2);
            
            return ans;
    }
};