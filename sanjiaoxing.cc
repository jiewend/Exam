#include <iostream>
#include <vector>
#include <istream> 
#include <sstream> 
#include <string.h> 

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
int trangle_num(int N){
    if (N == 1){
        cout<<"1/1"<<endl;
        return 0;
    }
    if (N == 2){
        cout<<"1/2"<<endl;
        return 0;
    }
    int res = 0;
    for(int i = 1; i < N; i++){
        if (N > (1 + i - 1) * (i - 1) / 2.0  && N <= (1 + i) * i / 2.0){
            res = i;
            break;
        }
    }
    int left = N - (1 + res - 1) * (res - 1) / 2.0;
    if ( res % 2 == 0){
        cout<<left<<"/"<<(res + 1 - left)<<endl;
    }
    else {
        cout<<(res + 1 - left)<<"/"<<left<<endl;
    }
    return res;
}

int main(){
/*    string in_str;*/
    //getline(cin, in_str);
    //int N;
    //vector<int > int_vec = splitSpace(in_str, N);
    //N = int_vec[0];
    /*trangle_num(N);*/


    for(int i = 1; i < 20 ; i++){
        cout<<i<<endl;
        trangle_num(i);
        cout<<endl;
    }


}
