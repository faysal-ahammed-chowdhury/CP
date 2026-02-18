#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  sort(t.begin(), t.end());
  s = '.' + s, t = '.' + t;

  int freq[26];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= m; i++) {
    freq[t[i] - 'a']++;
  }

  for (int i = 1; i <= n; i++) {
    freq[s[i] - 'a']--;
    if (freq[s[i] - 'a'] < 0) {
      cout << "Impossible\n";
      return;
    }
  }

  vector<pair<int, int>> v;
  char mx = s[1];
  int last = 1;
  for (int i = 2; i <= n; i++) {
    if (s[i] > mx) {
      mx = s[i];
      v.push_back({last, i - 1});
      last = i;
    }
  }
  v.push_back({last, n});

  string ans = "";
  for (auto [l, r] : v) {
    for (char c = 'a'; c < s[l]; c++) {
      while (freq[c - 'a'] > 0) {
        freq[c - 'a']--;
        ans += c;
      }
    }
    for (int j = l; j <= r; j++) {
      ans += s[j];
    }
    // cout << l << ' ' << r << '\n';
  }

  for (char c = 'a'; c <= 'z'; c++) {
    while (freq[c - 'a'] > 0) {
      freq[c - 'a']--;
      ans += c;
    }
    assert(freq[c - 'a'] == 0);
  }

  assert(ans.size() == m);

  cout << ans << '\n';
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