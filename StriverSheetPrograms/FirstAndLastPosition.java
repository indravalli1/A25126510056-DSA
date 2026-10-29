import java.util.Scanner;
public class FirstAndLastPosition {
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
        int[] result=searchRange(arr,target);
        System.out.println("First index: " + result[0]);
        System.out.println("Last index: " + result[1]);
    }
    public static int[] searchRange(int[] nums, int target) {
        int[] ans = {-1, -1};
                ans[0] = binarysearch(nums, target, true);
                if (ans[0] != -1) {
                    ans[1] = binarysearch(nums, target, false);

                }
                return ans;
                //  return binarysearch(nums,target);
            }
            public static int binarysearch(int[] nums, int target,boolean findstartindex) {
                int ans = -1;
                int start = 0;
                int end = nums.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                ans = mid;
                if (findstartindex) {
                    end = mid-1;
                }else {
                    start = mid + 1;
                }
            }
        }
        return ans;
    }
}
