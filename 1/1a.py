
def parse(line):
    first = [x.isdigit() for x in line].index(True)
    last = len(line) - 1 - [x.isdigit() for x in line[::-1]].index(True)

    dig = int(str(line[first]) + str(line[last]))
    return dig

def main():
    sum = 0
    with open("in.txt") as file:
        for line in file:
            sum += parse(line.rstrip())
    print(sum)

if __name__ == "__main__":
    main()
