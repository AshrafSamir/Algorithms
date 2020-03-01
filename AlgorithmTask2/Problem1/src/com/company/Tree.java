package com.company;
import java.util.LinkedList;
import java.util.Queue;

class Node<T>
{
    public Node(T item)
    {
        data = item;
        left = right = null;
    }
    T data;
    Node left, right;

}

public class Tree {
    Node root;

    String leftDFS(Node n){
        String sum = "";
        if(n == null)return (sum);

        if(n.left!=null){
            sum += "0";
            sum += Integer.toString((Integer) n.left.data);
        }

        sum+=leftDFS(n.left);

        if(n.right!=null){
            sum += "1";
            sum += Integer.toString((Integer) n.right.data);
        }

        sum+=leftDFS(n.right);
        return (sum);
    }

    String rightDFS(Node n){
        String sum="";
        if(n == null)return (sum);

        if(n.right!=null){
            sum += "0";
            sum += Integer.toString((Integer) n.right.data);
        }

        sum+=rightDFS(n.right);

        if(n.left!=null){
            sum += "1";
            sum += Integer.toString((Integer) n.left.data);
        }

        sum+=rightDFS(n.left);
        return (sum);
    }

    boolean myDFS(){
        if((root.right!=null)&&(root.left!=null)){
            if(root.right.data != root.left.data){
                return false;
            }
            else {
                //TODO
               String lst = leftDFS(root.left);
               String rst = rightDFS(root.right);
                System.out.println(lst + " "+ rst);
               if(lst.equals(rst)){
                   return true;
               }
               else return false;

            }
        }
        else if ((root.right==null)&&(root.left==null)){
            return true;
        }
        else {
            return false;
        }

    }
}
