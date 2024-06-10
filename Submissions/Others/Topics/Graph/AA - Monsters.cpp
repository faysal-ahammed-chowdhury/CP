#include <bits/stdc++.h>
using namespace std;

const int N = 1005, inf = 1e9;
int g[N][N];
pair<int, int> par[N][N];
int n, m;

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

bool ok(int i, int j) {
  if(!(i >= 1 and i <= n and j >= 1 and j <= m)) return false;
  if(g[i][j] == 0) return false;
  return true;
}

char direction(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first, y1 = p1.second;
  int x2 = p2.first, y2 = p2.second;
  if(y1 > y2) return 'L';
  if(y1 < y2) return 'R';
  if(x1 < x2) return 'D';
  return 'U';
}

vector<vector<int>> bfs(vector<pair<int, int>> sources) {
  vector<vector<int>> dis(n + 2, vector<int> (m + 2, inf));
  queue<pair<int, int>> q;
  for(auto [first, second]: sources) {
    q.push({first, second});
    dis[first][second] = 0;
  }
  while(!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();

    for(int k = 0; k < 4; k++) {
      int new_i = i + dx[k];
      int new_j = j + dy[k];
      if(ok(new_i, new_j) and dis[i][j] + 1 < dis[new_i][new_j]) {
        dis[new_i][new_j] = dis[i][j] + 1;
        q.push({new_i, new_j});
        par[new_i][new_j] = {i, j};
      }
    }
  }

  return dis;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  vector<pair<int, int>> monsters;
  pair<int, int> me;
  for(int i = 1; i <= n; i++) {
    string s; cin >> s;
    for(int j = 1; j <= m; j++) {
      if(s[j - 1] == 'A') {
        me = {i, j};
      }
      else if(s[j - 1] == 'M') {
        monsters.push_back({i, j});
      }

      if(s[j - 1] == '#') {
        g[i][j] = 0;
      }
      else {
        g[i][j] = 1;
      }
    }
  }

  auto dis1 = bfs(monsters);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      par[i][j] = {-1, -1};
    }
  }
  vector<pair<int, int>> my_start;
  my_start.push_back(me);
  auto dis2 = bfs(my_start);


  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if((i == 1 or j == 1 or i == n or j == m) and g[i][j] == 1) {
        if(dis2[i][j] < dis1[i][j]) {
          cout << "YES\n";
          vector<pair<int, int>> v;
          pair<int, int> curr = {i, j};
          while(true) {
            v.push_back(curr);
            if(curr.first == me.first and curr.second == me.second) break;
            curr = par[curr.first][curr.second];
          }
          reverse(v.begin(), v.end());
          int x = (int) v.size() - 1;
          cout << x << '\n';
          for(int i = 0; i < x; i++) {
            cout << direction(v[i], v[i + 1]);
          }
          return 0;
        }
      }
    }
  }

  cout << "NO\n";

  return 0;
}