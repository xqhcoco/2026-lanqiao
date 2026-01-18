//部分背包问题
//2026-1-17
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct pie {
	int m;
	double price;
};
bool cmp(const pie& a, const pie& b)
{
	return a.price > b.price;
}
int main()
{
	int n, t;
	cin >> n >> t;
	vector<pie>arr(n);
	for (int i = 0; i < n; i++) {
		int x;
		double y;
		cin >> x >> y;
		arr[i].m = x;
		arr[i].price = y / x;
	}
	sort(arr.begin(), arr.end(), cmp);
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		if (t <= arr[i].m) {
			sum += t * arr[i].price;
			break;
		}
		sum += arr[i].m * arr[i].price;
		t -= arr[i].m;
	}
	printf("%.2f", sum);
	return 0;
}