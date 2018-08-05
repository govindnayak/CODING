#Sliding Window Maximum (Maximum of all subarrays of size k)
#Use a double ended Queue i.e. Deque to make a "sliding window"
#Favourite!

from collections import deque

def printMax(a, n, k):

	Q = deque()

	for i in range(k):

		while Q and a[i]>=a[Q[-1]]:
			Q.pop()

		Q.append(i)

	for i in range(k, n):

		print(str(a[Q[0]])+" ", end="")

		while Q and Q[0]<=i-k:
			Q.popleft()

		while Q and a[Q[-1]]<=a[i]:
			Q.pop()

		Q.append(i)

	print(str(a[Q[0]]))


if __name__=="__main__":

	n, k = map(int, input().split())
	a = list(map(int, input().split()))

	printMax(a, len(a), k)	


