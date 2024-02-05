class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        
        vector<int> ans;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            
            while(!ans.empty() && arr[i]<0 && ans.back()>0)
            {
                int sum=ans.back()+arr[i];
                
                if(sum<0)
                {
                    ans.pop_back();
                }
                else if(sum>0)
                {
                    arr[i]=0;
                }
                else
                {
                    ans.pop_back();
                    arr[i]=0;
                }
            }
            if(arr[i]!=0)
                ans.push_back(arr[i]);
                
        }
        return ans;
        
    }
};