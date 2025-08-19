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
}