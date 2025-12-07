from collections import defaultdict
import sys

matrix = sys.stdin.read().splitlines()
trails = set()

start = matrix[0].find("S")
trails.add(start)
map_t_to_beams = defaultdict(int)
map_t_to_beams[start] += 1
end = len(matrix)
cur_row = 1
while cur_row != end:
    m = len(matrix[cur_row])
    splitters = set([i for i in range(m) if matrix[cur_row][i] == "^"])
    for split in splitters:
        if split not in trails:
            continue
        trails.remove(split)
        from_above_beams = map_t_to_beams[split]
        del map_t_to_beams[split]
        for delta in [-1, 1]:
            pos = split + delta
            if pos in splitters:
                continue
            trails.add(pos)
            map_t_to_beams[pos] += from_above_beams
    cur_row += 1

print(sum(map_t_to_beams.values()))
