class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre_prod=1;
        int suff_prod=1;
        int maxi=INT_MIN;;
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            pre_prod=pre_prod*nums[i];
            suff_prod=suff_prod*nums[n-i-1];
            maxi=max(maxi,max(pre_prod,suff_prod));
            if(pre_prod==0)
                pre_prod=1;
            else if(suff_prod==0)
                suff_prod=1;
            
            
        }
        return maxi;
    }
};