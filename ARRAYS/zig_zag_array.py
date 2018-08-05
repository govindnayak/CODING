#Convert an array into Zig-Zag fashion: a < b > c < d >

n = int(input())
a = list(map(int, input().split()))

flag = 0

for i in range(n-1):

	if flag==0:

		if a[i]>a[i+1]:
			temp = a[i]
			a[i] = a[i+1]
			a[i+1] = temp
	else:

		if a[i]<a[i+1]:
			temp = a[i]
			a[i] = a[i+1]
			a[i+1] = temp

	flag = 1-flag

print(a)