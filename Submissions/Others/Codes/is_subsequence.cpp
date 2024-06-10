#include <bits/stdc++.h>
using namespace std;

// check p is a subsequence of s or not
bool is_subsequence(string s, string p) {
  int len = s.size(), m = p.size();
  int curr_idx = 0;
  for(int i = 0; i < len && curr_idx < m; i++) {
    if(s[i] == p[curr_idx]) {
      curr_idx++;
    }
  }
  if(curr_idx < m) {
    return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}