package javasrc;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class IntervalQuestions {
    public boolean strictelyOverlapping(int[] firstInterval, int[] secondInterval) {
        return (firstInterval[1] >= secondInterval[0] || firstInterval[1] >= secondInterval[0]);
    }

    public boolean overlapping(int[] firstInterval, int[] secondInterval) {
        return (firstInterval[1] > secondInterval[0] || firstInterval[1] > secondInterval[0]);
    }

    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        int[] prevInterval = intervals[0];
        

        List<int[]> ans = new ArrayList<>();
        for(int i = 1; i < n; i++) {
            if(strictelyOverlapping(prevInterval, intervals[i])) {
                prevInterval = new int[]{
                    Math.min(prevInterval[0], intervals[i][0]),
                    Math.max(prevInterval[1], intervals[i][1]),
                };
                continue;
            }

            ans.add(prevInterval);
            prevInterval = intervals[i];
        }

        ans.add(prevInterval);

        return ans.toArray(new int[ans.size()][]);
    }

    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        int[] prevInterval = intervals[0];

        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(overlapping(prevInterval, intervals[i])) {
                ans++;
                prevInterval = new int[]{
                    Math.max(prevInterval[0], intervals[i][0]),
                    Math.min(prevInterval[1], intervals[i][1]),
                };
                continue;
            }

            prevInterval = intervals[i];
        }
        
        return ans;
    }

    public static void main(String[] args) {
        IntervalQuestions iq = new IntervalQuestions();
        
        // Test strictelyOverlapping
        System.out.println(iq.strictelyOverlapping(new int[]{1, 3}, new int[]{2, 4})); // true
        System.out.println(iq.strictelyOverlapping(new int[]{1, 2}, new int[]{2, 3})); // false
        
        // Test overlapping
        System.out.println(iq.overlapping(new int[]{1, 3}, new int[]{2, 4})); // true
        System.out.println(iq.overlapping(new int[]{1, 2}, new int[]{2, 3})); // false
        
        // Test merge
        int[][] merged = iq.merge(new int[][]{{1, 3}, {2, 4}, {5, 7}});
        for(int[] interval : merged) {
            System.out.println(Arrays.toString(interval));
        }
        
        // Test eraseOverlapIntervals
        System.out.println(iq.eraseOverlapIntervals(new int[][]{{1, 2}, {2, 3}, {3, 4}})); // 0
    }
}