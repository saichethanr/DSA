package graphs;

import java.util.*;

public class AdjacencyListGraphMap {
    private final Map<Integer, List<Integer>> adjMap;

    public AdjacencyListGraphMap() {
        adjMap = new HashMap<>();
    }

    public void addEdge(int u, int v) {
        adjMap.putIfAbsent(u, new ArrayList<>());
        adjMap.putIfAbsent(v, new ArrayList<>());
        adjMap.get(u).add(v);
        adjMap.get(v).add(u); // remove for directed graph
    }

    public void printGraph() {
        System.out.println("📘 Adjacency List (using Map):");
        for (int node : adjMap.keySet()) {
            System.out.print(node + " ➝ ");
            for (int neighbor : adjMap.get(node)) {
                System.out.print(neighbor + " → ");
            }
            System.out.println("null");
        }
    }
}

