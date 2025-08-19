package javasrc;

import java.util.Arrays;

class LIS {
    private int n;
    private int[] nums;

    public int dfs(int i, int j) {
        if(i == n) return 0;

        int ans = dfs(i + 1, j);
        if(j == -1 || nums[j] < nums[i]) {
            ans = Math.max(ans, 1 + dfs(i + 1, i));
        }

        return ans;
    }

    public int iteration() {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(nums, 1);
        for(int i = n - 1; i <= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    Math.max(dp[i], 1 + dp[j]);
                }
            }
        }

        return Arrays.stream(nums).max().getAsInt();
    }


    public int lengthOfLIS(int[] nums) {
        this.n = nums.length;
        this.nums = nums;

        return dfs(0, -1);
    }

    public static void main(String[] args) {
        LIS lis = new LIS();
        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
        System.out.println(lis.lengthOfLIS(nums)); // Output: 4
    }
    
}