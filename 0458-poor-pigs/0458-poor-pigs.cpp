class Solution {
public:
    int poorPigs(int buckets, int T, int TT) {
        
        int t=TT/T+1;
        
        int pig=0;
        int count=0;
        while(pow(t,pig)<buckets)
        {
            count++;
            pig++;
        }
        return count;
    }
};