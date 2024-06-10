#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  priority_queue<int> pq;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    x = abs(x);
    pq.push(-x); 
  }
  int idx = 0;
  while(!pq.empty()) {
    int took = -pq.top();
    pq.pop();
    if(idx % 2 == 0) {
      cout << -took << ' ';
    }
    else {
      cout << took << ' ';
    }
    idx++;
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}