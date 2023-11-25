class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        vector<int> presum;
        int n=nums.size();
        int sum=0;
        for(auto it : nums)
        {
            sum+=it;
            presum.push_back(sum);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int left=(i*nums[i])-(i>0?presum[i-1]:0);
            int right=(presum[n-1]-presum[i])-((n-i-1)*nums[i]);
            cout<<left<<" "<<right<<endl;
            ans.push_back(left+right);
        }
        return ans;
    }
};