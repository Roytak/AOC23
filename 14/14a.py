
lines = open("in.txt", 'r').read().split('\n')

array = []
for line in lines:
	array.append([*line])

for i, a in enumerate(array):
	if i == 0:
		continue

	for j in range(len(a)):
		if a[j] == 'O':
			for k in reversed(range(0, i)):
				if array[k][j] == '.':
					if k == 0:
						array[k][j] = 'O'
						array[i][j] = '.'
						break
				elif array[k][j] == '#' or array[k][j] == 'O':
					if array[k + 1][j] == '.':
						array[k + 1][j] = 'O'
						array[i][j] = '.'
					break

sum = 0
length = len(array)
for i, a in enumerate(array):
	for j in range(len(a)):
		if array[i][j] == 'O':
			sum += length - i

print(sum)
