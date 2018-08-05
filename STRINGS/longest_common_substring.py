import sys

def longest_substring(s1, s2):
	n1 = len(s1)
	n2 = len(s2)
	ind = 0
	dp = [[0 for i in range(n2+1)] for j in range(n1+1)]

	result = 0
	for i in range(n1+1):
		for j in range(n2+1):

			if i==0 or j==0:
				dp[i][j]=0

			elif s1[i-1]==s2[j-1]:		# and dp[i-1][j-1] < (j-i) with j=i+1 for non_overlapping
				dp[i][j] = dp[i-1][j-1] + 1 
				
				if(dp[i][j]>result):

					result = dp[i][j]
					ind = max(ind, i)
			
			else:
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) # (0) if you want continuous common substring

	return s1[ind-result:ind]


s1 = "GeeksforGeeks"
s2 = "Geeks"

print(longest_substring(s1, s2))
