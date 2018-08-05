#Given an array of strings, find the longest common PREFIX among them!

def longest(a, b):

	m = len(a)
	n = len(b)
	i = 0
	j = 0
	res = ""
	while i<m and j<n:
		if a[i]==b[j]:
			res+=a[i]
		i+=1
		j+=1

	return res

if __name__=="__main__":

	n = int(input())

	s = list(map(str, input().split()))

	prefix = s[0]

	for i in range(1, n):

		prefix = longest(prefix, s[i])

	print(prefix)

