class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        int len=n+m;
        int e1,e2,k=0;
        
        int pos1,pos2;
        
        pos1=len/2;
        pos2=len/2-1;
        
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(nums1[i] < nums2[j])
            {
                if(pos1==k)
                    e1=nums1[i];
                if(pos2==k)
                    e2=nums1[i];
                i++;        
            }
            else
            {
                if(pos1==k)
                    e1=nums2[j];
                if(pos2==k)
                    e2=nums2[j];
                j++;
            }
            k++;
        }
        
        while(i<n)
        {
            if(pos1==k)
                    e1=nums1[i];
            if(pos2==k)
                    e2=nums1[i];
            i++;
            k++;   
        }
        
        while(j<m)
        {
            if(pos1==k)
                    e1=nums2[j];
            if(pos2==k)
                    e2=nums2[j];
            j++;
            k++;      
        }
        
        double ans=0.0;
        if(len%2==1)
        {
            ans=e1;
            return ans;
        }
        else
        {
            ans=(e1+e2)/2.0;
            return ans;
        }
    }
};