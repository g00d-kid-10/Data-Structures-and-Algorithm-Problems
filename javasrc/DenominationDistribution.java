package javasrc;

import java.util.*;

class DenominationDistribution {
    private int n, amount, tolerance;
    private int[] denominations, maxunits;
    private Set<Long> visited = new HashSet<>();

    DenominationDistribution(int n, int amount, int tolerance, int[] denominations, int[] maxunits) {
        this.n = n; this.amount = amount; this.tolerance = tolerance;
        this.denominations = denominations; this.maxunits = maxunits;
    }

    public void distribute(int i, int sum, List<Integer> decidedUnits, Map<Integer, List<Integer>> errorCombinations) {
        int error = sum - amount;
        if(error > tolerance) return;

        long key = (((long) i) << 32) | (sum & 0xffffffffL);
        if (visited.contains(key)) return;

        if(i == n) {
            if (error >= 0 && !errorCombinations.containsKey(error)) {
                errorCombinations.put(error, new ArrayList<>(decidedUnits));
            }
            return;
        }

        for(int unit = maxunits[i]; unit > 0; unit--) {
            decidedUnits.add(unit);
            distribute(i + 1, sum + unit * denominations[i], decidedUnits, errorCombinations);
            decidedUnits.remove(decidedUnits.size() - 1);
        }

        visited.add(key);
    }

    public static void main(String[] args) {
        int amount = 45000;
        int tolerance = 50;
        int[] denominations = new int[]{1000, 500, 300, 200, 100};
        int[] maxunits = new int[denominations.length];
        for(int i = 0; i < denominations.length; i++) maxunits[i] = amount / denominations[i];
        
        List<Integer> decidedUnits = new ArrayList<>();
        Map<Integer, List<Integer>> errorCombinations = new HashMap<>();
        DenominationDistribution obj = new DenominationDistribution(denominations.length, amount, tolerance, denominations, maxunits);
        obj.distribute(0, 0, decidedUnits, errorCombinations);
        System.out.println(errorCombinations);
    }

}