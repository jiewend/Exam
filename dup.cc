#include<iostream>
#include<string>
#include<istream>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	int Num;
	cin >> Num;
	while (Num--)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<char> > MY;
		vector<vector<char> > res;
		for (int i = 0; i < N; i++)
		{
			vector<char>temp_char;
			for (int j = 0; j < N; j++)
			{
				char temp;
				cin >> temp;
				temp_char.push_back(temp);
			}
			MY.push_back(temp_char);
		}
		int mid1 = N / 2;
		int mid2 = M / 2;
		int cn1 = (M - N) / 2;
		//		res[mid2][mid2] = MY[mid1][mid1];
		for (int imyres1 = 0; imyres1 < cn1; imyres1++)
		{
			vector<char>temp_char1;
			for (int k1 = 0; k1 < cn1; k1++)
			{
				temp_char1.push_back(MY[k1][imyres1]);
			}
			for (int z = 0; z < N; z++)
			{
				temp_char1.push_back(MY[imyres1][z]);
			}
			for (int k2 = cn1 - 1; k2 >= 0; k2--)
			{
				temp_char1.push_back(MY[k2][imyres1]);
			}
			res.push_back(temp_char1);
		}
		for (int imyres2 = 0; imyres2 < N; imyres2++)
		{
			vector<char>temp_char1;
			for (int k1 = 0; k1 < cn1; k1++)
			{
				temp_char1.push_back(MY[k1][imyres2]);
			}
			for (int z = 0; z < N; z++)
			{
				temp_char1.push_back(MY[imyres2][z]);
			}
			for (int k2 = cn1 - 1; k2 >= 0; k2--)
			{
				temp_char1.push_back(MY[k2][imyres2]);
			}
			res.push_back(temp_char1);
		}
		for (int imyres3 = cn1-1; imyres3 >= 0; imyres3--)
		{
			res.push_back(res[imyres3]);
		}

		for (int x = 0; x < M; x++)
		{
			for (int y = 0; y < M; y++)
			{
				cout << res[x][y];
			}
			cout << endl;
		}
	}

	return 0;
}
