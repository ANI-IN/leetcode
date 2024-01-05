class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int x=n/2;
        
        int e=0;
        int c=0;
        
        for(int i=0;i<n;i++)
        {   
            if(c>x)
                return e;
            if(c==0)
            {
                c++;
                e=nums[i];
            }
            else if(e==nums[i])
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