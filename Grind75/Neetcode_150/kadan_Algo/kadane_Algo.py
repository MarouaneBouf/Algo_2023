
class Solution:
    ##Complete this function
    #Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self,arr,N):
        """
        The maximum subarray sum is the maximum of (1) the maximum subarray sum ending at the previous
        position plus the current element, and (2) the current element itself
        
        :param arr: The array of numbers
        :param N: length of the array
        :return: The maximum sum of a subarray.
        """
        max_so_far = -10000000000000000000000000
        max_end = 0
        for i in range(N):
            max_end += arr[i]
            if max_so_far < max_end:
                max_so_far = max_end
            max_end = max(max_end, 0) # If max_end == 0 --> max_end = 0
        return max_so_far
        

#{ 
 # Driver Code Starts
import math

def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            
            print(ob.maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends