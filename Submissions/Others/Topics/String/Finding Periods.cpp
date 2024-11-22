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
  
  set<int> ans;
  int j = lps[n - 1];
  while (j > 0) {
    ans.insert(n - j);
    j = lps[j - 1];
  }

  ans.insert(n);

  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}
