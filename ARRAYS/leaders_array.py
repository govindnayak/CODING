import sys

t = int(input())

while(t):
	t-=1

	n = int(input())
	res = []
	a = list(map(int, input().split()))

	m = a[n-1]
	res.append(m)
	for i in range(n-2, -1, -1):

		if a[i]>m:
			m = a[i]
			res.append(m)

	res.sort(reverse=True)
	
	print(' '.join([str(i) for i in res]))



