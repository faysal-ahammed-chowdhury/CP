#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int min_value[10] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int max_value[10] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999};

void solve() {
  int a, b, c; long long k; cin >> a >> b >> c >> k;
  for(int i = min_value[a]; i <= max_value[a]; i++) {
    int c_min = min_value[c];
    int c_max = max_value[c];
    int b_min = c_min - i;
    int b_max = c_max - i;
    b_min = max(b_min, min_value[b]);
    b_max = min(b_max, max_value[b]);
    if(b_max < b_min) continue;
    long long options = b_max - b_min + 1;
    if(options >= k) {
      cout << i << " + " << b_min + k - 1 << " = " << i + b_min + k - 1 << "\n";
      return;
    }
    k -= options;
  }
  cout << "-1\n";
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