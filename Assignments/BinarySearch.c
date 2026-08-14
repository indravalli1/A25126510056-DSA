#include <stdio.h>
int main() {
    int n,s,e,mid,target;
    int count=0;
    int flag=0;
    printf("Enter number of employee IDs: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d employee ID's in ascending order :\n",n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter employee ID to Search: ");
    scanf("%d",&target);

    s=0;
    e=n-1;
    while(s<=e) {
        mid=s+((e-s)/2);
        count++;
        if(arr[mid]==target) {
            flag=1;
            break;
        } else if(target<arr[mid]) {
            e=mid-1;
        }else {
            s=mid+1;
        }
    }
    if(flag) {
        printf("Employeee ID found at position %d\n",mid+1);   
    } else {
        printf("Employee ID not found\n");
    }
    printf("Number of comparisons: %d\n",count);
    return 0;

}