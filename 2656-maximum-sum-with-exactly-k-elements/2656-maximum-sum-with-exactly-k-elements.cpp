class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        
        int sum=maxi;
        for(int i=1;i<k;i++)
        {       
            maxi++;
            sum=sum+maxi;
          
            
        }
        return sum;
    }
};