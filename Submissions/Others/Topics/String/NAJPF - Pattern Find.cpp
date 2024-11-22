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

vector<int> kmp(string &txt, string &pat) {
  vector<int> lps = build_lps(pat);
  int n = txt.size(), m = pat.size();
  vector<int> ans;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j > 0 and txt[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (txt[i] == pat[j]) j++;
    if (j == m) {
      ans.push_back(i - j + 1);
      j = lps[j - 1];
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  bool first = true;

  int t; cin >> t;
  while (t--) {
    string txt, pat; cin >> txt >> pat;
    auto ans = kmp(txt, pat);

    if (!first) {
      cout << '\n';
    }
    else first = false;

    if (ans.size() == 0) {
      cout << "Not Found\n";
      continue;
    }

    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << ++x << ' ';
    }
    cout << '\n';
  }

  return 0;
}