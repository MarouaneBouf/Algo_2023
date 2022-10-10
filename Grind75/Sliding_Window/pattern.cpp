#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    vector<int> V = {1, 3, 2, 6, -1, 4, 1, 8, 2}; // 9 elements
    int k = 5;

    vector<double> result(V.size() - k + 1);
    int wind_start = 0, wind_end;
    double wind_sum = 0;
    for(wind_end = 0 ; wind_end < V.size() ; wind_end++)
    {
        wind_sum += V[wind_end];
        if(wind_end >= k-1)
        {
            result[wind_start] = wind_sum/k;
            wind_sum = wind_sum - V[wind_start];
            wind_start++;
        }
    }

    auto maxi = max_element(result.begin(), result.end());
    cout << *maxi ;
    cout << "\n";
}