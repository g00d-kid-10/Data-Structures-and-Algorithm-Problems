package javasrc;

import java.util.ArrayList;
import java.util.List;

class CombinationSum {
    int target;
    int[] nums;
    int n;
    List<List<Integer>> ans = new ArrayList<List<Integer>>();

    void dfs(int i, int sum, List<Integer> temp) {
        if(i >= n) {
            return;
        }

        if(sum >= target) {
            if(sum == target) {
                ans.add(new ArrayList<>(temp));
            }
            return;
        }

        temp.add(nums[i]);
        dfs(i, sum + nums[i], temp);
        temp.remove(temp.size() - 1);
        
        dfs(i + 1, sum, temp);
    }
    
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        this.nums = nums; this.n = nums.length;
        this.target = target;
        dfs(0, 0, new ArrayList<>());
        return ans;
    }

    public static void main(String[] args) {
        CombinationSum cs = new CombinationSum();
        int[] nums = {2, 3, 6, 7};
        int target = 7;
        List<List<Integer>> result = cs.combinationSum(nums, target);
        System.out.println(result);
    }

}