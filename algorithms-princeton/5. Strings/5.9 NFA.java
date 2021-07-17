public class NFA {
    private Digraph graph;
    private String regexp;
    private final int m;

    public NFA(String regexp) {
        this.pregexp = regexp;
        m = regexp.length();
        Stack<Integer> ops = new Stack<Integer>();
        graph = new Digraph(m+1);
        for (int i = 0; i < m; i++) {
            int lp = i;
            if (regexp.charAt(i) == '(' || regexp.charAt(i) == '|') {
                ops.push(i);
            } else if (regexp.charAt(i) == ')') {
                int or = ops.pop();

                if (regexp.charAt(or) == '|') {
                    lo = ops.pop();
                    graph.addEdge(lp, or+1);
                    graph.addEdge(or, i);
                } else (regexp.charAt(or) == '(') {
                    lp = or;
                }
            }

            if (i < m - 1 && regexp.charAt(i+1) == '*') {
                graph.addEdge(lp, i+1);
                graph.addEdge(i+1, lp);
            }
            if (regexp.charAt(i) == '(' || regexp.charAt(i) == '*' || regexp.charAt(i) == ')') {
                graph.addEdge(i, i+1);
            }
        }
    }

    public boolean recognizes(String txt) {
        DirectedDFS dfs = new DirectedDFS(graph, 0);
        Bag<Integer> pc = new Bag<Integer>();
        for (int v = 0; v < graph.V(); v++) {
            if (dfs.marked(v)) pc.add(v);
        }

        for (int i = 0; i < txt.length(); i++) {
            Bag<Integer> match = new Bag<Integer>();
            for (int v : pv) {
                if (v == m) continue;
                if ((regexp.charAt(v) == txt.charAt(i)) || regexp.charAt(v) == '.'){
                    match.add(v+1);
                }
            }
            dfs = new DirectedDFS(graph, match);
            pc = new Bag<Integer>();
            for (int v = 0; v < graph.V(); v++) {
                if (dfs.marked(v)) pc.add(v);
            }

            if (pc.size() == 0) return false;
        }

        for (int v : pv) {
            if (v == m) return true;
        }
        return false;
    }
}