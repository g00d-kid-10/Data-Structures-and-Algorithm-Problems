class SubArray {
    private int[] nums;
    private int n;

    SubArray(int[] nums) {this.nums = nums; this.n = nums.length;}

    public int minimum() {
        int ans = Integer.MAX_VALUE;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(nums[i] < sum) {
                sum = nums[i];
            }

            ans = Math.min(ans, sum);
        }

        return ans;
    }

    public int maximum() {
        int ans = Integer.MIN_VALUE;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(nums[i] > sum) {
                sum = nums[i];
            }

            ans = Math.max(ans, sum);
        }

        return ans;
    }

    public static void main(String[] args) {
        SubArray obj = new SubArray(new int[]{0, -2, 3, 0, -5, 1});
        int ans = obj.minimum();
        System.out.println(ans);
    }
}


