package javasrc;

import java.util.*;

class ValidTree {
    private Map<Integer, List<Integer>> adj = new HashMap<>();
    private Set<Integer> visited = new HashSet<>();

    public boolean dfs(int i, int parent) {
        if(visited.contains(i)) return true;

        visited.add(i);
        for(int nei : adj.get(i)) {
            if(nei == parent) continue;
            if(dfs(nei, i)) {
                return true;
            }
        }

        return false;
    }

    public boolean validTree(int n, int[][] edges) {
        if (edges.length > n - 1) {
            return false;
        }


        for(int i = 0; i < n; i++) adj.put(i, new ArrayList<>());
        for(int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        if(dfs(0, -1)) {
            return false;
        }

        return visited.size() == n;
    }

    public static void main(String[] args) {
        ValidTree solution = new ValidTree();
        int[][] edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
        System.out.println(solution.validTree(5, edges)); // Output: true

        int[][] edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
        System.out.println(solution.validTree(5, edges2)); // Output: false
    }
    
}