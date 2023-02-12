package org.example;
import java.util.*;

class Node
{
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
}


class Solution
{
    public List<List<Integer>> levelOrder(Node root)
    {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<Node> q = new LinkedList<>();
        q.offer(root);                       // adding an element

        while (!q.isEmpty())
        {
            int size = q.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++)
            {
                Node node = q.poll();      // returns and removes the front element
                level.add(node.val);       // adding the element to the "level" list

                if (node.children != null)       // checking if the children is null or not
                {
                    for (Node child : node.children)
                    {
                        q.offer(child);     // adding all the children
                    }
                }

            }
            result.add(level);         // adding the level to the list of lists
        }

        return result;
    }


    public static void main(String[] args)         // Driver Method
    {
        Solution s = new Solution();

        Node n1 = new Node(5);
        Node n2 = new Node(6);
        Node n3 = new Node(2);
        Node n4 = new Node(3);
        n4.children = Arrays.asList(n1, n2);
        Node n5 = new Node(4);

        Node root = new Node(1);
        root.children = Arrays.asList(n5, n4, n3);

        List<List<Integer>> result = s.levelOrder(root);

        for (List<Integer> level : result)
        {
            for (int val : level)
            {
                System.out.print(val + " ");
            }
            System.out.println();
        }


    }
}


//    This implementation uses a Queue to store nodes at each level. The nodes are removed from the front of the queue
//    and their values are added to a List called "level". The children of each node are then added to the end of the queue.
//    This continues until the queue is empty, and the result is a list of lists, where each inner list contains
//    the values of nodes at a level.
