#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int first = -1;
  int par[n];
  for (int i = 2; i < n; i++) {
    cout << "? " << 1 << ' ' << i << endl;
    int x; cin >> x;
    par[i] = 0;
    if (x == 0) {
      first = i;
      break;
    }
  }

  par[1] = 0;
  par[first] = 1;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 2; i <= first; i++) {
    pq.push(i);
  }

  int i = first + 1;
  while (i < n) {
    if (pq.size() == 1) break;
    cout << "? " << pq.top() << ' ' << i << endl;
    int x; cin >> x;
    if (x == 0) {
      par[i] = pq.top();
      pq.push(i);
      i++;
    }
    pq.pop();
  }
  while (i < n) {
    par[i] = i - 1;
    i++;
  }

  cout << "! ";
  for (int i = 1; i < n; i++) {
    cout << par[i] << ' ';
  }
  cout << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}