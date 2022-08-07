/*
Time Complexity :
The time complexity of the linear search is O(n) because each element in an array is compared only once.

Pseudo Code : 
for(start to end of array)
{
    if (current_element equals to 5)  
    {
        print (current_index);
    }
}
*/

#include <stdio.h>

int main(void){
	int N,M;
	int res = -2;
    scanf("%d %d", &N,&M);
	int arr[N];
	for (int i = 0 ; i < N ; i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i] == M)
		{
			res = i;
		}
	}
	printf("%d",res+1);
	return 0;
}
