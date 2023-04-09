import java.util.*;

public class PowerTransmission {
    static int N, M, B, D;
    static int[] capacities, sources, sinks;
    static int[][] graph, flow;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        capacities = new int[N];
        for (int i = 0; i < N; i++) {
            capacities[i] = sc.nextInt();
        }
        M = sc.nextInt();
        graph = new int[N][N];
        flow = new int[N][N];
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int c = sc.nextInt();
            graph[u][v] = c;
        }
        B = sc.nextInt();
        D = sc.nextInt();
        sources = new int[B];
        sinks = new int[D];
        for (int i = 0; i < B; i++) {
            sources[i] = sc.nextInt() - 1;
        }
        for (int i = 0; i < D; i++) {
            sinks[i] = sc.nextInt() - 1;
        }
        sc.close();
        int maxFlow = getMaxFlow();
        System.out.println(maxFlow);
    }

    static int getMaxFlow() {
        int maxFlow = 0;
        while (true) {
            // find an augmenting path using BFS
            int[] parent = new int[N];
            Arrays.fill(parent, -1);
            Queue<Integer> queue = new LinkedList<>();
            queue.offer(sources[0]); // start from the first source
            while (!queue.isEmpty() && parent[sinks[0]] == -1) {
                int u = queue.poll();
                for (int v = 0; v < N; v++) {
                    if (graph[u][v] - flow[u][v] > 0 && parent[v] == -1) {
                        parent[v] = u;
                        queue.offer(v);
                    }
                }
            }
            if (parent[sinks[0]] == -1) { // no more augmenting paths
                break;
            }
            // find the bottleneck capacity of the augmenting path
            int bottleneck = Integer.MAX_VALUE;
            for (int v = sinks[0]; v != sources[0]; v = parent[v]) {
                int u = parent[v];
                bottleneck = Math.min(bottleneck, graph[u][v] - flow[u][v]);
            }
            // update the flow and residual graph
            for (int v = sinks[0]; v != sources[0]; v = parent[v]) {
                int u = parent[v];
                flow[u][v] += bottleneck;
                flow[v][u] -= bottleneck;
            }
            maxFlow += bottleneck;
        }
        return maxFlow;
    }
}
