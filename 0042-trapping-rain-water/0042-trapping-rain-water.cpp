class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        
        int i=0,j=n-1;
        int lm=0,rm=0;
        int res=0;
        while(i<=j)
        {
            if(arr[i]<=arr[j])
            {
                if(arr[i]>=lm)
                    lm=arr[i];
                else
                    res+=lm-arr[i];
                    
                i++;
            }
            else
            {
                if(arr[j]>=rm)
                    rm=arr[j];
                else
                    res+=rm-arr[j];
                
                j--;
            }
            
        }
        return res;
    }
};