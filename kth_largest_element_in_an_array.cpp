class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> maxHeap;

        for(int i = 0; i < nums.size(); i++){
            maxHeap.push(nums[i]);
        }

        int n = 0;
        
        while(n != k-1){
            maxHeap.pop();
            n++;
        }

        return maxHeap.top();
        
    }
};