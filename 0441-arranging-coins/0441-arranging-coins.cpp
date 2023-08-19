class Solution {
public:
    int arrangeCoins(int n) {
        int low=0,high=n;
        
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long ans=(mid*(mid+1)/2);
            
            if(ans==n)
                return mid;
            else if(ans>n)
                high=mid-1;
            else
                low=mid+1;
        }
        return high;
    }
};