class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int e=0,c=0;
        
        
        int x=n/2;
        for(int i=0;i<n;i++)
        {
            if(c>x)
                return e;
            
            if(c==0)
            {
                e=nums[i];
                c=1;
            }
            else if(nums[i]==e)
            {
                c++;
            }
            else
            {
                c--;
            }
            
        }
        return e;
    }
};