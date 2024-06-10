#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 9, MAX_VAL = 4005;
bitset<MAX_VAL> mask1[N], mask2[N];
int a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q; cin >> n >> m >> q;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  mask1[0].reset(), mask2[0].reset();
  for(int i = 1; i <= n; i++) {
    mask1[i] = mask1[i - 1];
    mask1[i].flip(a[i]);
  }
  for(int i = 1; i <= m; i++) {
    mask2[i] = mask2[i - 1];
    mask2[i].flip(b[i]);
  }

  while(q--) {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    auto first = mask1[r1] ^ mask1[l1 - 1];
    auto second = mask2[r2] ^ mask2[l2 - 1];
    auto merge = first ^ second;
    int cnt = merge.count();
    cout << cnt << '\n';
  }
        
  return 0;
}