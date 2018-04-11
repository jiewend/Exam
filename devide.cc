#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<map> 


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int N,X,Y;
		cin >> N;
		int flag = false;
		
			X = 1;
			Y = 1;
			while (N % 2 == 0)
			{
				Y = Y * 2;
				X = N / 2;
				N = N / 2;
				flag = true;
			}

			if((X % 2 ==0 && flag) || flag==false)
				cout << "No" << endl;
			else
			{
				cout << X<<" " << Y << endl;
			}

	}
	return 0;
}
