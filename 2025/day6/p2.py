import sys
from functools import reduce


def bin_op(op):
    if op == "*":
        return lambda acc, x: acc * x
    else:
        return lambda acc, x: acc + x


matrix = sys.stdin.read().splitlines()
max_len = max(len(row) for row in matrix)
matrix = [row.ljust(max_len) for row in matrix]
mcols = list(zip(*matrix))
n, m = len(mcols[0]), len(mcols)
col_splits = (
    [-1] + [j for j in range(m) if all([elem == " " for elem in mcols[j]])] + [m]
)
ops_matrices = [
    [row[col_splits[i - 1] + 1 : col_splits[i]] for row in matrix]
    for i in range(1, len(col_splits))
]
ans = 0
for ops_matrix in ops_matrices:
    cols = list(zip(*ops_matrix[:-1][:]))
    op = "+" if any([elem == "+" for elem in ops_matrix[-1]]) else "*"
    s_nums = [[c for c in col if c != " "] for col in cols]
    nums = [int("".join(col)) for col in s_nums]
    ans += reduce(bin_op(op), nums, 0 if op == "+" else 1)
print(ans)
