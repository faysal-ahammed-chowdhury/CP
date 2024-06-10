#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int a, b, c;
char sign, other;

string number_to_str(int n) {
  stringstream ss;
  ss << n;
  string s; ss >> s;
  return s;
}

int str_to_num(string s) {
  int n = 0;
  for(auto i : s) {
    n = n * 10 + (i - '0');
  }
  return n;
}

void swap_prefix(string &s1, string &s2, int first1, int first2) {
  int len1 = s1.length();
  int len2 = s2.length();
  string first_s1, last_s1, first_s2, last_s2;
  first_s1 = "", first_s2 = "", last_s1 = "", last_s2 = "";
  for(int i = 0; i < first1; i++) {
    first_s1 += s1[i];
  }
  for(int i = first1; i < len1; i++) {
    last_s1 += s1[i];
  }
  for(int i = 0; i < first2; i++) {
    first_s2 += s2[i];
  }
  for(int i = first2; i < len2; i++) {
    last_s2 += s2[i];
  }
  s1 = first_s2 + last_s1;
  s2 = first_s1 + last_s2;
}

bool ok(int a, int b, int c, char sign) {
  if(sign == '+') {
    return a + b == c; 
  }
  return a * b == c;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> sign >> b >> other >> c;

  string s1,s2, s3;
  s1 = number_to_str(a);
  s2 = number_to_str(b);
  s3 = number_to_str(c);

  int len1 = s1.length();
  int len2 = s2.length();
  int len3 = s3.length();

  // assume a ok
  for(int i = 1; i < len2; i++) {
    for(int j = 1; j < len3; j++) {
      string s2_tmp = s2, s3_tmp = s3;
      swap_prefix(s2_tmp, s3_tmp, i, j);
      int b_tmp = str_to_num(s2_tmp);
      int c_tmp = str_to_num(s3_tmp);
      if(ok(a, b_tmp, c_tmp, sign)) {
        cout << a << " " << sign << " " << b_tmp << " = " << c_tmp << '\n';
      }
    }
  }

  for(int i = 1; i < len1; i++) {
    for(int j = 1; j < len3; j++) {
      string s1_tmp = s1, s3_tmp = s3;
      swap_prefix(s1_tmp, s3_tmp, i, j);
      int a_tmp = str_to_num(s1_tmp);
      int c_tmp = str_to_num(s3_tmp);
      if(ok(a_tmp, b, c_tmp, sign)) {
        cout << a_tmp << " " << sign << " " << b << " = " << c_tmp << '\n';
      }
    }
  }

  for(int i = 1; i < len1; i++) {
    for(int j = 1; j < len2; j++) {
      string s1_tmp = s1, s2_tmp = s2;
      swap_prefix(s1_tmp, s2_tmp, i, j);
      int a_tmp = str_to_num(s1_tmp);
      int b_tmp = str_to_num(s2_tmp);
      if(ok(a_tmp, b_tmp, c, sign)) {
        cout << a_tmp << " " << sign << " " << b_tmp << " = " << c << '\n';
      }
    }
  }

  return 0;
}