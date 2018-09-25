#include <iostream> 
#include <vector> 

using namespace std;



int distanceCovered(int busCount, vector<vector<int> > busStops)
{
    // WRITE YOUR CODE HERE
    int min = busStops[0][0];
    int max = busStops[0][1];
    int count = 0;
    for(int i=1;i<busCount;i++){
        if(max<busStops[i][0]){
            count = count + max - min;
            min = busStops[i][0];
            max = busStops[i][1];
        }
        else if(max>busStops[i][0]){
            max = busStops[i][1];
            //count = count + max - min;
        }
    }
	count += max - min;
    return count;
}


int main(){
	int a;
	vector<vector<int> > aa;
	vector<int > bb(2);
	bb[0] = 2;
	bb[1] = 4;
	aa.push_back(bb);
	bb[0] = 3;
	bb[1] = 5;
	aa.push_back(bb);
	bb[0] = 6;
	bb[1] = 7;
	aa.push_back(bb);
	cout<<distanceCovered(3, aa)<<endl;




}

