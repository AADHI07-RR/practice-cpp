import java.util.*;

class Sofa {
    int fsr, fsc, ssr, ssc;
    char dir;
    int moves;

    public Sofa(int fsr, int fsc, int ssr, int ssc, char d, int m) {
        this.fsr = fsr;
        this.fsc = fsc;
        this.ssr = ssr;
        this.ssc = ssc;
        this.dir = d;
        this.moves = m;
    }
}

class Solution {
    private static boolean canAdd(int fsr, int fsc, int ssr, int ssc, char dir, Set<String> vis) {
        String key = fsr + "-" + fsc + "-" + ssr + "-" + ssc + "-" + dir;
        if (vis.contains(key)) return false;
        vis.add(key);
        return true;
    }

    public int minimumMoves(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;

        Queue<Sofa> q = new LinkedList<>();
        Set<String> vis = new HashSet<>();
        vis.add("0-0-0-1-H");
        q.add(new Sofa(0, 0, 0, 1, 'H', 0));

        while (!q.isEmpty()) {
            Sofa s = q.poll();

            if (s.dir == 'H' &&
                s.fsr == r - 1 && s.fsc == c - 2 &&
                s.ssr == r - 1 && s.ssc == c - 1) {
                return s.moves;
            }

            if (s.dir == 'H') {
                // drag right
                if (s.ssc + 1 < c && grid[s.ssr][s.ssc + 1] == 0) {
                    if (canAdd(s.fsr, s.fsc + 1, s.ssr, s.ssc + 1, 'H', vis)) {
                        q.add(new Sofa(s.fsr, s.fsc + 1, s.ssr, s.ssc + 1, 'H', s.moves + 1));
                    }
                }
                // drag bottom
                if (s.fsr + 1 < r && grid[s.fsr + 1][s.fsc] == 0 && grid[s.ssr + 1][s.ssc] == 0) {
                    if (canAdd(s.fsr + 1, s.fsc, s.ssr + 1, s.ssc, 'H', vis)) {
                        q.add(new Sofa(s.fsr + 1, s.fsc, s.ssr + 1, s.ssc, 'H', s.moves + 1));
                    }
                }
                // rotate down (pivot on left cell only)
                if (s.fsr + 1 < r && grid[s.fsr + 1][s.fsc] == 0 && grid[s.fsr + 1][s.fsc + 1] == 0) {
                    if (canAdd(s.fsr, s.fsc, s.fsr + 1, s.fsc, 'V', vis)) {
                        q.add(new Sofa(s.fsr, s.fsc, s.fsr + 1, s.fsc, 'V', s.moves + 1));
                    }
                }
            }

            if (s.dir == 'V') {
                // drag bottom
                if (s.ssr + 1 < r && grid[s.ssr + 1][s.ssc] == 0) {
                    if (canAdd(s.fsr + 1, s.fsc, s.ssr + 1, s.ssc, 'V', vis)) {
                        q.add(new Sofa(s.fsr + 1, s.fsc, s.ssr + 1, s.ssc, 'V', s.moves + 1));
                    }
                }
                // drag right
                if (s.fsc + 1 < c && grid[s.fsr][s.fsc + 1] == 0 && grid[s.ssr][s.ssc + 1] == 0) {
                    if (canAdd(s.fsr, s.fsc + 1, s.ssr, s.ssc + 1, 'V', vis)) {
                        q.add(new Sofa(s.fsr, s.fsc + 1, s.ssr, s.ssc + 1, 'V', s.moves + 1));
                    }
                }
                // rotate right (pivot on top cell only)
                if (s.fsc + 1 < c && grid[s.fsr][s.fsc + 1] == 0 && grid[s.ssr][s.ssc + 1] == 0) {
                    if (canAdd(s.fsr, s.fsc, s.fsr, s.fsc + 1, 'H', vis)) {
                        q.add(new Sofa(s.fsr, s.fsc, s.fsr, s.fsc + 1, 'H', s.moves + 1));
                    }
                }
            }
        }
        return -1;
    }
}