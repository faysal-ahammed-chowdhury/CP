#include <bits/stdc++.h>
using namespace std;

int legendre(int n, int p) {
  int ex = 0;
  while(n) {
    ex += (n / p);
    n /= p;
  }
  return ex;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  vector<int> ans;
  for(int i = 1; i <= 500009; i++) {
    int n = i;
    int pw = legendre(n, 5);
    if(pw == m) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << '\n';
  for(auto i: ans) {
    cout << i << ' ';
  }
  if(ans.size() != 0) {
    cout << '\n';
  }

  return 0;
}