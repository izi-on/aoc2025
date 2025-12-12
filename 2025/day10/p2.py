import sys
from pprint import pprint

inpl = sys.stdin.read().splitlines()

for l in inpl:
    parts = l.split(" ")
    joltage_req_raw = parts[-1]
    configs_raw = parts[1:-1]

    joltages = [int(x) for x in joltage_req_raw[1:-1].split(",")]
    configs = [
        [int(x) for x in config_raw[1:-1].split(",")] for config_raw in configs_raw
    ]

    n = len(joltages)
    m = len(configs) + 1  # one for the target joltage
    matrix = [[0 for _ in range(m)] for _ in range(n)]

    # upper bounds on the coefficients
    upper_bounds = [float("inf")] * len(configs)
    for i in range(len(configs)):
        for j in configs[i]:
            upper_bounds[i] = min(upper_bounds[i], joltages[j])

    # add the config columns + joltage column
    for j in range(m - 1):
        for i in configs[j]:
            matrix[i][j] = 1
    for i in range(n):
        matrix[i][-1] = joltages[i]

    # reduced row echelon form with partial pivoting
    pivots = []
    pivot_col = 0
    for i in range(n):
        # get max for the column (ensure current is not 0)
        cols = list(zip(*matrix))
        m_idx = cols[pivot_col][i:].index(max(cols[pivot_col][i:])) + i
        matrix[m_idx], matrix[i] = matrix[i], matrix[m_idx]
        while pivot_col < m - 1 and matrix[i][pivot_col] == 0:
            pivot_col += 1
            cols = list(zip(*matrix))
            m_idx = cols[pivot_col][i:].index(max(cols[pivot_col][i:])) + i
            matrix[m_idx], matrix[i] = matrix[i], matrix[m_idx]
        if pivot_col == m - 1:
            print("exiting loop")
            break
        pivots.append(pivot_col)
        for k in range(0, n):
            if i == k:
                continue
            if matrix[k][pivot_col] == 1:  # needs to be eliminated
                for j in range(pivot_col, m):
                    matrix[k][j] -= matrix[i][j]

    # brute force a solution
    def brute_force()

    pprint(matrix)
