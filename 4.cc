#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int> shuzu;
    int index=0;
	int temp2;
    for(int i=0;i<s1.length();i++)
    {
        for(int j=index;j<s2.length();j++)
        {
            if(s1[i]==s2[j])
            {
				temp2=j+1;
                shuzu.push_back(temp2);
                index=j+1;
                break;
            }
        }
    }
    vector<int> dist;
	int temp,shuchu;
    for(int k=0;k<shuzu.size()-1;k++)
    {
		temp=shuzu[k+1]-shuzu[k];
        shuchu=100-k-temp+1;
        dist.push_back(shuchu);
    }
    sort(dist.begin(),dist.end(),less<int>());
    cout<<dist[0]<<endl;
	system("pause");
    return 0;
}
