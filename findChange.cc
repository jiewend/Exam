#include <iostream> 
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
template <typename T>
vector<T> splitSpace(std::string stri, T outType){
	string temp;
	vector<T>res;
	istringstream stream(stri);
	while (stream >> temp)
	{
		stringstream iss;
		iss << temp;
		T f;
		iss >> f;
		res.push_back(f);
	}
	return res;
}

int change(int amount, vector<int>& coins) {
	if (amount == 0)
		return 1;
	int len = coins.size();
	if (len == 0)
		return 0;
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int i = 0; i<len; i++) {
		for (int j = coins[i]; j <= amount; j++) {
			dp[j] += dp[j - coins[i]];  
		}
	}
	return dp[amount];
}

int main()
{
	int N, M;
	cin >> N>> M;
	vector<int> P;
	
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		P.push_back(a);
	}
	int res = change(M, P);
	cout << res<< endl;
	return 0;
}

