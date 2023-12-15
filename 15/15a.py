
sequences = open("in.txt", 'r').read().split(',')

sum = 0
for seq in sequences:
	x = list(seq)

	tmp = 0
	for c in x:
		if x == '\n':
			continue
		tmp += ord(c)
		tmp *= 17
		tmp = tmp % 256
	sum += tmp

print(sum)
