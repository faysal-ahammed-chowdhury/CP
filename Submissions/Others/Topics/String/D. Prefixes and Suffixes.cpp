#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(string &pat) {
  int n = pat.size();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; i++) {
    int j = lps[i - 1];
    while (j > 0 and pat[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (pat[i] == pat[j]) j++;
    lps[i] = j;
  }
  return lps;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  auto lps = build_lps(s);
  int n = s.size();
  int j = lps[n - 1];
  vector<int> v;
  while (j > 0) {
    v.push_back(j);
    j = lps[j - 1];
  }
  sort(v.begin(), v.end());

  vector<int> ans(n + 1, 0);
  for (int i = 0; i < n; i++) {
    ans[lps[i]]++;
  }
  for (int i = n - 1; i > 0; i--) {
    ans[lps[i - 1]] += ans[i];
  }
  for (int i = 0; i <= n; i++) {
    ans[i]++;
  }

  cout << v.size() + 1 << '\n';
  for (auto x : v) {
    cout << x << ' ' << ans[x] << '\n';
  }
  cout << n << ' ' << 1 << '\n';

  return 0;
}
