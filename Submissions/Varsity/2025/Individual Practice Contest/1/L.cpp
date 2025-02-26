#include <bits/stdc++.h>
using namespace std;

const int N = 205;
string s;
int n, x;
int dp[N];

int f(int n) {
  if (n <= 0) return 0;

  int &ans = dp[n];
  if (ans != -1) return ans;

  set<int> mex;
  for (int i = 1; i <= n; i++) {
    int l = max(0, i - 3), r = max(0, n - i - 2);
    int x = f(l) ^ f(r);
    mex.insert(x);
  }
  ans = 0;
  while (true) {
    if (mex.find(ans) != mex.end()) ans++;
    else break;
  }
  return ans;
}

int cs;
void solve() {
  cout << "Case " << ++cs << ": ";
  cin >> s;
  n = s.size();
  s = '#' + s;

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (i - 1 >= 1 and i + 1 <= n and s[i] == '.' and s[i - 1] == 'X' and s[i + 1] == 'X') {
      v.push_back(i);
    }
    else if ((i + 2 <= n and s[i] == '.' and s[i + 1] == 'X' and s[i + 2] == 'X')) {
      v.push_back(i);
    }
    else if ((i - 2 >= 1 and s[i] == '.' and s[i - 1] == 'X' and s[i - 2] == 'X')) {
      v.push_back(i);
    }
  }

  if (v.size() > 0) {
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " \n"[i + 1 == v.size()];
    }
    return;
  }

  vector<int> vec;
  vec.push_back(0);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'X') {
      vec.push_back(i);
    }
  }
  vec.push_back(n + 1);

  // for (auto x : vec) cout << x << ' '; cout << '\n';

  int pref = 0, suff = 0;
  for (int i = 1; i < vec.size(); i++) {
    int len = vec[i] - vec[i - 1] - 1;
    if (i + 1 != vec.size()) len -= 2;
    if (i  - 1 != 0) len -= 2;
    suff ^= f(len);
  }

  for (int i = 1; i < vec.size(); i++) {
    int j = vec[i - 1] + 1;

    int len = vec[i] - vec[i - 1] - 1;
    if (i + 1 != vec.size()) len -= 2;
    if (i  - 1 != 0) len -= 2, j += 2;

    suff ^= f(len);
    for (int k = 1; k <= len; k++, j++) {
      int l = max(0, k - 3), r = max(0, len - k - 2);
      int x = f(l) ^ f(r);
      int here = x ^ pref ^ suff;
      if (here == 0) v.push_back(j);
    }
    pref ^= f(len);
  }

  if (v.size() == 0) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " \n"[i + 1 == v.size()];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}