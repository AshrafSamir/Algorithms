package com.company;

import java.util.*;

public class Graph {
    int V;
    LinkedList<Integer> adjListArray[];


    Graph(int V)
    {
        this.V = V;

        adjListArray = new LinkedList[V];

        for(int i = 0; i < V ; i++){
            adjListArray[i] = new LinkedList<>();
        }
    }
     void addEdge( int src, int dest)
    {
        adjListArray[src].add(dest);

       adjListArray[dest].add(src);
    }

    int setEdges(int n, ArrayList<Integer> clubs)
    {

        int SalahC = 1;
        Vector<Boolean> visited = new Vector<Boolean>(n);

        for (int i = 0; i < n; i++) {
            visited.addElement(false);
        }


        Vector<Integer> distance = new Vector<Integer>(n);

        for (int i = 0; i < n; i++) {
            distance.addElement(0);
        }


        Queue<Integer> Q = new LinkedList<>();
        distance.setElementAt(0, SalahC);

        Q.add(SalahC);
        visited.setElementAt(true, SalahC);
        while (!Q.isEmpty())
        {
            int x = Q.peek();
            Q.poll();

            for (int i=0; i<adjListArray[x].size(); i++)
            {
                if (visited.elementAt(adjListArray[x].get(i)))
                    continue;


                distance.setElementAt(distance.get(x) + 1,adjListArray[x].get(i));
                Q.add(adjListArray[x].get(i));
                visited.setElementAt(true,adjListArray[x].get(i));
            }
        }

        int min = 9999999;
        int ind = 0;
        for(int i=0; i<distance.size();i++){
            if((distance.get(i)<min)&&(distance.get(i)!=0)&&(clubs.contains(i))){
                min = distance.get(i);
                ind = i;
            }
        }

        return ind;
    }






}
