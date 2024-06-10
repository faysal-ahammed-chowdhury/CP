#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int vis[N], ans_idx[N];
vector<int> seq[N];

int32_t main() {
  // freopen("generators.in", "r", stdin);
  // freopen("generators.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int n, k; cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(vis, 0, sizeof(vis));
    int x, a, b, c; cin >> x >> a >> b >> c;
    seq[i].push_back(x);
    vis[x] = true;
    for (int j = 1;; j++) {
      int y = ((a * seq[i][j - 1]) + b) % c;
      if (vis[y]) break;
      vis[y] = true;
      seq[i].push_back(y);
    }

    int mx = -1, idx;
    for (int j = 0; j < seq[i].size(); j++) {
      if (seq[i][j] > mx) {
        mx = seq[i][j];
        idx = j;
      }
    }
    ans_idx[i] = idx;
    ans += mx;
  }

  if (ans % k != 0) {
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      cout << ans_idx[i] << ' ';
    }
    cout << '\n';
  }
  else {
    int mx_ans = -1, change_i, new_idx;
    for (int i = 0; i < n; i++) {
      int tmp_ans = ans;
      tmp_ans -= seq[i][ans_idx[i]];
      for (int j = 0; j < seq[i].size(); j++) {
        if ((tmp_ans + seq[i][j]) % k != 0) {
          if (tmp_ans + seq[i][j] > mx_ans) {
            mx_ans = tmp_ans + seq[i][j];
            change_i = i, new_idx = j;
          }
        }
      }
    }
    if (mx_ans == -1) {
      cout << mx_ans << '\n';
    }
    else {
      cout << mx_ans << '\n';
      for (int i = 0; i < n; i++) {
        if (i == change_i) {
          cout << new_idx << ' ';
        }
        else {
          cout << ans_idx[i] << ' ';
        }
      }
      cout << '\n';
    }
  }


  return 0;
}