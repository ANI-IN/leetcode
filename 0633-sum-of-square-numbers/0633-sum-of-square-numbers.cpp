class Solution {
    long long f(int low, int high)
    {
        return (low*low) + (high*high);
    }
public:
    bool judgeSquareSum(int c) {
        
            if(c<0)
    		return false;
    	long int left=0,right=sqrt(c);
    	while(left<=right)
    	{
    		long int cur=left*left+right*right;
    		if(cur<c)
    			left++;
    		else if(cur>c)
    			right--;
    		else 
    			return true;
    	}    
    	return false;
    }
};