#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Explanation: Subarray with maximum sum is [3, 4].

/**
 * We keep a window of size k and keep adding elements to the window. 
 * 
 * If the window size is k, we check if the sum of the window is greater than the maxSum. 
 * 
 * If it is, we update the maxSum. 
 * 
 * We then subtract the first element of the window from the sum and move the window ahead by one
 * element. 
 * 
 * We repeat this process until we reach the end of the array
 */
int main(void)
{
    vector<int> V = {2, 3, 4, 1, 5}; // 9 elements
    int k;
    cout << "Enter K: ";
    cin >> k;
    int wind_end = 0, wind_start = 0;
    int maxSum = 0, sum = 0;

    for(int i = 0; i < V.size(); i++)
    {
        sum += V[i];
        if (i >= k-1)
        {
            maxSum = max(maxSum, sum);
            sum -= V[wind_start++];
        }
    }

    cout << maxSum;
    cout << "\n";
}