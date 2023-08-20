class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> arr={1};
        int i=2;
        
        bool t;
        while(arr.size()<n)
        {
            t=1;
            for(auto it : arr)
            {
                if(it+i==k)
                {
                    t=0;
                    break;
                }
            }
            if(t)
                arr.push_back(i);
            i++;
        }
        int sum=0;
        for(auto it : arr)
            sum+=it;
        return sum;
    }
};