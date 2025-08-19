package javasrc;

import java.util.*;

class WordBreak {
    private String s;
    private int n;
    private HashSet<String> dict;
    private Map<Integer, Boolean> cache;
        
    public boolean dfs(int i) {
        if(i == n) return true;
        if(cache.containsKey(i)) return cache.get(i);

        boolean res = false;
        for(int j = i; j < n; j++) {
            String subStr = s.substring(i, j + 1);
            if(dict.contains(subStr)) {
                res = dfs(j + 1);
                if(res) break;
            }
        }

        cache.put(i, res);
        return res;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        this.s = s;
        this.n = s.length();
        this.dict = new HashSet<>(wordDict);
        this.cache = new HashMap<>();
        return dfs(0);
    }

    public static void main(String[] args) {
        WordBreak wb = new WordBreak();
        List<String> wordDict = Arrays.asList("leet", "code");
        System.out.println(wb.wordBreak("leetcode", wordDict)); // Output: true
    }
}