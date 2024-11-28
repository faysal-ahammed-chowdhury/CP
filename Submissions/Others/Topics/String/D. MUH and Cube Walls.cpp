#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(vector<int> &pat) {
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

// int kmp(vector<int> &txt, vector<int> &pat) {
//   vector<int> s;
//   for (auto x : pat) {
//     s.push_back(x);
//   }
//   s.push_back(2e9);
//   for (auto x : txt) {
//     s.push_back(x);
//   }
//   vector<int> lps = build_lps(s);
//   int ans = 0;
//   for (auto x : lps) {
//     if (x == pat.size()) ans++;
//   }
//   return ans;
// }

int kmp(vector<int> &txt, vector<int> &pat) {
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

  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }

  if (m == 1) {
    cout << n << '\n';
    return 0;
  }

  vector<int> d1(n - 1), d2(m - 1);
  for (int i = 1; i < n; i++) {
    d1[i - 1] = a[i] - a[i - 1];
  }
  for (int i = 1; i < m; i++) {
    d2[i - 1] = b[i] - b[i - 1];
  }

  // for (auto x : d1) {
  //   cout << x << ' ';
  // }
  // cout << '\n';
  // for (auto x : d2) {
  //   cout << x << ' ';
  // }
  // cout << '\n';

  cout << kmp(d1, d2) << '\n';

  return 0;
}
