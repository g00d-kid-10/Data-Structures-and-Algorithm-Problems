class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        int anotherSlow = 0;
        while(slow == anotherSlow) {
            slow = nums[slow];
            anotherSlow = nums[anotherSlow];                
        }

        return slow;
    }
};