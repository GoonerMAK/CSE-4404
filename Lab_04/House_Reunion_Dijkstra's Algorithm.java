import java.util.*;

class House
{
    int id;
    List<Edge> edges = new ArrayList<>();

    public House(int id)
    {
        this.id = id;
    }

    public void addEdge(int target, int distance)
    {
        edges.add(new Edge(target, distance));
    }


    public static class Edge
    {
        int target;
        int distance;

        public Edge(int target, int distance)
        {
            this.target = target;
            this.distance = distance;
        }
    }
}



public class Main {
    private static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt(); // number of houses
        int m = scanner.nextInt(); // number of edges

        List<House> houses = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            houses.add(new House(i + 1)); // house IDs start from 1
        }

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();

            houses.get(a - 1).addEdge(b, c); // add edge from house a to house b
            houses.get(b - 1).addEdge(a, c); // add edge from house b to house a
        }

        int[][] distances = new int[n][n]; // distances[i][j] is the distance from house i to house j

        for (int i = 0; i < n; i++)
        {
            Arrays.fill(distances[i], INF);
            distances[i][i] = 0;

            // Create a final copy of i
            final int index = i;

            PriorityQueue<Integer> queue = new PriorityQueue<>(Comparator.comparingInt(a -> distances[index][a]));
            queue.add(i);

            while (!queue.isEmpty()) {
                int curr = queue.poll();

                for (House.Edge edge : houses.get(curr).edges)
                {
                    int next = edge.target - 1;
                    int newDistance = distances[i][curr] + edge.distance;

                    if (newDistance < distances[i][next]) {
                        distances[i][next] = newDistance;
                        queue.add(next);
                    }
                }
            }
        }

        int minSum = INF;
        List<Integer> minHouses = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = 0; j < n; j++) {
                sum += distances[i][j];
            }

            if (sum < minSum) {
                minSum = sum;
                minHouses.clear();
                minHouses.add(i + 1);
            } else if (sum == minSum) {
                minHouses.add(i + 1);
            }
        }

        System.out.print(minHouses.get(0));
        for (int i = 1; i < minHouses.size(); i++) {
            System.out.print(" " + minHouses.get(i));
        }
        System.out.println();
    }
}
