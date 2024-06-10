#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(vector<int> v) {
  int n = v.size();
  vector<int> d;
  for (int i = 0; i + 1 < n; i++) {
    d.push_back(v[i + 1] - v[i]);
  }
  int i = 0, j = n - 2;
  while (i < j) {
    if (d[i] != d[j]) return false;
    i++, j--;
  }
  return true;
}

void solve(int n, int x) {
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (i != x) vec.push_back(i);
  }

  do {
    vector<int> v;
    v.push_back(x);
    for (auto val : vec) v.push_back(val);
    if (is_palindrome(v)) {
      cout << "YES\n";
      for (auto val : v) {
        cout << val << ' ';
      }
      cout << '\n';
    }

  } while(next_permutation(vec.begin(), vec.end()));
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve(4, 3);

  return 0;
}