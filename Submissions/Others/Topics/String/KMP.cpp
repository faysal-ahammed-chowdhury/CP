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

// int kmp(string &txt, string &pat) {
//   string s = pat + '#' + txt;
//   vector<int> lps = build_lps(s);
//   int ans = 0;
//   for (auto x : lps) {
//     if (x == pat.size()) ans++;
//   }
//   return ans;
// }

int kmp(string &txt, string &pat) {
  vector<int> lps = build_lps(pat);
  int n = txt.size(), m = pat.size();
  int ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j > 0 and txt[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (txt[i] == pat[j]) j++;
    if (j == m) {
      ans++;
      j = lps[j - 1];
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string txt, pat; cin >> txt >> pat;
  cout << kmp(txt, pat) << '\n';

  return 0;
}
// https://cses.fi/problemset/task/1753