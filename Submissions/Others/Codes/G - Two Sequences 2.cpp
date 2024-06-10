#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n], b[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long c[n];
  priority_queue<int> pq;
  for(int i = 0; i < n; i++) {
    pq.push(a[i]);
    c[i] = 1LL * b[i] * pq.top();
    if(i != 0) {
      c[i] = max(c[i], c[i - 1]);
    }
  }

  for(int i = 0; i < n; i++) {
    cout << c[i] << '\n';
  }

  return 0;
}