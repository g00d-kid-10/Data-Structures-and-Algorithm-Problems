package javasrc;

class RSA {
    private final int[] nums;
    private final int n;

    RSA(int[] nums) {
        this.nums = nums;
        this.n = nums.length;
    }

    public int pivot() {
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return r;
    }

    public static void main(String[] args) {
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        RSA rsa = new RSA(nums);
        int pivotIndex = rsa.pivot();
        System.out.println("Pivot index: " + pivotIndex); // Output: Pivot index: 4
    }
}