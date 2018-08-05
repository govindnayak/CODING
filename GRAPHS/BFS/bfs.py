class Queue:
	def __init__(self):
		self.items = []
	def enqueue(self,item):
		self.items.insert(0,item)
	def dequeue(self):
		return self.items.pop()
	def isEmpty(self):
		return self.items==[]
	def size(self):
		return len(self.items)

q = Queue()
a = []
n = int(raw_input())
visited = [False]*n

for i in range(0,n):
	columns = raw_input().split()
	a.append(columns)	


def bfs(a,s):
	q.enqueue(s)
	visited[s]=True

	while q.isEmpty()==False:
		v = q.dequeue()
		print v
		for i in range(0,n):
			if int(a[v][i])==1 and visited[i]==False:
				q.enqueue(i)
				visited[i] = True

bfs(a,0)