#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<int> vi;
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}
#define cpheader
#endif


using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vi m1(n), m2(n);
  string s;
  int arr[] = {9, 11, 0,2,4,5,7};

  f0r (i, n) {
    cin >> s;
    if (s.size() == 1) { m1[i] = -1; }
    if (s.size() == 2) { m1[i] = (arr[s[0]-'A']) + (s[1]-'1'+1)*12; }
    if (s.size() == 3) { m1[i] = (arr[s[0]-'A']) + (s[2]-'1'+1)*12 + (s[1] == '#') - (s[1] == 'b'); } 
  }

  f0r (i, n) {
    cin >> s;
    if (s.size() == 1) { m2[i] = -1; }
    if (s.size() == 2) { m2[i] = (arr[s[0]-'A']) + (s[1]-'1'+1)*12; }
    if (s.size() == 3) { m2[i] = (arr[s[0]-'A']) + (s[2]-'1'+1)*12 + (s[1] == '#') - (s[1] == 'b');} 
  }

  int diff = INT_MAX;

  F0R (i, 0, n) {
    if (m1[i] == -1 && m2[i] == -1)
    { 
      continue;
    } else if ((m1[i] == -1) != (m2[i] == -1)) {
      cout << "Neibb";
      return 0;
    }
    if (diff == INT_MAX) {
      diff = m1[i] - m2[i]; 
    }
    if (diff != m1[i] - m2[i]) {
      cout << "Neibb";
      return 0;
    } 
  }

  cout << "Jebb";

  return 0;
}
