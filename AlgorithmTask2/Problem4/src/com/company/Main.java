package com.company;

import java.util.*;

public class Main {

    public static void main(String[] args) {

        int V = 7;
        Graph graph = new Graph(V);
        graph.addEdge( 1, 2);
        graph.addEdge( 1, 3);
        graph.addEdge( 1, 4);
        graph.addEdge(2, 5);
        graph.addEdge( 2, 6);
        ArrayList<Integer> c = new ArrayList<>(List.of(5, 6, 3, 4));
        System.out.println(graph.setEdges(6,7, c));

    }
}
