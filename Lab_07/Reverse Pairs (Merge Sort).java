import java.util.ArrayList;

class Solution
{
    int merge(int[] nums, int low, int mid, int high)         //  check out the mergeSort() function first
    {
        int count=0;
        int j = mid+1;

        for(int i=low ; i<=mid ; i++)          // iterating first half of the sorted array
        {
            // checking the elements in the sorted second half for the condition nums[i] > (2*nums[j])
            while (j <= high && nums[i] > (2 * (long) nums[j]))
            {
                j++;
            }

            count += j - (mid + 1);     // incrementing the count by the number of pairs found
        }


        /*   Now we have to merge the two sorted halves (storing them into a temporary array)  */

        ArrayList<Integer> temp = new ArrayList<>();
        int left = low, right = mid+1;    // initialize two pointers to point at the start of both halves of the sorted array

        while(left<=mid && right<=high)   // while both halves are not fully iterated
        {
            if(nums[left] <= nums[right])
            {
                temp.add(nums[left]);    // add the left element to the temporary ArrayList
                left++;                 //  move the left pointer to the next element
            }

            else
            {
                temp.add(nums[right]);   // add the right element to the temporary ArrayList
                right++;                //  move the right pointer to the next element
            }
        }


        /*  After one of the halves is fully iterated, adding the remaining elements of the other half to the temporary ArrayList */

        while(left<=mid)        // if there are still some elements left in the left half
        {
            temp.add(nums[left]);
            left++;
        }

        while(right<=high)    // if there are still some elements left in the right half
        {
            temp.add(nums[right]);
            right++;
        }

        for(int i=low ; i<=high ; i++)     // copy the sorted elements from the temporary ArrayList back to the original array
        {
            nums[i] = temp.get(i-low);
        }

        return count;
    }

    int mergeSort(int[] nums, int low, int high)     // sorting da tings
    {
        if(low>=high)  return 0;                    //  base case

        int mid = (low+high)/2;                    //  splitting it into two halves

        int ans = mergeSort(nums, low, mid);     // sorting the left side

        ans += mergeSort(nums,mid+1, high);  // sorting the right side

        ans += merge(nums, low, mid, high);     //  merging the whole array

        return ans;
    }

    public int reversePairs(int[] nums)
    {
        return mergeSort(nums, 0, nums.length-1);
    }


    public static void main(String[] args)
    {
        // create an instance of the Solution class
        Solution sol = new Solution();

        // test input array
        int[] nums = {1,3,2,3,1};

        // call the reversePairs() method to compute the number of reverse pairs
        int numPairs = sol.reversePairs(nums);

        // print the result
        System.out.println("The number of reverse pairs is: " + numPairs);
    }


}
