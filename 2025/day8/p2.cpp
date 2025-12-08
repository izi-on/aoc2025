#include <algorithm>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
using namespace std;

int CONNECT_COUNT = 1000;

int find(vector<int> &p, int i) {
  if (i != p[i])
    p[i] = find(p, p[i]);
  return p[i];
}

void _union(vector<int> &p, vector<int> &r, int a, int b) {
  int pa = find(p, a);
  int pb = find(p, b);
  if (pa == pb)
    return;
  if (r[pa] > r[pb]) {
    p[pb] = pa;
    r[pa] += r[pb];
  } else {
    p[pa] = pb;
    r[pb] += r[pa];
  }
}

int main() {
  string input;
  vector<tuple<int, int, int>> nodes;
  vector<tuple<long, int, int>> heap;

  while (getline(cin, input, '\n')) {
    istringstream stream(input);
    vector<int> coords;
    string num;
    while (getline(stream, num, ',')) {
      coords.push_back(stoi(num));
    }
    for (int i = 0; i < nodes.size(); i++) {
      auto node = nodes[i];
      long long dx = (long long)get<0>(node) - coords[0];
      long long dy = (long long)get<1>(node) - coords[1];
      long long dz = (long long)get<2>(node) - coords[2];
      long long dist = dx * dx + dy * dy + dz * dz;
      heap.push_back({-dist, i, (int)nodes.size()});
      push_heap(heap.begin(), heap.end());
    }
    nodes.push_back({coords[0], coords[1], coords[2]});
  }

  vector<int> p(nodes.size());
  generate(p.begin(), p.end(), [n = 0]() mutable { return n++; });
  vector<int> r(nodes.size(), 1);

  long ans = 0;
  int idx = 0;
  while (!heap.empty()) {
    pop_heap(heap.begin(), heap.end());
    auto candidate = heap.back();
    heap.pop_back();
    _union(p, r, get<1>(candidate), get<2>(candidate));
    ans = static_cast<long>(get<0>(nodes[get<1>(candidate)])) *
          static_cast<long>(get<0>(nodes[get<2>(candidate)]));
    if (r[find(p, get<1>(candidate))] == nodes.size()) {
      break;
    }
  }

  cout << ans;
  return 0;
}
