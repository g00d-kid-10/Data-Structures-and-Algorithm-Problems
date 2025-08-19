package javasrc;

import javasrc.Interval;
import java.util.Comparator;
import java.util.Arrays;
import java.util.List;

class MeetingRooms {
    public boolean canAttendMeetings(List<Interval> intervals) {
        int n = intervals.size();
        
        boolean ans = true;
        if(n <= 1) return ans;

        intervals.sort(Comparator.comparingInt((Interval interval) -> interval.start));

        for(int i = 1; i < n; i++) {
            Interval curr = intervals.get(i);
            Interval prev = intervals.get(i - 1);
            if(prev.end > curr.start || prev.end > curr.start) {
                ans = false;
                break;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        List<Interval> intervals = Arrays.asList(
            new Interval(0, 30),
            new Interval(31, 54),
            new Interval(60, 80)
        );

        MeetingRooms meetingRooms = new MeetingRooms();
        boolean canAttend = meetingRooms.canAttendMeetings(intervals);
        System.out.println("Can attend all meetings: " + canAttend);
    }
}