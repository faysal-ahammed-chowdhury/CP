#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  string s; cin >> s;
  int freq[26];
  memset(freq, 0, sizeof freq);

  for (auto c : s) {
    freq[c - 'A']++;
  }

  int mn = 1e9;
  for (int i = 0; i < k; i++) {
    mn = min(mn, freq[i]);
  }

  cout << mn * k << '\n';

  return 0;
}