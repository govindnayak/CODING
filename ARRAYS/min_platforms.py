import sys

n = int(input())

arr = list(map(int, input().split()))
dep = list(map(int, input().split()))

arr.sort()
dep.sort()

i = 0
j = 0
count = 1
max_count = 0

while(i<n and j<n):

	if arr[i]<dep[j]:
		i+=1
		count+=1

		max_count = max(max_count, count)

	else:

		j+=1
		count-=1

print(max_count)






