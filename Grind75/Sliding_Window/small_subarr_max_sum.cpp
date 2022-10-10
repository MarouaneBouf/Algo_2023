// Smallest subarray with greatest sum!
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"


int main(void)
{
    vector<int> V = {3, 4, 1, 1, 6};
    int S = 7;

    int wind_start = 0, wind_end = 0, sum = 0;
    int res = 10909090;
    vector<int> result;
    while(wind_end <= V.size())
    {
        if(sum >= S)
        {
            res = min(res,wind_end - wind_start);
            sum -= V[wind_start++];
        }
        else
        {
            sum += V[wind_end++];
        }
    }
    cout << res << endl;

}