//Code to find maximum sum of subarray
//Brute force and Kadane's algorithm
#include<iostream>
#include<climits>
using namespace std;
//Kadane's Algorithm O(n)
int KadanesAlgo(int arr[10],int n)
{
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<n;i++)
    {
        currSum+=arr[i];
        maxSum=max(maxSum,currSum);
        //here maxsum is updated before if satement because for all negative elements max sum is 
        //negative num with minimum magnitude
        if(currSum<0)
        {
            currSum=0;
        }
    }
    return maxSum;
}
int main()
{
    
    int arr[10]={2,3,-1,-3,2,3,5,-4,1,2};
    int n=10;
    int currSum[n],maxSum=INT_MIN,subSum=0;
    currSum[0]=arr[0];
    maxSum=max(currSum[0],maxSum);
    //This approach gives answer in O(n^2)
    for(int i=1;i<n;i++)
    {
        currSum[i]=currSum[i-1]+arr[i];
        maxSum=max(currSum[i],maxSum);
        for(int j=0;j<i;j++)
        {
            subSum=currSum[i]-currSum[j];
            maxSum=max(maxSum,subSum);
        }
    }
    cout<<maxSum<<endl;
    cout<<KadanesAlgo(arr,n)<<endl;
    return 0;
}