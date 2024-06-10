#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  vector<long long> v;
  for (int len = 1; len <= 10; len++) {
    for (int mask = 0; mask < (1 << len); mask++) {
      long long x = 0;
      for (int i = 0; i < len; i++) {
        if (mask & (1 << i)) {
          x = x * 10 + 4;
        }
        else {
          x = x * 10 + 7;
        }
      }
      v.push_back(x);
    }
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) {
    if (v[i] == n) {
      cout << i + 1 << '\n';
      break;
    }
  }

  return 0;
}