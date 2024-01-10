class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vector<int>num;
    
        for(int i=0;i<bank.size();i++)
        {   
            int cnt=0;
            for(int j=0;j<bank[0].size();j++)
            {
                if(bank[i][j]=='1')
                {
                    cnt++;
                }
            }
            if(cnt>0)
                num.push_back(cnt);
        }
    
        if(num.size()<=1)
            return 0;
        long long sum=0;
        for(int i=0;i<num.size()-1;i++)
        {
             sum+=(num[i]*num[i+1]);
        }
        return sum;
    }
};