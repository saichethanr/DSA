package graphs;

public class AdjacencyMatrixGraph {
    private final int[][] matrix;
    private final int vertices;

    public AdjacencyMatrixGraph(int vertices) {
        this.vertices = vertices;
        matrix = new int[vertices][vertices];
    }

    public void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // remove for directed graph
    }

    public void printGraph() {
        System.out.println("📊 Adjacency Matrix:");
        System.out.print("    ");
        for (int i = 0; i < vertices; i++) {
            System.out.print(i + " ");
        }
        System.out.println("\n   " + "-".repeat(2 * vertices));
        for (int i = 0; i < vertices; i++) {
            System.out.print(i + " | ");
            for (int j = 0; j < vertices; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
