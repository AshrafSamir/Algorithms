package com.company;

import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner n = new Scanner(System.in);
        int V = n.nextInt();
        Graph graph = new Graph(V+1);
        int src, dest;
        for(int i=0;i<V-1;i++){
            src = n.nextInt();
            dest = n.nextInt();
            graph.addEdge( src,dest);
        }
        ArrayList<Integer> c = new ArrayList<>(/*List.of(5, 6, 3, 4)*/);
        int q = n.nextInt();
        int in = 0;
        for(int i=0;i<q;i++){
            in = n.nextInt();
            c.add(in);
        }

        System.out.println(graph.setEdges(V+1, c));

    }
}
