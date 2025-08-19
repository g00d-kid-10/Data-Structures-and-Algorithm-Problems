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

    public static void main(String[] args) {
        Interval interval = new Interval(1, 5);
        System.out.println(interval); // Output: {1, 5}
    }
}