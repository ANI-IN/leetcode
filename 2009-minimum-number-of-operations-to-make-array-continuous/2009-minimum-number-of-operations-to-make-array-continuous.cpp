class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=n-1;
        
        sort(nums.begin(), nums.end());
        
        auto it=unique(nums.begin(), nums.end());
        
        nums.erase(it, nums.end());
        
        int m=nums.size(), k=n-m;
   

     
        for(int i=0, j=0; i<m; i++){
            while(j<m && nums[j]<nums[i]+n){ 
                j++;
            }
            ans=min(ans, n-j+i);
        }  
        return ans;
    }
};