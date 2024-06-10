#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ull a[64];
  for(int i = 0; i < 64; i++) {
    a[i] = (1ULL << i);
  }
  ull sum = 0;
  for(int i = 0; i < 64; i++) {
    int x; cin >> x;
    a[i] *= x;
    sum += a[i];
  }
  cout << sum << '\n';

  return 0;
}