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
  int n = s.size();
  auto lps = build_lps(s);

  vector<int> cnt(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cnt[lps[i]]++;
  }
  for (int i = n - 1; i > 0; i--) {
    cnt[lps[i - 1]] += cnt[i];
  }
  for (int i = 0; i <= n; i++) {
    cnt[i]++;
  }

  int j = lps[n - 1];
  while (j > 0) {
    if (cnt[j] >= 3) {
      cout << s.substr(0, j) << '\n';
      return 0;
    }
    j = lps[j - 1];
  }
  cout << "Just a legend\n";

  return 0;
}