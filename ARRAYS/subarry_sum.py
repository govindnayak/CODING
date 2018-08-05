#Find subarray with given sum - OWN

t = int(input())

while(t):
    t-=1
    n, s = map(int, input().split())

    a = list(map(int, input().split(" ")))

    prev = 0
    sums = 0
    for i in range(0, n):

    	while sums>s and prev<i:	

    		sums-=a[prev]
    		prev+=1

    	if sums==s:
    		print(prev+1, i)
    		break

    	sums+=a[i]
