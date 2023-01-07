#include <bits/stdc++.h>
using namespace std;

void test_case() {
	int n, k;
	cin >> n >> k;
	k += 1;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int cur = 1;
		while (a[i]--) {
			cur *= 10;
		}
		a[i] = cur;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int cnt = k;
		if (i + 1 < n) {
			cnt = min(cnt, a[i+1] / a[i] - 1);
		}
		res += a[i] * 1LL * cnt;
		k -= cnt;
	}
	cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case();
	}
}
