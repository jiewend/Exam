#include <bits/stdc++.h> 
using namespace std;
int gcb(int a, int b){
	return b == 0 ? a:gcb(b, a % b);
}
int main(){
	int n;
	string cur;
	set<string> st;
	scanf("%d", &n);
	for (unsigned i = 1; i <= n; ++i) { 
		cin>>cur;
		for (unsigned j = 0; j < cur.size(); ++j) { 
			cur[i] = tolower(cur[j]);
		} 
		sort(cur.begin(), cur.end());
		st.insert(cur);
	} 
	cout<<st.size()<<endl;
	return 0;
}

