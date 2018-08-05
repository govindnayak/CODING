n = int(raw_input())

a = []
visited = [False]*n

def dfs(i):
	print (i)
	visited[i] = True

	for j in range(0,n):
		if visited[j]==False and int(a[i][j])==0:
			dfs(j)
	

for i in range(0,n):
	columns = raw_input().split()
	a.append(columns)	

dfs(0)