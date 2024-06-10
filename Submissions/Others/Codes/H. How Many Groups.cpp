#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 9;
vector<int> graph[N];
vector<bool> visited(N, false);
int groups[N], ans[N];

void dfs(int src, map<int, int> &mp) {
  visited[src] = true;
  mp[groups[src]]++;
  // cout << src << ": ";
  // for(auto i: mp) {
  //   cout << i.first << ' ';
  // }
  // cout << '\n';
  ans[src] = mp.size();
  for (auto i: graph[src]) {
    if (!visited[i]) {
      if(mp.find(groups[src]) == mp.end()) {
        mp[groups[src]]++;
      }
      dfs(i, mp);
    }
  }
  mp[groups[src]]--;
  if(mp[groups[src]] == 0) {
    mp.erase(groups[src]);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int src;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    if(x == 0) {
      src = i;
      continue;
    }
    graph[i].push_back(x);
    graph[x].push_back(i);
  }

  for(int i = 1; i <= n; i++) {
    cin >> groups[i];
  }

  map<int, int> mp;
  dfs(src, mp);

  for(int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  // for(int i = 1; i <= n; i++) {
  //   cout << i << ": ";
  //   for(auto j: graph[i]) {
  //     cout << j << ' ';
  //   }
  //   cout << '\n';
  // }
        
  return 0;
}