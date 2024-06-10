#include <bits/stdc++.h>
using namespace std;

#define EMPTY '.'
#define IMPASSABLE '*'
const int N = 1005;
string s[N];
int n, m, cnt;
int vis1[N][N], vis2[N][N], a[N][N];
pair<int, int> par[N][N];

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool is_valid(int i, int j) {
  return i >= 0 and i < n and j >= 0 and j < m;
}

void dfs1(int i, int j) {
  cnt++;
  vis1[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if (is_valid(new_i, new_j) and !vis1[new_i][new_j] and s[new_i][new_j] == EMPTY) {
      dfs1(new_i, new_j);
    }
  }
}

void dfs2(int i, int j, int par_i, int par_j) {
  par[i][j] = make_pair(par_i, par_j);
  a[i][j] = cnt;
  vis2[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if (is_valid(new_i, new_j) and !vis2[new_i][new_j] and s[new_i][new_j] == EMPTY) {
      dfs2(new_i, new_j, par_i, par_j);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis1[i][j] and s[i][j] == EMPTY) {
        cnt = 0;
        dfs1(i, j);
        dfs2(i, j, i, j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == IMPASSABLE) {
        int ans = 1;
        set<pair<int, int>> se;
        for (int k = 0; k < 4; k++) {
          int new_i = i + dx[k];
          int new_j = j + dy[k];
          if (is_valid(new_i, new_j) and s[new_i][new_j] == EMPTY and se.find(par[new_i][new_j]) == se.end()) {
            ans += a[new_i][new_j];
            se.insert(par[new_i][new_j]);
          }
        }
        cout << ans % 10;
      }
      else {
        cout << '.';
      }
    }
    cout << '\n';
  }

  return 0;
}