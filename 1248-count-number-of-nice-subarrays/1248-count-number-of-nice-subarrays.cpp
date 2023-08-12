class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        
        int i=0,j=0;
        int sum=0;
        int curr=0;
        m[0]=1;
        while(j<n)
        {   
            sum=sum+(nums[j]%2);
            if(m.find(sum-k)!=m.end())
            {
                curr+=m[sum-k];
            }
            m[sum]++;
            j++;
        }
        return curr;
    }
};