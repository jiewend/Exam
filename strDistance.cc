#include <iostream> 

using namespace std;

int strDistance(string pp, string qq) {
    int len1 = pp.size();
    int len2 = qq.size();
    int d[len1+1][len2+1];
    int i,j;   
    for(i = 0;i <= len1;i++)   
        d[i][0] = i;
    for(j = 0;j <= len2;j++)   
        d[0][j] = j;   
    for(i = 1;i <= len1;i++)   
        for(j = 1;j <= len2;j++) {   
			if(pp[i -1] == qq[j-1]){
				d[i][j] = d[i-1][j-1];
			} else {
				int deletion = d[i-1][j] + 1;
				int insertion = d[i][j-1] + 1;
				d[i][j] = min(deletion, insertion);
			}
        }   
	return d[len1][len2];
}

int main(){
	string inStr1, inStr2;
	getline(cin, inStr1);
	getline(cin, inStr2);
	cout<<strDistance(inStr1, inStr2)<<endl;
}
