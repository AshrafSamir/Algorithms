package com.company;
import java.util.LinkedList;
import java.util.Queue;

class Node
{
    public Node(int item)
    {
        data = item;
        left = right = null;
    }
    int data;
    Node left, right;

}

public class Tree {
    Node root;

    String leftDFS(Node n){
        String st = "";
        if(n == null)return st;

        if(n.left!=null){
            st += "0";
        }

        leftDFS(n.left);

        if(n.right!=null){
            st += "1";
        }

        leftDFS(n.right);
        return st;
    }
    
    String rightDFS(Node n){
        String st = "";
        if(n == null)return st;

        if(n.right!=null){
            st += "0";
        }

        leftDFS(n.right);

        if(n.left!=null){
            st += "1";
        }

        leftDFS(n.left);
        return st;
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
