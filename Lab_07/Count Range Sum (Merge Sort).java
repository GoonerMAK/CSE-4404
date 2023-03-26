import java.util.*;

class Solution
{
    private int lower;
    private int upper;
    private int count = 0;
    private long[] prefixSum;

    public int countRangeSum(int[] nums, int lower, int upper)
    {
        int n = nums.length;
        this.lower = lower;
        this.upper = upper;

        this.prefixSum = new long[n+1];

        for (int i = 0 ; i < n ; i++)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        mergeSort(0, n);

        return count;
    }

    private void mergeSort(int low, int high)
    {
        if (low >= high) return;            // Base case: If the sub-array has only one element, it is already sorted
        int mid = low + (high - low) / 2;


        // Recursively sort the left and right halves of the array
        mergeSort(low, mid);
        mergeSort(mid+1, high);

        int i = mid + 1, j = mid + 1;

        for (int k = low; k <= mid; k++)      // Iterate over the first half of the array
        {
            // Find the first index i such that prefixSum[i] - prefixSum[k] >= lower
            while (i <= high && prefixSum[i] - prefixSum[k] < lower) i++;

            /// Find the first index j such that prefixSum[j] - prefixSum[k] > upper
            while (j <= high && prefixSum[j] - prefixSum[k] <= upper) j++;

            // Add the number of valid sub-arrays that contain the element at index k
            count += j - i;
        }

        merge(low, mid, high);
    }

    private void merge(int low, int mid, int high)
    {
        long[] temp = new long[high - low + 1];    //  temp array to store the merged sub-arrays

        for (int i = low; i <= high; i++)   // copy the elements of the sub-arrays to the temp array
        {
            temp[i - low] = prefixSum[i];
        }

        // merge the two sub-arrays while counting the number of range sums that lie in [lower, upper]
        int i = low, j = mid+1;   // initialize pointers to the start of the two sub-arrays
        int index = low;         // initialize pointer to the start of the merged sub-array

        while (i <= mid && j <= high)      // the merge starts
        {
            if (temp[i - low] < temp[j - low])    // if element in first sub-array is smaller, add to merged array
            {
                prefixSum[index] = temp[i - low];
                index++;
                i++;
            }

            else                        // if element in second sub-array is smaller, add to merged array
            {
                prefixSum[index] = temp[j - low];
                index++;
                j++;
            }
        }

        while (i <= mid)    // add any remaining elements from the first sub-array to the merged array
        {
            prefixSum[index] = temp[i - low];
            index++;
            i++;
        }

    }

    public static void main(String[] args)
    {
        int[] nums = { -2, 5, -1 };
        int lower = -2;
        int upper = 6;

        Solution solution = new Solution();
        int count = solution.countRangeSum(nums, lower, upper);

        System.out.println("The number of sub-arrays with sum in range [" + lower + ", " + upper + "] is " + count);
    }

}


