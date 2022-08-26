#include <stdio.h>
#include <stdlib.h>

// Function prototype
int binarySearch(int arr[], int low, int high, int x);

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8};
    // Calculate the length of the array
    int size = sizeof(arr)/sizeof(arr[0]);

    int num;
    fprintf(stdout,"Enter a number from the array: ");
    fscanf(stdin,"%i",&num);

    fprintf(stdout,"Number at index : %i\n",binarySearch(arr,0,size,num));

}


int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        // We use this formula instead of (l+h)/2 for the sake of optimization!
        int mid = low + (high - low)/2;
        // Check if the element is in the middle of the array
        if (arr[mid] == x)
        {
            return mid;
        }
        // if this condition is True
        // This means it has to be in the left subarray
        else if (arr[mid] > x)
        {
            return binarySearch(arr, low, mid - 1, x);
        }
        // Otherwise the element has to in the right subarray
        return binarySearch(arr, mid + 1, high, x);
    }
    // Element is not present in the array
    return -1;
}
