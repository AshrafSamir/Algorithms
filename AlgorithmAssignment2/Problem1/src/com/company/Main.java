package com.company;

public class Main {

    public static void main(String[] args) {

        Tree t = new Tree();
        t.root = new Node<>(1);
        t.root.right = new Node<>(2);
        t.root.left = new Node<>(2);
        t.root.right.right = new Node<>(3);
        t.root.right.left = new Node<>(4);
        t.root.left.right = new Node<>(4);
        t.root.left.left = new Node<>(3);
        t.root.right.right.left = new Node<>(3);
        t.root.left.left.right = new Node<>(3);

        System.out.println(t.myDFS());
    }
}
