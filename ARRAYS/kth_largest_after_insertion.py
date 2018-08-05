#Given an input stream of n integers the task is to insert integers to stream and print 
#the kth largest element in the stream at each insertion
#Use HEAP instead of an array window!

import heapq
t = int(input())

while(t):
	t-=1

	k, n = map(int, input().split())
	a = list(map(int, input().split()))

	s = []

	for j in range(k-1):
		print(-1, end=" ")

	for i in range(k):
		heapq.heappush(s, a[i])


	print(s[0], end=" ")

	for i in range(k, n):

		m = s[0]
		if a[i]>m:
			x = heapq.heappop(s)
			heapq.heappush(s, a[i])
			print(s[0], end=" ")
		else:
			print(m, end=" ")

	print("")

