package javasrc;

class Interval {
    public int start, end;
    Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public String toString() {
        return "{" + start + ", " + end + "}";
    } 
}