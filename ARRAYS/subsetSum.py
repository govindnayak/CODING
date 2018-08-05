a = list(map(int, input().split()))
s = int(input())
def subset(a,n,s):
	if s==0:
		return 1
	if n==0 and s!=0:
		return 0


	if a[n-1]>s:
		return subset(a,n-1,s)
	

	return (subset(a,n-1,s) + subset(a,n-1,s-a[n-1]))


print(subset(a,len(a),s))
