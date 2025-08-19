package javasrc;

import java.util.Queue;
import java.util.ArrayDeque;

class NumIsIslands {
    private final int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private char[][] grid;
    private int m, n;

    void dfs(int r, int c) {
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') return;

        grid[r][c] = '0';
        for(int[] dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            dfs(nr, nc);
        }
    }

    void bfs(int r, int c) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{r, c});
        grid[r][c] = '0';

        while(!q.isEmpty()) {
            int[] cord = q.poll();
            for(int[] dir : dirs) {
                int nr = cord[0] + dir[0];
                int nc = cord[1] + dir[1];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] == '0') continue;
                q.offer(new int[]{nr, nc});
                grid[nr][nc] = '0';
            }
        }
    }

    public int numIslands(char[][] grid) {
        this.grid = grid;
        this.m = grid.length; this.n = grid[0].length;

        int count = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == '1') {
                    bfs(r, c);
                    count++;
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        NumIsIslands solution = new NumIsIslands();
        char[][] grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
        };
        System.out.println(solution.numIslands(grid)); // Output: 3
    }
}