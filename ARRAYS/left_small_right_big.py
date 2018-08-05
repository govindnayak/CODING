#Beautiful! Get LEFT_MAX and RIGHT_MIN for every elements in the array. If the element lies b/w these 2, return it!

import sys

def findElement(a, n):
	
	left_max = [0]*n
	left_max[0] = -1000000000

	for i in range(1, n):
		left_max[i] = max(left_max[i-1], a[i-1])

	right_min = [0]*n
	right_min[n-1] = 1000000000

	for i in range(n-2, -1, -1):
		right_min[i] = min(a[i+1], right_min[i+1])

	for i in range(1, n-1):

		if left_max[i]<a[i] and right_min[i]>a[i]:
			return i

	return -1

if __name__=="__main__":
	n = int(input())
	a = list(map(int, input().split(", ")))	

	print(findElement(a,n))