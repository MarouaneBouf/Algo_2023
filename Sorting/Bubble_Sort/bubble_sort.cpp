#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main(void)
{
    vector<int> V = {8,5,1,4,3,2};
    int swap = 1;
    int temp;
    while (swap != 0)
    {
        swap = 0;
        for(int i = 0; i < V.size();i++)
        {
            if(V[i] > V[i+1])
            {
                temp = V[i];
                V[i] = V[i+1];
                V[i+1] = temp;
                swap++;
            }
        }
    }
    for(int i:V)
    {
        cout << i << " ";
    }
    cout << "\n";
}