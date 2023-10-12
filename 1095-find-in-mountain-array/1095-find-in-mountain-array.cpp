/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int left=1;
        int n=arr.length();
        int right=n-2;
        int p=-1;
        int curr,prev,next;
        while(left<=right){
            int mid=left+(right-left)/2;
            curr=arr.get(mid);
            prev=arr.get(mid-1);
            next=arr.get(mid+1);
            if(curr>next && curr>prev){
                if(curr==target) return mid;
                p=mid;
                break;
            }
            else if(curr>prev){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        // got the peak index
        int tarIndex=-1;
        left=0;
        right=p-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            curr=arr.get(mid);
            if(curr==target){
                return mid;
            }
            else if(curr>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        left=p+1;
        right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            curr=arr.get(mid);
            if(curr==target){
                return mid;
            }
            else if(curr<target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return -1;
    }
};