#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e4 + 9;
pair<int, int> a[N];
bool binary_search(int start, int end, int x) {
  int l = start, r = end;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(a[mid].first <= x && a[mid].second >= x) return true;
    else if(a[mid].first < x) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  for(int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    a[i] = {x, x + y};
  }

  sort(a + 1, a + 1 + n);
  int last = a[n].second;

  int T, mn = INT_MAX; 
  for(int t = 0; t <= 480; t++) {
    int cnt = 0;
    for(int j = t; j <= last; j += x) {
      if(binary_search(1, n, j)) {
        cnt++;
      }
    }
    if(cnt < mn) {
      mn = cnt;
      T = t;
    }
  }

  cout << T << ' ' << mn << '\n';

  return 0;
}