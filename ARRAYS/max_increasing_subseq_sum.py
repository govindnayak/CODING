#Maximum sum of an increasing subsequence!

def max_size(a): 

    n = len(a)
    sums = []

    for i in range(n):
        sums.append(a[i])

    for i in range(n):
        for j in range(i):

            if a[i]>a[j] and sums[i]<sums[j]+a[i]:
                sums[i]=sums[j]+a[i]

    return max(sums)

if __name__=="__main__":

    a = list(map(int, input().split()))

    print(max_size(a))

# For non-adjecent elements - max sum

# int maxSubsetSum(vector<int> arr) {    
#     dp[0]=max(0,arr[0]);
#     if(arr.size()==1)
#         return dp[0];
#     for(int i=1;i<arr.size();i++)
#     {
#         dp[i]=max(dp[i-2],max(dp[i-1],dp[i-2]+arr[i]));
#     }
#     int n=arr.size();
#     return max(dp[n-1],dp[n-2]);
# }