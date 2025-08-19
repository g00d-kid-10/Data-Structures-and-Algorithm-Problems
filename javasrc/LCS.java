package javasrc;

import java.util.HashMap;
import java.util.Map;

class LCS {
    private String text1, text2;
    private int n, m;
    private Map<Long, Integer> cache;


    public int dfs(int i, int j) {
        if(i == n || j == m) return 0;

        Long key = ((long) i << 32) | (j & 0xffffffffL);
        if(cache.containsKey(key)) return cache.get(key);

        int ans = 0;
        if(text1.charAt(i) == text2.charAt(j)) {
            ans = 1 + dfs(i + 1, j + 1);
        } else {
            ans = Math.max(dfs(i + 1, j), dfs(i, j + 1));
        }

        cache.put(key, ans);
        return ans;
    }


    public int longestCommonSubsequence(String text1, String text2) {
        this.text1 = text1;
        this.text2 = text2;
        this.n = text1.length();
        this.m = text2.length();
        
        if(text1.equals(text2)) return n;
        
        this.cache = new HashMap<>();
        return dfs(0, 0);
    }

    public static void main(String[] args) {
        LCS lcs = new LCS();
        String text1 = "abcde";
        String text2 = "ace";
        System.out.println("Length of LCS: " + lcs.longestCommonSubsequence(text1, text2));
    }
}