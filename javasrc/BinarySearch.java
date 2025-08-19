package javasrc;

class BinarySearch {
    private final int[] nums;
    private final int n;
    private int l, r;

    BinarySearch(int[] nums) {
        this.nums = nums;
        this.n = nums.length;
        this.l = 0;
        this.r = n - 1;
    }

    BinarySearch(int l, int r, int[] nums) {
        this.nums = nums;
        this.n = nums.length;
        this.l = l;
        this.r = r;
    }

    int search(int value) {
        int ans = -1;

        while(l <= r) {
            int m = (l + r) / 2;

            if(value < nums[m]) {
                r = m - 1;
            } else if(value > nums[m]) {
                l = m + 1;
            } else if(value == nums[m]){
                return m;
            }
        }

        return ans;
    }
}