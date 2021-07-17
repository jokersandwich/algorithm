public class KruskalMST {
    private double weight;
    private Queue<Edge> mst = new Queue<Edge>();

    public KruskalMST(EdgeWeightedGraph G) {
        Edge[] edges = new Edge[G.E()];
        int t = 0;
        for (Edge e: G.edges()) {
            edges[t++] = e;
        }
        Arrays.sort(edges);

        UF uf = new UF(G.V());
        for (int i = 0; i < G.E() && mst.size() < G.V() - 1; i++) {
            Edge e = edges[i];
            int v = e.either();
            int w = e.other(v);

            if (uf.find(v) != uf.find(w)) {
                uf.union(v, w);
                mst.enqueue(e);
                weight += e.weight();
            }
        }
    }

    public Iterable<Edge> edges() {
        return mst;
    }

    public double weight() {
        return weight;
    }
}