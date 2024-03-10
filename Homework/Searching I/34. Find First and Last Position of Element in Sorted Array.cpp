class Solution {
    int lowerBound(vector<int>& arr, int target){
        int low=0;
        int high=arr.size()-1;
        int ans = -1;

        int mid =(low+high)/2;
        while(low<=high){
            if(target == arr[mid]){
                ans = mid;
                high = mid - 1;
            }
            else if(target < arr[mid]){
                high= mid -1;
            }
            else{
                low=mid + 1;
            }
            mid = (low+high)/2;
        }
        return ans;
    }

    int upperBound(vector<int>& arr, int target){
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;

        int  mid = (low+high)/2;
        while(low<=high){
            if(target == arr[mid]){
                ans = mid;
                low = mid + 1;
            }
            else if(target < arr[mid]){
                high= mid -1;
            }
            else{
                low=mid + 1;
            }
            mid =(low+high)/2;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lowerBound(nums,target);
        int ub=upperBound(nums,target);
        return{lb,ub};
    }
};