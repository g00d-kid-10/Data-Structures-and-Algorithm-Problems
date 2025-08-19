package javasrc;

class ReverseBits {
    public int reverseBits(int n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            ans = ans << 1;
            int bit = (n & 1);
            ans = ans | bit;
            n = n >> 1;
        }

        return ans;
    }

    public static void main(String[] args) {
        ReverseBits rb = new ReverseBits();
        int n = 43261596; // Example input
        int reversed = rb.reverseBits(n);
        System.out.println("Reversed bits: " + reversed); // Output should be 964176192
    }
}