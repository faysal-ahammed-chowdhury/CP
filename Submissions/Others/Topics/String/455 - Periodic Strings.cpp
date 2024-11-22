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

  int t = 1; cin >> t;
  while (t--) {
    string s; cin >> s;
    auto lps = build_lps(s);
    int n = s.size();
    int len = n - lps[n - 1];
    if (n % len == 0) cout << len;
    else cout << n;
    cout << '\n';
    if (t != 0) cout << "\n";
  }

  return 0;
}
