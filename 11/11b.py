GROWTH_FACTOR = 999999

def shortest_path(g1, g2, spaces):
	ans = abs(g2['x'] - g1['x']) + abs(g2['y'] - g1['y']) + (spaces * GROWTH_FACTOR)
	return ans

lines = open("in.txt",'r').read().split('\n')

# Find columns without '#'
columns_without_hashtag = [i for i, col in enumerate(zip(*lines)) if '#' not in col]
rows_without_hashtag = [i for i, row in enumerate(lines) if '#' not in row]

galaxies = {}
ngalaxies = 1

for y, l in enumerate(lines):
	for x, c in enumerate(l):
 		if c == '#':
 			galaxies[ngalaxies] = {'x': x, 'y': y}
 			ngalaxies += 1

sum = 0
for i in range(1, ngalaxies):
    for j in range(i + 1, ngalaxies):
        nxspaces = len([n for n in columns_without_hashtag if (galaxies[i]['x'] < n < galaxies[j]['x'] or galaxies[j]['x'] < n < galaxies[i]['x'])])
        nyspaces = len([n for n in rows_without_hashtag if (galaxies[i]['y'] < n < galaxies[j]['y'] or galaxies[j]['y'] < n < galaxies[i]['y'])])
        sum += shortest_path(galaxies[i], galaxies[j], nxspaces + nyspaces)

print(sum)
