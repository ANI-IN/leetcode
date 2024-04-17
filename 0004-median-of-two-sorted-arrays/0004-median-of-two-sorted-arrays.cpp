class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        double ans=0.0;
      
        int len=n+m;
        
        int index1=len/2;
        int index2=index1-1;
        int e1=-1,e2=-1;
        int count=0;
        
        
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {   
                if(count==index1) e1=nums1[i];
                if(count==index2) e2=nums1[i];
                count++;
                i++;
            }
            else
            {   
                if(count==index1) e1=nums2[j];
                if(count==index2) e2=nums2[j];
                count++;
                j++;
            }
        }
        
        while(i<n)
        {
            if(count==index1) e1=nums1[i];
            if(count==index2) e2=nums1[i];
            count++;
            i++;
                
        }
        
        while(j<m)
        {
            if(count==index1) e1=nums2[j];
            if(count==index2) e2=nums2[j];
            count++;
            j++;
        }
        
        
        if(len%2==1)
        {
            ans=e1;
        }
        else
        {
            ans=(double)(e1+e2)/2.0;
        }
        
        return ans;
        
    }
};