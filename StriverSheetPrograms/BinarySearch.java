//https://leetcode.com/problems/binary-search/description/
import java.util.Scanner;
public class BinarySearch {
    public static void main (String [] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter array size:");
        int size=in.nextInt();
        int [] arr=new int[size];
        System.out.println("Enter Array Elements:");
        for(int i=0;i<size;i++) {
            arr[i]=in.nextInt();
        }
        System.out.println("Enter target:");
        int target=in.nextInt();
        int result=search(arr,target);
        System.out.println("index:"+result);
    }
    public static int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length-1;
        boolean assand = nums[start] <= nums[end];
        while (start <= end) {
            int mid = start+(end - start)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (assand) {
                if (target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > nums[mid]) {
                    end = mid-1;
                } else {
                        start = mid+1;
                    return target; 
                }
            }
        }
        return -1;
    }
}
