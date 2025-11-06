package Lecture8.Jav;
import java.util.LinkedList;
import java.util.Queue;
public class BFS {
    public static void main(String[] args) {
        // Create a sample graph represented as an adjacency list
        int[][] graph = {
            {1, 2},    
            {0, 3, 4}, 
            {0, 4},    
            {1, 5},    
            {1, 2, 5}, 
            {3, 4}     
        };
        // Perform BFS starting from vertex 0
        bfs(graph, 0);

    }

    // BFS algorithm
    public static void bfs(int[][] graph, int start) {
        boolean[] visited = new boolean[graph.length];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int current = queue.poll();
            System.out.println("Visiting: " + current);

            // Explore neighbors & counting all the values
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.offer(neighbor);
                }
            }
            System.out.println("Number of values explored: " + graph[current].length );
        }
    }
}
