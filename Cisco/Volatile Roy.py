prime = [3, 5, 7, 11, 13, 17]
swaps = ((0, 1), (0, 3), (1, 2), (1, 4), (2, 5), (3, 4), (3, 6), (4, 5), (4, 7), (5, 8), (6, 7), (7, 8))
a = [[1,2,3,4,5,6,7,8,9]]
visited = {(1,2,3,4,5,6,7,8,9):0}

while a:
	s = a.pop(0)

	for i in swaps:
		if s[i[0]] + s[i[1]] in prime:
			s2 = s[:]
			s2[i[0]], s2[i[1]] = s2[i[1]], s2[i[0]]
			if tuple(s2) not in visited:
				visited[tuple(s2)] = visited[tuple(s)] + 1
				a.append(s2)
#print("v -",visited)

for t in range(int(input())):
	_ = input()
	arr = []
	for i in range(3):
	    arr += list(map(int, input().split()))

	if tuple(arr) in visited:
		print(visited[tuple(arr)])
	else:
		print(-1)
