from collections import defaultdict
from collections import deque
import sys

inps = sys.stdin.read().splitlines()
adj_all = defaultdict(set)
for inp in inps:
    parts = inp.split(" ")
    src = parts[0][:-1]
    dest = parts[1:]
    adj_all[src] = set(dest)


def from_to(src, dest):
    adj_rel = defaultdict(set)
    rev_adj_rel = defaultdict(set)

    # find all reachable nodes from you
    def explore(node):
        for nb in adj_all[node]:
            adj_rel[node].add(nb)
            rev_adj_rel[nb].add(node)
            if nb not in adj_rel.keys():
                explore(nb)

    explore(src)

    node_to_count = defaultdict(int)
    node_to_count[src] = 1
    topo = deque([src])
    while topo:
        node = topo.popleft()
        ways = node_to_count[node]
        for nb in adj_rel[node]:
            node_to_count[nb] += ways
            rev_adj_rel[nb].remove(node)
            if len(rev_adj_rel[nb]) == 0:
                topo.append(nb)

    return node_to_count[dest]


print(from_to("you", "out"))
