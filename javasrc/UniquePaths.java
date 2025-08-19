package javasrc;

import java.util.HashMap;
import java.util.Map;

class UniquePaths {
    int m, n;
    int[][] dirs = {{1, 0}, {0, 1}};
    Map<Long, Integer> cache = new HashMap<>();

    public int dfs(int r, int c) {
        // out of bound
        if(r >= m || c >= n) return 0;

        // reached condition
        if(r == m - 1 && c == n - 1) return 1;

        // caching
        Long key = (((long) r) << 32) | (c & (((long) 1) << 32) - 1);
        if(cache.containsKey(key)) return cache.get(key);

        // explore recursion
        int ans = 0;
        for(int[] dir : dirs) {
            ans += dfs(r + dir[0], c + dir[1]);
        }
        
        cache.put(key, ans);
        return ans;
    }
    
    public int uniquePaths(int m, int n) {
        this.m = m;
        this.n = n;

        return dfs(0, 0);
    }

    public static void main(String[] args) {
        UniquePaths up = new UniquePaths();
        System.out.println(up.uniquePaths(3, 7)); // Output: 28
    }
    
}