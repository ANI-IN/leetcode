class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        
        vector<int> temp;
        for(int i=n-k;i<n;i++)
            temp.push_back(nums[i]);
        
        
        
        int i=n-k-1;
        
        int index=n-1;
        while(i>=0)
        {   
            cout<<nums[i];
            nums[index--]=nums[i--];
           
        }
        
    
        
    index=0;
        for(int i=0;i<k;i++)
        {
            nums[i]=temp[index++];
        }
        
    }
};