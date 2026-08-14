#include <stdio.h>
int main() {
    int n, i, j, key;
    int count= 0;
    int shifts = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    int marks[n];

    printf("Enter %d student marks:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    printf("\nInsertion Sort Process:\n");

    for(i=1;i<n;i++) {
        for(int j=i;j>0;j--) {
            count++;
            if(marks[j]<marks[j-1]) {
                shifts++;
                int temp=marks[j-1];
                marks[j-1]=marks[j];
                marks[j]=temp;
            }else {
                break;
            }
        }
    }

        printf("After pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", marks[k]);
        }
        printf("\n");
    

    printf("\nFinal sorted marks: ");
    for (i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    printf("\nTotal comparisons: %d", count);
    printf("\nTotal shifts: %d\n", shifts);

    return 0;
}