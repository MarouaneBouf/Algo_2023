#include <stdio.h>
#include <stdlib.h>



void merge(int arr[], int p, int m, int r);
void merge_sort(int arr[], int l, int r);

int main(void)
{
    int arr[] = {1,5,3,9,4,0,6};
    /* This is finding the size of the array. */
    int size = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,size);
    for (int i = 0; i < size; i++)
    {
        fprintf(stdout,"%i ",arr[i]);
    }
    fprintf(stdout,"\n");
     
    return 0;
}


/* This function is merging the two subarrays. */
void merge(int arr[], int p, int m, int r)
{
    int n = m - p + 1;
    int q = r - m;
    
    int L[n];
    int M[q];
    int i = 0, k = 0;

    /* This code is creating a new array L that is the size of the left subarray. */
    for (; i < n; i++)
    {
        L[i] = arr[p+i];
    }
    /* This is creating a new array M that is the size of the right subarray. */
    for (; k < q; k++)
    {
        M[k] = arr[m+k+1];
    }

    int a = 0, b = 0, c = p;

    /* This is comparing the elements of the left and right subarrays and adding the smaller element to
    the array. */
    while(a < i && b < k)
    {
        if (L[a] <= M[b])
        {
            arr[c] = L[a++];
        }
        else
        {
            arr[c] = M[b++];
        }
        c++;
    }

    /* This is adding the remaining elements of the left subarray to the array. */
    while (a < i)
    {
        arr[c++] = L[a++];
    }
    /* This is adding the remaining elements of the right subarray to the array. */
    while (b < k)
    {
        arr[c++] = M[b++];
    }
}

void merge_sort(int arr[], int l, int r)
{
  if (l < r) 
  {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    /* Recursively calling the merge_sort function on the left and right subarrays. */
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}