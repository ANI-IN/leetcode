class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> s;
        int sum=0;
        int t=0;
        int n=nums.size();
        for(auto it : nums)
        {   
            sum+=it;
            if(s.count(it)==1)
            {
                t=it;
                
            }
            s.insert(it);
        }
        
        int maxi=(n*(n+1))/2;
        cout<<t;
        sum=sum-t;
        
        int m=maxi-sum;
        
        return {t,m};
        
        
        
        
    }
};