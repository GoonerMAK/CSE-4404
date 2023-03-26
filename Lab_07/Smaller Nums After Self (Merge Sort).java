import java.util.*;

class Solution {
    private class Array_Value_With_Original_Index
    {
        int val;
        int originalIndex;

        public Array_Value_With_Original_Index(int val, int originalIndex)
        {
            this.val = val;
            this.originalIndex = originalIndex;
        }
    }

    public List<Integer> countSmaller(int[] nums)
    {
        if (nums == null || nums.length == 0)       // check if input is valid or not
            return new LinkedList<Integer>();

        int n = nums.length;
        int[] result = new int[n];

        // new array of Array_Value_With_Original_Index objects
        Array_Value_With_Original_Index[] newNums = new Array_Value_With_Original_Index[n];

        for (int i = 0 ; i<n ; i++)         // storing each element of the input array along with its original index
        {
            newNums[i] = new Array_Value_With_Original_Index(nums[i], i);
        }

        mergeSortAndCount(newNums, 0, n - 1, result);     // merge and count the numbers

        List<Integer> resultList = new LinkedList<Integer>();

        for (int i : result)
        {
            resultList.add(i);
        }

        return resultList;
    }

    private void mergeSortAndCount(Array_Value_With_Original_Index[] nums, int start, int end, int[] result)
    {
        if (start >= end) return;   // Base case: If the sub-array has only one element, it is already sorted

        int mid = (start + end) / 2;
        mergeSortAndCount(nums, start, mid, result);            //  Left sub-array
        mergeSortAndCount(nums, mid + 1, end, result);    //   Right sub-array

        // initialize two pointers to point at the start of both halves of the sorted array
        int leftPos = start;
        int rightPos = mid + 1;

        //  to store the merged sub-arrays
        LinkedList<Array_Value_With_Original_Index> merged = new LinkedList<Array_Value_With_Original_Index>();

        int count = 0;  // number of Elements Right Array Less Than Left Array

        while (leftPos < mid + 1 && rightPos <= end)   // while both halves are not fully iterated
        {
            if (nums[leftPos].val > nums[rightPos].val)    // if the Element Right Array Less Than Left Array (main problem)
            {
                count++;                          // increment the count of smaller elements in the right sub-array

                merged.add(nums[rightPos]);     // add the element in the right sub-array to the merged list
                rightPos++;
            }

            else if(nums[leftPos].val <= nums[rightPos].val)
            {
                // update the count of smaller elements for the current element in the left sub-array
                result[nums[leftPos].originalIndex] += count;

                merged.add(nums[leftPos]);
                leftPos++;
            }
        }

        /*  After one of the halves is fully iterated, adding the remaining elements of the other half to the merged ArrayList  */

        while (leftPos < mid + 1)   // if there are still some elements left in the left half
        {
            // update the count of smaller elements for the current element in the left sub-array
            result[nums[leftPos].originalIndex] += count;

            merged.add(nums[leftPos]);
            leftPos++;
        }

        while (rightPos <= end)     // if there are still some elements left in the right half
        {
            merged.add(nums[rightPos]);
            rightPos++;
        }

        // Copy the merged list back to the original array
        int pos = start;

        for (Array_Value_With_Original_Index m : merged)
        {
            nums[pos] = m;
            pos++;
        }
    }


    public static void main(String[] args)
    {
        int[] nums = { -1 , 1};

        Solution s = new Solution();

        List<Integer> counts = s.countSmaller(nums);

        System.out.println("Input array: " + Arrays.toString(nums));
        System.out.println("Counts of smaller elements on the left:");
        System.out.println(counts);
    }
}
