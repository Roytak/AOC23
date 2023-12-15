
class Box:
	def __init__(self):
		self.lenses = []

	def add(self, name, foc):
		for i, lens in enumerate(self.lenses):
			if lens[0] == name:
				self.lenses[i] = [name, foc]
				return

		self.lenses.append([name, foc])

	def remove(self, name):
		for i, lens in enumerate(self.lenses):
			if lens[0] == name:
				self.lenses.pop(i)
				return

	def get_lenses(self):
		return self.lenses

sequences = open("in.txt", 'r').read().split(',')

boxes = []
for _ in range(256):
	boxes.append(Box())

for seq in sequences:
	x = list(seq)

	tmp = 0
	if '=' in x:
		chars = list(seq.split('=')[0])
		for c in chars:
			tmp += ord(c)
			tmp *= 17
			tmp = tmp % 256

		boxes[tmp].add(seq.split('=')[0], seq.split('=')[1])
	else:
		chars = list(seq.split('-')[0])
		for c in chars:
			tmp += ord(c)
			tmp *= 17
			tmp = tmp % 256
		boxes[tmp].remove(seq.split('-')[0])

sum = 0
for i, box in enumerate(boxes):
	lenses = box.get_lenses()

	for j, lens in enumerate(lenses):
		sum += (i + 1) * (j + 1) * int(lens[1])

print(sum)
