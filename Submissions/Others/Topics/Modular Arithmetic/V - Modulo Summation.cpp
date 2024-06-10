#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    sum += x;
  }
  cout << sum - n << '\n';
  return 0;
}