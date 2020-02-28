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
        String st = "",sum = "";
        if(n == null)return (st+sum);

        if(n.left!=null){
            st += "0";
            sum += Integer.toString((Integer) n.left.data);
        }

        leftDFS(n.left);

        if(n.right!=null){
            st += "1";
            sum += Integer.toString((Integer) n.right.data);
        }

        leftDFS(n.right);
        return (st+sum);
    }

    String rightDFS(Node n){
        String st = "", sum="";
        if(n == null)return (st+sum);

        if(n.right!=null){
            st += "0";
            sum += Integer.toString((Integer) n.right.data);
        }

        leftDFS(n.right);

        if(n.left!=null){
            st += "1";
            sum += Integer.toString((Integer) n.left.data);
        }

        leftDFS(n.left);
        return (st+sum);
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
