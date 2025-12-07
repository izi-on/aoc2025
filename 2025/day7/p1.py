import sys

matrix = sys.stdin.read().splitlines()
trails = set()

start = matrix[0].find("S")
trails.add(start)
end = len(matrix)
cur_row = 1
count = 0
while cur_row != end:
    m = len(matrix[cur_row])
    splitters = set([i for i in range(m) if matrix[cur_row][i] == "^"])
    for split in splitters:
        if split not in trails:
            continue
        trails.remove(split)
        count += 1
        for delta in [-1, 1]:
            pos = split + delta
            if pos in splitters:
                continue
            trails.add(pos)
    cur_row += 1

print(count)
