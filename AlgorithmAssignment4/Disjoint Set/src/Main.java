import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {


    int citizens;
    int[] id;
    int[] rank;



    // Creates a graph with V vertices and E edges
    Main(int citizens)
    {

        this.citizens = citizens;
        rank = new int[citizens];
        id = new int[citizens];
        for (int i = 0; i < citizens; i++){

            rank[i] = 1;
            id[i] = i;
        }
    }

    private int root(int i){

        while(id[i]!=i){

            id[i]=id[id[i]];
            i=id[i];
        }
        return i;
    }

    public boolean connected(int i, int j){

        return root(i) == root(j);
    }


    // A utility function to do union of two subsets
    void Union( int x, int y){

        int i = root(x);
        int j = root(y);
        if (i == j) return;
        if (rank[i] > rank[j]) { id[j] = i; rank[i] += rank[j]; }
        else { id[i] = j; rank[j] += rank[i]; }
    }


    public static void main (String[] args)
    {

        int tests = 0;
        int citizens = 0;
        int pairs = 0;



        Scanner sc = new Scanner(System.in);
        tests = sc.nextInt();
        ArrayList<Integer> friends = new ArrayList<>();

        while (tests-- != 0){


            int max = 0;
            citizens = sc.nextInt();
            pairs = sc.nextInt();
            Main graph = new Main(citizens);

            for (int i = 0; i < pairs; i++){

                int first = 0;
                int second = 0;

                first = sc.nextInt();
                second = sc.nextInt();

                //pair.add(new Pair(first, second));
                graph.Union(first - 1,second - 1);
            }



            for (int i = 0; i < citizens;i++){

                if (max < graph.rank[i]) max = graph.rank[i];
            }

            friends.add(max);
        }


        for (int i = 0; i < friends.size(); i++){

            System.out.println(friends.get(i));
        }



    }
}
