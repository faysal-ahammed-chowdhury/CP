#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> g[N];
bool vis[N][N];
int n, x, y;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool is_valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= n;
}

void dfs(int i, int j) {
  vis[i][j] = true;
  for (int k = 0; k < 8; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if (is_valid(new_i, new_j) and new_i != x and new_j != y and !vis[new_i][new_j]) {
      dfs(new_i, new_j);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int ax, ay; cin >> ax >> ay;
  int bx, by; cin >> bx >> by;
  int cx, cy; cin >> cx >> cy;
  x = ax, y = ay;
  dfs(bx, by);

  if (vis[cx][cy]) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }

  return 0;
}