def tapping(a, n):

	left = [0]*n
	right = [0]*n

	sums = 0

	left[0] = a[0]
	for i in range(1, n):
		left[i] = max(left[i-1], a[i])


	right[n-1] = a[n-1]
	for i in range(n-2, -1, -1):
		right[i] = max(right[i+1], a[i])


	for i in range(n):
		sums+=min(left[i], right[i]) - a[i]

	return sums


if __name__=="__main__":

	a = list(map(int, input().split()))
	print(tapping(a, len(a)))