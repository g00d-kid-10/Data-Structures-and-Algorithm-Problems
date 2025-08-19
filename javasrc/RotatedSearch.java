package javasrc;

import javasrc.RSA;
import javasrc.BinarySearch;

class RotatedSearch {
    static int rotatedSearch(int i, int j, int[] nums, int value) {
        int ans = -1;
        int p = new RSA(nums).pivot();
        int n = nums.length;

        if(p == 0) {
            ans = new BinarySearch(0, n - 1, nums).search(value);
            return ans;
        } else {
            ans = new BinarySearch(p, n - 1, nums).search(value);
            if(ans != -1) {
                return ans;
            }

            ans = new BinarySearch(0, p, nums).search(value);
            if(ans != -1) {
                return ans;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        int value = 0;
        int index = rotatedSearch(0, nums.length - 1, nums, value);
        System.out.println("Index of " + value + ": " + index); // Output: Index of 0: 4
    }
}