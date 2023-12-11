def shortest_path(g1, g2):
	return abs(g2['x'] - g1['x']) + abs(g2['y'] - g1['y'])


lines = open("in.txt",'r').read().split('\n')

space = []

for line in lines:
	if '#' in line:
		space.append(line)
	else:
		space.append(line)
		space.append(line)

# Find columns without '#'
columns_without_hashtag = [i for i, col in enumerate(zip(*space)) if '#' not in col]

moved = 0;
# Duplicate columns without '#'
for col_index in columns_without_hashtag:
    for i in range(len(space)):
        space[i] = space[i][:col_index + moved] + space[i][col_index + moved:]  # Move characters to the right

        # Duplicate the column by moving characters to the right
        if col_index + moved < len(space[i]) - 1:
            space[i] = space[i][:col_index + 1 + moved] + space[i][col_index + moved:]
    moved = moved + 1

galaxies = {}
ngalaxies = 1

for y, l in enumerate(space):
	for x, c in enumerate(l):
		if c == '#':
			galaxies[ngalaxies] = {'x': x, 'y': y}
			ngalaxies += 1

sum = 0
for i in range(1, ngalaxies):
    for j in range(i + 1, ngalaxies):
        sum += shortest_path(galaxies[i], galaxies[j])

print(sum)
