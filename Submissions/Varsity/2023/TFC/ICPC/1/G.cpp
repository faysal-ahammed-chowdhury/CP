#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

bool is_sorted(vector<int> &v) {
  int last = -1;
  for(auto i: v) {
    if(i < last) {
      return false;
    }
    last = i;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  
  int start = -1;
  int end = -1;
  for(int i = 1; i <= n; i++) {
    if(a[i] != b[i]) {
      if(start == -1) {
        start = i;
      }
      end = i;
    }
  }

  if(start == end) {
    cout << 1 << ' ' << 1 << '\n';
    return 0;
  }

  vector<int> v;
  for(int i = end; i >= start; i--) {
    v.push_back(a[i]);
  }

  if(!is_sorted(v)) {
    cout << "impossible\n";
    return 0;
  }

  cout << start << ' ' << end << '\n';

  return 0;
}