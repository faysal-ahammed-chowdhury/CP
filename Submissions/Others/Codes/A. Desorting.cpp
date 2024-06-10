#include <bits/stdc++.h>
using namespace std;

const int N = 509;
int n, a[N];

bool is_sorted() {
  for(int i = 1; i < n; i++) {
    if(a[i] > a[i + 1]) return false;
  }
  return true;
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  bool sorted = is_sorted();
  if(!sorted) {
    cout << 0 << '\n';
    return;
  }

  int min_dis = INT_MAX;
  int first, second;
  for(int i = 1; i < n; i++) {
    if(abs(a[i] - a[i + 1]) < min_dis) {
      min_dis = abs(a[i] - a[i + 1]);
      first = i;
      second = i + 1;
    }
  }
  int cnt = abs(a[first] - a[second]) / 2;
  cout << ++cnt << '\n';
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