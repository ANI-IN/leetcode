class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int x=abs(sx-fx);
        int y=abs(sy-fy);
        
        int d=min(x,y)+abs(x-y);
        
        if(d==0)
            if(t>1 || t==0)
                return true;
        else
            return false;
        
        return t>=d;
    }
};