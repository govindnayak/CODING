from collections import Counter

t = int(input())

while(t):
	t-=1

	m, n = map(int, input().split())
	res = []
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))

	c = Counter(a)

	for i in b:
		if i in a and c[i]!=-1:
			k = c[i]
			while(k):
				res.append(i)
				k-=1
			
			c[i]=-1
 

	for i in sorted(a):
		if c[i]!=-1:
			res.append(i)

	print(" ".join([str(i) for i in res]))
