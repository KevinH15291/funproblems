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
  vi nums(n);
  f0r(i, n) {
    cin >> nums[i];
  }
  int l = 0, r=n-1, a = 0, b = 0;
  f0r(i, n) {
    if (i % 2) {
    if (nums[l] > nums[r]) {
      a+=nums[l];
      l++;
    } else {
      a+=nums[r];
      r--;
    }
    } else {
    if (nums[l] > nums[r]) {
      b+=nums[l];
      l++;
    } else {
      b+=nums[r];
      r--;
    }
    }
  }
  cout << b << " " << a;

  return 0;
}
