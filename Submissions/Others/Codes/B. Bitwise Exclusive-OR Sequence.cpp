#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1], b[n + 1];
  vector<pair<pair<int, int>, int>> arr;
  memset(a, -1, sizeof(a));
  memset(b, -1, sizeof(b));
  while(m--) {
    int u, v, w; cin >> u >> v >> w;
    pair<pair<int, int>, int> p = {{u, v}, w};
    arr.push_back(p);
    if(w == 0) {
      a[u] = 0;
      a[v] = 0;
    }
    else {
      a[u] = w;
      a[v] = 0;
      b[u] = 0;
      b[v] = w;
    }
  }
        
  return 0;
}