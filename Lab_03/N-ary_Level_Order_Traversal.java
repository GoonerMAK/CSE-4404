package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

public class Main
{
    public static void main(String[] args)
    {

        Node root = newNode(1);
        (root.children).add(newNode(3));
        (root.children).add(newNode(2));
        (root.children).add(newNode(4));
        (root.children.get(0).children).add(newNode(5));
        (root.children.get(0).children).add(newNode(6));
        List<List<Integer> > ans = levelOrder(root);
        printList(ans);
    }




    static class Node {

        public int val;
        public Vector<Node> children;
        public Node(int key)
        {
            val = key;
            children = new Vector<Node>();
        }
    }

    static Node newNode(int key)
    {
        Node temp = new Node(key);
        return temp;
    }



    static List<List<Integer>> levelOrder(Node root)
    {
        List<List<Integer>> res = new ArrayList<>();
        solve(root, 0, res);
        return res;
    }

    public static void solve(Node root, int level, List<List<Integer>> res)
    {
        if(root == null) return;

        // When found a new level, add a new list
        if(level >= res.size())
            res.add(new ArrayList<>());

        // Add node in the list at the related level
        res.get(level).add(root.val);

        // Traverse all the children
        for(Node n : root.children)
            solve(n, level+1, res);
    }


    public static void printList(List<List<Integer> > temp)
    {
        for (List<Integer> it : temp) {
            for (Integer et : it)
                System.out.print(et + " ");
            System.out.println();
        }
    }

}