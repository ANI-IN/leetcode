class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int len=n+m-1;
        int p1=m-1;
        int p2=n-1;
        
        
        while(p1>=0 && p2>=0)
        {
            if(nums1[p1] >= nums2[p2])
            {
                nums1[len]=nums1[p1];
                p1--;
                len--;
            }
            else
            {
                nums1[len]=nums2[p2];
                p2--;
                len--;
            }
        }
        
        
        
        while(p2>=0)
        {
            nums1[len]=nums2[p2];
            p2--;
            len--;
        }
        
    }
};