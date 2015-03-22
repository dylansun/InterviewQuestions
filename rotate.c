#include <stdio.h>
void rotate(int nums[], int n, int k)
{
    k = k % n;
    if(k == 0)
    {
        return ;
    }
    int tmp[k];
    int i=0;
    while(i < k)
    {
        tmp[i]=nums[n-k+i];
        i++;
    }
    for(i=n-k-1; i >= 0; i--)
    {
       nums[i+k] = nums[i];
    }
    for(i=0; i<k;i++)
    {
        nums[i] = tmp[i];
    }
    return ;
}
int main(int argc,char* argv[])
{
    int nums[7] = {1,2,3,4,5,6,7};
    int i =0;
    for(i=0; i< 7; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    rotate(nums, 7, 3);
    for(i=0; i< 7; i++)
    {
        printf("%d ",nums[i]);
    }
    return 0;
}
