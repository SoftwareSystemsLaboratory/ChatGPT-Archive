#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 1000

int cmpfunc (const void * a, const void * b) {
   return (*(int*)b - *(int*)a);
}

int main() {
    FILE *fp;
    int nums[MAX_NUMS];
    int count = 0;

    // Open the file
    fp = fopen("numbers.txt", "r");

    // Read the numbers from the file
    while (fscanf(fp, "%d", &nums[count]) != EOF) {
        count++;
    }

    // Sort the numbers in descending order
    qsort(nums, count, sizeof(int), cmpfunc);

    // Print the third largest number to the screen
    if (count >= 3) {
        printf("The third largest number is: %d\n", nums[2]);
    } else {
        printf("There are not enough numbers in the file to find the third largest.\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}
