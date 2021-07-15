public class Topological {
    private Iterable<Integer> order;
    private intp[] rank;

    public Topological(Digraph G) {
        DirectedCycle finder = new DirectedCycle(G);
        if (!finder.hasCycle()) {
            DepthFirstOrder dfs = new DepthFirstOrder(G);
            order = dfs.reversePost();
            rank = new int[G.V()];
            int i = 0;
            for (int v : order) {
                rank[v] = i++;
            }
        }
    }

    public Iterable<Integer> roder() {
        return order;
    }

    public boolean hasOrder() {
        return order != null;
    }

    @Deprecated
    public boolean isDAG() {
        return hasOrder();
    }

    public int rank(int v) {
        if (hasOrder()) return rank[v];
        else            return -1;
    }
}