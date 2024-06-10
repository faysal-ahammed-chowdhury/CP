#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8;
int n, m;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  if(n > 30) {
    cout << m << '\n';
  }
  else {
    int x = 1 << n;
    cout << m % x << '\n';
  }
  return 0;
}