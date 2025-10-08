#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 35;
int n, k, dp[N][450];

bool f(int i, int need) {
  if (i > n) return need == 0;
  int &ans = dp[i][need];
  if (ans != -1) return ans;
  ans = 0;
  for (int j = 1; j <= n - i + 1; j++) {
    int cnt = (j * (j - 1)) / 2;
    if (cnt <= need) {
      ans |= f(i + j, need - cnt);
    }
  }
  return ans;
}

void print(int i, int need, vector<int> &p) {
  if (i > n) return;
  stack<int> st;
  for (int j = 1; j <= n - i + 1; j++) {
    st.push(p.back());
    p.pop_back();
    int cnt = (j * (j - 1)) / 2;
    if (cnt <= need) {
      if (f(i + j, need - cnt)) {
        while (!st.empty()) {
          cout << st.top() << ' ';
          st.pop();
        }
        return print(i + j, need - cnt, p);
      }
    }
  }
}

void solve() {
  cin >> n >> k;
  k = ((n * (n  - 1)) / 2) - k;
  // cout << n << ' ' << k << ' ';

  memset(dp, -1, sizeof dp);
  bool ans = f(1, k);
  if (!ans) {
    cout << 0 << '\n';
    return;
  }

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  print(1, k, v);
  cout << '\n';
  assert(v.size() == 0);
  // cout << v.size() << '\n';
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