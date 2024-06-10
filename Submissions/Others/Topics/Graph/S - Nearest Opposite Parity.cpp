#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 2e9;
vector<int> g[N];
vector<int> ans(N, inf);
int n; 

void fun(vector<int> even, vector<int> odd) {
  queue<int> q;
  vector<int> dis(n + 1, inf);
  for(auto x: even) {
    q.push(x);
    dis[x] = 0;
  }

  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto v: g[u]) {
      if(dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }

  for(auto x: odd) {
    ans[x] = dis[x];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> odd, even;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    int j = i + x;
    if(j <= n) g[j].push_back(i);
    j = i - x;
    if(j >= 1) g[j].push_back(i);
    if(x & 1) odd.push_back(i);
    else even.push_back(i);
  }

  fun(odd, even);
  fun(even, odd);

  for(int i = 1; i <= n; i++) {
    cout << (ans[i] == inf ? -1 : ans[i]) << ' ';
  }
  cout << '\n';


  return 0;
}