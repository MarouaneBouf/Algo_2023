#include <stdio.h>
#include <stdlib.h>




int binary_search(int arr[], int low, int high, int num);

int main(void)
{
    int arr[] = {1,2,3,4,5,6};
  // Calculate the length of the array!
    int size = sizeof(arr) / sizeof(arr[0]);
    fprintf(stdout,"%i\n",binary_search(arr, 0, size, 6));
}


int binary_search(int arr[], int low, int high, int num)
{
    int mid;
  
    // while size of the array is not 0
    while(low != high)
    {
      // Calculate the updated value of mid!
        mid = low + (high - low)/2;
      
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] > num)
        {
            high = mid - 1;
        }
        else if (arr[mid] < num)
        {
            low = mid + 1;
        }
    }
    return -1;
}
