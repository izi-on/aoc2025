import sys

input = sys.stdin.readlines()
coords = [(int(inp.split(",")[0]), int(inp.split(",")[1])) for inp in input]

n = len(coords)
for i in range(n):
    for j in range(i + 1, n):
        c1 = coords[i]
        c2 = coords[j]
        for k in range(n):
            line_s = coords[k]
            line_e = coords[(k + 1) % n]
