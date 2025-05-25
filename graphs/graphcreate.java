package graphs;

public class graphcreate {
    public static void main(String[] args){
         int V = 5;

        // Matrix
        AdjacencyMatrixGraph matrixGraph = new AdjacencyMatrixGraph(V);
        matrixGraph.addEdge(0, 1);
        matrixGraph.addEdge(0, 2);
        matrixGraph.addEdge(1, 2);
        matrixGraph.addEdge(1, 3);
        matrixGraph.addEdge(2, 4);
        matrixGraph.addEdge(3, 4);
        matrixGraph.printGraph();


        // Map
        AdjacencyListGraphMap mapGraph = new AdjacencyListGraphMap();
        mapGraph.addEdge(0, 1);
        mapGraph.addEdge(0, 2);
        mapGraph.addEdge(1, 2);
        mapGraph.addEdge(1, 3);
        mapGraph.addEdge(2, 4);
        mapGraph.addEdge(3, 4);
        mapGraph.printGraph();
    }
}
