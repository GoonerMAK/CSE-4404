import java.util.*;

class TreeNode
{
    int val;
    TreeNode left, right;

    TreeNode(int val) { this.val = val; }

    TreeNode(int val, TreeNode left, TreeNode right)
    {
         this.val = val;
         this.left = left;
         this.right = right;
     }
 }

class Solution
{
    int ans=0;
    public int sumOfLeftLeaves(TreeNode root)
    {
        if (root==null) { return 0; }

        // Checking if the left Node is a leaf node or not
        if (root.left!=null && root.left.left==null && root.left.right==null)
        {
            ans+=root.left.val;    // adding the value if it's leaf node
        }

        // DFS calls
        sumOfLeftLeaves(root.left);
        sumOfLeftLeaves(root.right);

        return ans;
    }

    public static void main(String[] args)
    {
        TreeNode n1 = new TreeNode(2);
        TreeNode n3 = new TreeNode(4);
        TreeNode n4 = new TreeNode(5);
        TreeNode n2 = new TreeNode(3, n3, n4);
        TreeNode root = new TreeNode(1, n1, n2);
        Solution s= new Solution();
        System.out.println(s.sumOfLeftLeaves(root));

    }
}

