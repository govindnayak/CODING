#Just use Dynamic Programming Bottom-Up approach i.e. LOOPS!

def longest(s, n):

	d = [[False for i in range(n)] for j in range(n)]

	maxlen = 1

	#k=1
	for i in range(n):
		d[i][i] = True
		maxlen = 1

	#k=2
	start = 0
	for i in range(n-1):
		if s[i]==s[i+1]:
			start = i
			d[i][i+1] = True
			maxlen = 2

	#k>=3
	
	for k in range(3, n+1):

		for i in range(0, n-k+1):

			j = i+k-1

			if d[i+1][j-1]==True and s[i]==s[j]:

				d[i][j] = True

				if k>maxlen:
					start = i
					maxlen = k

	print(d)
	print(s[start:start+maxlen])
	print(maxlen)


if __name__=="__main__":

	s = input()

	longest(s, len(s))