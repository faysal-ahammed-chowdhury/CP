#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

void solve() {
  int n, k; cin >> n >> k;
  string s[n + 1];
  bool go_out[n + 1][n + 1];
  memset(go_out, false, sizeof go_out);
  for (int i = 1; i <= n; i++) {
    s[i] = '.';
    for (int j = 1; j <= n; j++) {
      s[i] += '#';
    }
  }

  int u = 1, d = n, l = 1, r = n;
  while (true) {
    for (int i = l; k > 0 and i <= r; i++, k--) {
      s[u][i] = 'U';
      go_out[u][i] = true;
    }
    for (int i = l;  k > 0 and i <= r; i++, k--) {
      s[d][i] = 'D';
      go_out[d][i] = true;
    }
    u++, d--;
    for (int i = u;  k > 0 and i <= d; i++, k--) {
      s[i][l] = 'L';
      go_out[i][l] = true;
    }
    for (int i = u;  k > 0 and i <= d; i++, k--) {
      s[i][r] = 'R';
      go_out[i][r] = true;
    }
    l++, r--;

    if (l > r) break;
  }

  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      cnt += s[i][j] == '#';
    }

    if (cnt > 1) {
      bool first = true;
      for (int j = 1; j <= n; j++) {
        if (s[i][j] == '#') {
          if (first) s[i][j] = 'R';
          else s[i][j] = 'L';
          first = false;
        }
      }
    }
    else {
      for (int j = 1; j <= n; j++) {
        if (s[i][j] != '#') continue;
        bool flag = false;
        for (int k = 0; k < 4; k++) {
          int ii = i + dx[k];
          int jj = j + dy[k];
          bool valid = ii >= 1 and ii <= n and jj >= 1 and jj <= n;
          if (valid and !go_out[ii][jj]) {
            if (dx[k] > 0) s[i][j] = 'D';
            else if (dx[k] < 0) s[i][j] = 'U';
            else if (dy[k] > 0) s[i][j] = 'R';
            else if (dy[k] < 0) s[i][j] = 'L';
            flag = true;
            break;
          }
        }
        if (!flag) {
          cout << "NO\n";
          return;
        }
      }
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << s[i].substr(1) << '\n';
  }
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