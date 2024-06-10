#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  map<int , int> mp;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for(auto i: mp) {
    pq.push({i.first, i.second});
  }
  int last = -1, last_cnt = INT_MAX;
  while(!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();
    if(p.first != last + 1) {
      cout << "NO\n";
      return;
    }
    if(p.second > last_cnt) {
      cout << "NO\n";
      return;
    }
    last = p.first;
    last_cnt = p.second;
  }
  cout << "YES\n";
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}