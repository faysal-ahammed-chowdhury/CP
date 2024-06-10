#include <bits/stdc++.h>
using namespace std;

int get(char c) {
  return (c - 'a');
}

void solve() {
  int n, k; cin >> n >> k;
  string s, t; cin >> s >> t;

  int have[26], need[26];
  memset(have, 0, sizeof have);
  memset(need, 0, sizeof need);
  for (auto c : s) have[get(c)]++;
  for (auto c : t) need[get(c)]++;

  bool bad = false;
  for (int i = 0; i < 26; i++) {
    if (have[i] < need[i] or (have[i] -= need[i]) % k) {
      bad = true;
    }
    have[i + 1] += have[i];
  }
  cout << (bad ? "No" : "Yes") << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}