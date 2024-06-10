#include <bits/stdc++.h>
using namespace std;

const int N = 1009;
int spf[N];

void spf_sieve() {
  for(int i = 1; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if(spf[i] == i) {
      for(int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

vector<int> g[N];
bool vis[N];
int level[N];

void bfs(int u) {
  queue<int> q;
  q.push(u);
  vis[u] = true;
  level[u] = 0;

  while(!q.empty()) {
    int top = q.front(); q.pop();
    for(auto v: g[top]) {
      if(!vis[v]) {
        level[v] = level[top] + 1;
        q.push(v);
        vis[v] = true;
      }
    }
  }
}

int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  memset(vis, 0, sizeof(vis));
  memset(level, -1, sizeof(level));
  int n, s; cin >> n >> s;
  bfs(n);
  cout << level[s] << '\n';
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  for(int i = 2; i < N; i++) {
    int x = i;
    if(spf[x] == x) continue;
    while(x > 1) {
      int p = spf[x];
      if(p + i < N) {
        g[i].push_back(i + p);
      }
      while(x % p == 0) {
        x /= p;
      }
    }
  }


  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}