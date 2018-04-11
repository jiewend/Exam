#include <iostream> 
#include <stack> 

using namespace std;
int main(){
	int N, K, H;
	cin>>N;
	cin>>K;
	cin>>H;
	int Ti[N];
	stack<int> T;
	for (unsigned i = 0; i < N; i++) { 
	    cin>>Ti[i];
	} 
	for (unsigned i = 0; i < N; i++) { 
		T.push(Ti[N - 1 - i]);
	} 
	int pos = 0, posTemp = 0, TLastTop = T.top();
	for (unsigned i = 0; i < K ; i++) {//最多跳K次 
		if(T.empty()){
			break;
		}
		while(T.top() - pos <= H) {//下一个跳板能跳到，但还要看下下个能不能跳到
			TLastTop = T.top();
			T.pop();
			if(T.empty())
				break;
		}
		pos = (TLastTop - pos) * 2 + pos;
	} 
	cout<<pos<<endl;
}
