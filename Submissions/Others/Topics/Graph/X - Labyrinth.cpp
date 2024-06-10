#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, g[N][N];
bool vis[N][N];
pair<int, int> par[N][N];

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

bool ok(int i, int j) {
  if(!(i >= 1 and i <= n and j >= 1 and j <= m)) return false;
  if(vis[i][j]) return false;
  if(g[i][j] == 0) return false;
  return true;
}

void bfs(int i, int j) {
  vis[i][j] = true;
  queue<pair<int, int>> q;
  q.push({i, j});
  while(!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    for(int k = 0; k < 4; k++) {
      int new_i = top.first + dx[k];
      int new_j = top.second + dy[k];
      if(ok(new_i, new_j)) {
        q.push({new_i, new_j});
        vis[new_i][new_j] = true;
        par[new_i][new_j] = top;
      }
    }
  }
}

char direction(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first, y1 = p1.second;
  int x2 = p2.first, y2 = p2.second;
  if(y1 > y2) return 'L';
  if(y1 < y2) return 'R';
  if(x1 < x2) return 'D';
  return 'U';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  pair<int, int> start, end;
  for(int i = 1; i <= n; i++) {
    string s; cin >> s;
    for(int j = 1; j <= m; j++) {
      if(s[j - 1] == '#') {
        g[i][j] = 0;
      }
      else {
        g[i][j] = 1;
      }

      if(s[j - 1] == 'A') {
        start = {i, j};
      }
      else if(s[j - 1] == 'B') {
        end = {i, j};
      }
    }
  }

  memset(par, -1, sizeof(par));
  bfs(start.first, start.second);

  vector<pair<int, int>> v;
  pair<int, int> curr = end;
  while(curr.first != -1 and curr.second != -1) {
    v.push_back(curr);
    curr = par[curr.first][curr.second];
  }

  int x = (int) v.size() - 1;
  if(x == 0) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  cout << x << '\n';
  reverse(v.begin(), v.end());
  for(int i = 0; i < x; i++) {
    cout << direction(v[i], v[i + 1]);
  }

  return 0;
}