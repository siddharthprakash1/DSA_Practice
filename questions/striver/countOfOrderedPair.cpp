// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the number of possible
// ordered pairs
long long countPairs(int n, int x, vector<int> v)
{
	int power[10]
		= { 1, 10, 100,
			1000, 10000, 100000,
			1000000, 10000000,
			100000000,
			1000000000 };

	// Stores the count of digits of each number
	vector<int> len;
	long long count = 0;
	for (int i = 0; i < n; i++)
		len.push_back(log10(v[i]) + 1);

	unordered_map<int, int> mp;
	mp[v[0]]++;

	// Iterating from the start
	for (int i = 1; i < n; i++) {
		if (x % power[len[i]] == v[i])
			count += mp[x / power[len[i]]];
cout<<"count = "<<count<<endl;
		mp[v[i]]++;
	}

	mp.clear();
	mp[v[n - 1]]++;

	// Iterating from the end
	for (int i = n - 2; i >= 0; i--) {
		if (x % power[len[i]] == v[i])
			count += mp[x / power[len[i]]];
cout<<"c = "<<count<<endl;
		mp[v[i]]++;
	}
	return count;
}

// Driver Code
int main()
{
	int N = 4;
	int X = 1212;
	vector<int> numbers = { 1, 212, 12, 12 };
	long long ans = countPairs(N, X, numbers);
	cout << ans << endl;
	return 0;
}
