class Solution {
public:
    int minimumSize(vector<int>& nums, int o) {
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;
        int ans = high;
        while(low < high) {
            int penalty = (low + high) / 2;
            int ops = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] > penalty) {
                    if(nums[i] % penalty == 0) {
                        ops += nums[i] / penalty - 1;
                    } else {
                    ops += nums[i] / penalty;
                    }
                }
            }
            if(ops <= o) {
                ans = penalty;
                high = penalty;
            } else {
                low = penalty + 1;
            }
        }
        return ans;
    }
};