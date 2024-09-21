#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, ans;

bool ok(vector<string> &a) {
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = 1; j <= n; j++) {
      flag &= a[i][j] == '#';
    }
    if (flag) return false;
  }
  for (int j = 1; j <= n; j++) {
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      flag &= a[i][j] == '#';
    }
    if (flag) return false;
  }
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    flag &= a[i][i] == '#';
  }
  if (flag) return false;
  flag = true;
  for (int i = n, j = 1; i >= 1; i--, j++) {
    flag &= a[j][i] == '#';
  }
  if (flag) return false;
  return true;
}

int get(vector<string> &a) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans += a[i][j] == '#';
    }
  }
  return ans;
}

void f(int i, int j, vector<string> &a) {
  if (i > n) {
    // cout << "Here: " << get(a) << ' ' << ok(a) << '\n';
    // for (int i = 1; i <= n; i++) {
    //   for (int j =1; j <= n; j++) {
    //     cout << a[i][j];
    //   }
    //   cout << '\n';
    // }
    if (ok(a)) {
      if (ans < 30 and get(a) == 30) {
        cout << "Here: " << get(a) << ' ' << ok(a) << '\n';
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
            cout << a[i][j];
          }
          cout << '\n';
        }
      }
      ans = max(ans, get(a));
    }
    return;
  }
  if (j + 1 <= n) {
    f(i, j + 1, a);
    a[i][j] = '#';
    f(i, j + 1, a);
    a[i][j] = '.';
  }
  else {
    f(i + 1, 1, a);
    a[i][j] = '#';
    f(i + 1, 1, a);
    a[i][j] = '.';
  }
}

void solve() {
  vector<string> a(N);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i] = "!";
    for (int j = 1; j <= n; j++) {
      a[i] += '.';
    }
  }
  ans = 0;
  f(1, 1, a);
  // a[1][2] = '#';
  // a[2][1] = '#';
  cout << ans << '\n';
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