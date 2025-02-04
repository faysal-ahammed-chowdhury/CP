#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  int game[n + 1][5][5];
  memset(game, 0, sizeof game);

  for (int i = 1; i <= m; i++) {
    int idx, r, c; cin >> idx >> r >> c;
    game[idx][r][c] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      int row_cnt = 0;
      for (int k = 1; k <= 3; k++) {
        row_cnt += game[i][j][k] == 1;
      }
      if (row_cnt >= 2) {
        if (m & 1) cout << "Himel\n";
        else cout << "Murad\n";
        return;
      }
    }

    for (int k = 1; k <= 3; k++) {
      int col_cnt = 0;
      for (int j = 1; j <= 3; j++) {
        col_cnt += game[i][j][k] == 1;
      }
      if (col_cnt >= 2) {
        if (m & 1) cout << "Himel\n";
        else cout << "Murad\n";
        return;
      }
    }

    int corner_1_cnt = 0;
    for (int j = 1; j <= 3; j++) {
      corner_1_cnt += game[i][j][j] == 1;
    }

    int corner_2_cnt = 0;
    for (int j = 1, k = 3; j <= 3; j++, k--) {
      corner_2_cnt += game[i][j][k] == 1;
    }

    if (corner_1_cnt >= 2 or corner_2_cnt >= 2) {
      if (m & 1) cout << "Himel\n";
      else cout << "Murad\n";
      return;
    }


    for (int j = 1; j <= 3; j++) {
      for (int k = 1; k <= 3; k++) {
        if (game[i][j][k] and j + 1 <= 3 and k + 1 <= 3 and game[i][j + 1][k + 1]) {
          if (m & 1) cout << "Himel\n";
          else cout << "Murad\n";
          return;
        }
        if (game[i][j][k] and j + 1 <= 3 and k - 1 >= 1 and game[i][j + 1][k - 1]) {
          if (m & 1) cout << "Himel\n";
          else cout << "Murad\n";
          return;
        }
      }
    }
  }

  // cout << "Here:\n";
  vector<int> mx_possible_move;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= 3; j++) {
      for (int k = 1; k <= 3; k++) {
        cnt += game[i][j][k];
      }
    }

    if (cnt == 0) mx_possible_move.push_back(2);
    else {
      if (game[i][2][2]) mx_possible_move.push_back(0);
      else {
        if (cnt == 1) mx_possible_move.push_back(1);
        else mx_possible_move.push_back(0);
      }
    }
  }

  int xr = 0;
  for (auto x : mx_possible_move) xr ^= x;

  if (xr != 0) cout << ((m & 1) ? "Himel\n" : "Murad\n");
  else cout << ((m & 1) ? "Murad\n" : "Himel\n");
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