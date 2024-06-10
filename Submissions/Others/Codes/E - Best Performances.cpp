#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
priority_queue<pair<int, int>> pq;
void update(int x, int y) {
  set<pair<int, int>> se;
  while(pq.top().second != x) {
    se.insert(pq.top());
    pq.pop();
  }
  pq.pop();
  pq.push({y, x});
  for(auto i: se) {
    pq.push(i);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, q; cin >> n >> k >> q;
  for(int i = 1; i <= n; i++) {
    pq.push({0, i});
  }

  while(q--) {
    int x, y; cin >> x >> y;
    update(x, y);
    long long sum = 0;
    set<pair<int, int>> se;
    for(int i = 0; i < k; i++) {
      sum += pq.top().first;
      se.insert(pq.top());
      pq.pop();
    }
    for(auto i: se) {
      pq.push(i);
    }
    cout << sum << '\n';
  }

  return 0;
}