class Solution {

int peakElement(vector<int>& nums, int low, int high){

    while(low < high){
        int target = low + (high-low)/2;

        if (nums[target] > nums[target+1]){
            high = target;
        }
        else{
            low = target+1;
        }
    }
    return low;
}

public:
    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size()-1;
        return peakElement(nums, low, high);
    }
};