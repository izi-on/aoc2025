#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

long ipow(long base, long exp) {
  long result = 1;
  while (exp) {
    if (exp & 1) {
      result *= base;
    }
    base *= base;
    exp >>= 1;
  }
  return result;
}

int get_dig_count(long i) {
  if (i == 0) {
    return 1;
  }
  int count = 0;
  while (i) {
    count += 1;
    i /= 10;
  }
  return count;
}

void build_set(set<long> &digs) {
  for (long i = 1; i < 999999; i++) {
    long dig_count = get_dig_count(i);
    long cur = i * ipow(10, dig_count) + i;
    while (get_dig_count(cur) <= 11) {
      digs.insert(cur);
      cur = cur * ipow(10, dig_count) + i;
    }
  }
}

int bisect(const vector<long> &sv, long num) {
  int l = 0;
  int r = sv.size() - 1;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (num <= sv[mid]) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}

void build_pref_sum(const vector<long> &sv, vector<long> &ps) {
  ps[0] = 0;
  for (int i = 0; i < sv.size(); i++) {
    ps[i + 1] = ps[i] + sv[i];
  }
}

int main() {
  string input;
  set<long> digs;
  build_set(digs);
  vector<long> sv(digs.begin(), digs.end());
  sort(sv.begin(), sv.end());
  vector<long> ps(sv.size() + 1);
  build_pref_sum(sv, ps);
  long ans = 0;
  while (getline(cin, input, ',')) {
    long lower = stol(input.substr(0, input.find('-')));
    long upper = stol(input.substr(input.find('-') + 1));
    int li = bisect(sv, lower); // points to first equal to bigger than lower
    if (li == -1) {
      continue;
    }
    int ri = bisect(sv, upper + 1l); // points to first bigger than ri
    if (ri == -1) {
      ri = sv.size(); // upper bigger than everything
    }
    ans += ps[ri] - ps[li];
  }
  cout << ans;
  return 0;
}
