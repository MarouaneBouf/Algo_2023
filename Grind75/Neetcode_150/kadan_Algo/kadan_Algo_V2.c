int maxSubArray(int* nums, int numsSize)
{
    int max_so_far = -10000000000;
    int max_end_here = 0;
    for (int i = 0; i < numsSize; i++)
    {
        max_end_here += nums[i];
        if (max_so_far < max_end_here)
        {
            max_so_far = max_end_here;
        }
        if (max_end_here < 0)
        {
            max_end_here = 0;
        }
    }
    return max_so_far;
}