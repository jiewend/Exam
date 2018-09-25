#include <iostream> 

using namespace std;
string change(string aa, int l, int r, int neg){
	if(neg != -1){
	for (unsigned i = l; i < r; i++) { 
		if(aa[i] == '+'){
			aa[i] = '-';
		}else{
		if(aa[i] == '-'){
			aa[i] = '+';
		}
	}
	}}
	aa.erase(r, 1);
	aa.erase(l, 1);
	return aa;
}
int findRightBasket(string aa){
	for (unsigned i = 0; i < aa.size(); i++) 
		if(aa[i] == ')')
			return i;
	return -1;
}
int findLeftBasket(string aa, int left){
	for (unsigned i = left - 1; i > 0; i--) 
		if(aa[i] == '(')
			return i;
}
int findNeg(string aa, int leftBasketTap){
	for (unsigned i = leftBasketTap; i > 0; i--) 
		if(aa[i] == '-')
			return i;
		else if(aa[i] == '+')
			return -1;
}
void simExper(string inStr){
	int rightBasket = findRightBasket(inStr);
	if(rightBasket == -1){
		cout<<inStr<<endl;
		return ;
	} else {
		int leftBasket = findLeftBasket(inStr, rightBasket);
		int neg = findNeg(inStr, leftBasket);
		inStr = change(inStr, leftBasket, rightBasket, neg);
		simExper(inStr);
	}
}

int main(){
	string aa = "x-(p+q)-(y-a)";
	cout<<aa<<endl;
	// getline(cin, aa);
	simExper(aa);
}
