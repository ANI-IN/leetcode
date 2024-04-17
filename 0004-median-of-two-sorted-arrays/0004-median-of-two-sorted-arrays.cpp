class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        double ans=0.0;
        vector<int> a;
        int len=n+m;
        
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                a.push_back(nums1[i]);
                i++;
            }
            else
            {
                a.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i<n)
        {
            a.push_back(nums1[i]);
            i++;
                
        }
        
        while(j<m)
        {
            a.push_back(nums2[j]);
            j++;
        }
        
        
        if(len%2==1)
        {
            ans=a[len/2];
        }
        else
        {
            ans=(a[len/2]+a[len/2-1])/2.0;
        }
        
        return ans;
        
    }
};