#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n, tail[N][N], dp[(1 << N) + 2][N + 2];
string s[N + 2];

bool cmp(string a, string b) {
  if (a.size() < b.size()) {
    return true;
  }
  return false;
}

int fun(int mask, int last) {
  if (__builtin_popcount(mask) >= n) {
    return 0;
  }

  int &ans = dp[mask][last];
  if (ans != -1) return ans;

  ans = 1e9;
  for (int j = 1; j <= n; j++) {
    if (!(mask & (1 << j))) {
      if (last == n + 1) {
        int x = s[j].length() + fun(mask | (1 << j), j);
        ans = min(ans, x);
      }
      else {
        int x = (s[j].length() - tail[last][j]) + fun(mask | (1 << j), j);
        ans = min(ans, x);
      }
    }
  }

  return ans;
}


void print(int mask, int last) {
  if (__builtin_popcount(mask) >= n) {
    return;
  }

  int ans = fun(mask, last), idx = -1;
  string str = "{";
  for (int j = 1; j <= n; j++) {
    if (!(mask & (1 << j))) {
      if (last == n + 1) {
        int x = s[j].length() + fun(mask | (1 << j), j);
        if (x == ans) {
          string d = s[j];
          if (d <= str) {
            str = d;
            idx = j;
          }
        }
      }
      else {
        int x = (s[j].length() - tail[last][j]) + fun(mask | (1 << j), j);
        if (x == ans) {
          string d = s[j].substr(tail[last][j]);
          if (d <= str) {
            str = d;
            idx = j;
          }
        }
      }
    }
  }

  cout << s[idx].substr(tail[last][idx]);
  print(mask | (1 << idx), idx);
}

int cs = 0;
void solve() {
  cin >> n;
  string str[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
  }

  // remove duplicates and strings which is a subarray of others
  sort(str + 1, str + n + 1, cmp);
  vector<string> vec;
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (int j = i + 1; j <= n; j++) {
      if (str[j].find(str[i]) != string::npos) {
        ok = false;
        break;
      }
    }
    if (ok) {
      vec.push_back(str[i]);
    }
  }

  n = vec.size();
  int idx = 1;
  for (auto x : vec) {
    s[idx++] = x;
  }

  // maximum length that suffix of a[i] = prefix of a[j]
  memset(tail, 0, sizeof(tail));
  for (int i = 1; i <= n; i++) {
    string x = s[i];
    for (int j = 1; j <= n; j++) {
      string y = s[j];
      int cnt = 0;
      for (int k = min(x.length(), y.length()); k >= 1; k--) {
        if (x.substr(x.length() - k) == y.substr(0, k)) {
          cnt = k;
          break;
        }
      }
      tail[i][j] = cnt;
    }
  }

  memset(dp, -1, sizeof(dp));
  fun(0, n + 1);
  cout << "Case " << ++cs << ": ";
  print(0, n + 1);
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}