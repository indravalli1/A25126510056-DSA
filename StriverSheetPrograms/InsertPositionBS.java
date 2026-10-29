//https://leetcode.com/problems/search-insert-position/description/
import java.util.Scanner;
public class InsertPositionBS {
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
        int result=searchInsert(arr,target);
        System.out.println("index:"+result);
    }
    public static int searchInsert(int[] nums, int target) {
        int start = 0;
        int end =nums.length;
        while(start<end) {
            int mid =start+(end-start)/2;
            if (nums[mid]>target) {
                end=mid;
            } else if (nums[mid] <target) {
                start=mid+1;
            } else if (nums[mid]==target) {
                return mid;
            }
        }
        return start;//return end;
    }
}
