package javasrc;

class MaximumSubArray {
    public int maxSubArray(int[] nums) {
        int maxSum = 0, sum = 0;
        for(int num : nums) {
            sum += num;
            if(sum < 0) {
                sum = 0;
            }

            maxSum = Math.max(maxSum, sum);
        }

        return maxSum;
    }

    public static void main(String[] args) {
        MaximumSubArray solution = new MaximumSubArray();
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("Maximum Subarray Sum: " + solution.maxSubArray(nums)); // Output: 6
    }
    
}