#include <iostream> 
#include <string> 
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

class Solution {
    public:
        int sellDay1;
        int buyDay1;
        int maxProfit(std::vector<int> &prices)
        {
            // Profit aa = CaculateProfit(prices, 0, FIRST);
            // cout<<aa.profit<<" "<<aa.buyDay<<" "<<aa.sellDay<<endl;
            // return 0;
            return CaculateProfit(prices, 0, FIRST).profit;
        }
        
    private:
        struct Profit
        {
            Profit() : profit(0), buyPrice(-1), buyDay(0), sellDay(0)
            {
            }
            
            int profit;
            int buyPrice;
            int buyDay;
            int sellDay;
        };
        
        enum Transaction
        {
            FIRST,
            SECOND
        };
        
        Profit CaculateProfit(std::vector<int> &prices, int start, Transaction transaction )
        {
            Profit currentProfit;
            Profit maxProfit;
            Profit secondProfit;
            Profit totalProfit;
            
            for(int day = start; day < prices.size(); ++day)
            {
                if(currentProfit.buyPrice == -1)
                {
                    currentProfit.buyPrice = prices[day];
                    currentProfit.buyDay = day;
                    buyDay1 = day;
                    continue;
                }
                
                currentProfit.profit = prices[day] - currentProfit.buyPrice;
                currentProfit.sellDay = day;
                sellDay1 = day;
                
                if(currentProfit.profit < 0)
                {
                    currentProfit.buyPrice = prices[day];
                    currentProfit.buyDay = day;
                    buyDay1 = day;
                    currentProfit.profit = 0;
                }
                
                if(currentProfit.profit > maxProfit.profit)
                {
                    if(transaction == FIRST)
                    {
                        secondProfit = CaculateProfit(prices, day + 1, SECOND);
                        
                        
                        if(currentProfit.profit + secondProfit.profit > totalProfit.profit)
                        {
                            totalProfit.profit = currentProfit.profit + secondProfit.profit;
                        }
                    }

                    maxProfit = currentProfit;
                }
            }
            
            if(transaction == FIRST)
            {
                return totalProfit;
            }
            else
            {
                return maxProfit;
            }
        }
    };

int main(){
    string tempStr;
    getline(cin, tempStr);
    int intType;

    vector<int > aa = splitSpace(tempStr, intType);
    Solution a;
    a.maxProfit(aa);
    cout<<a.maxProfit(aa)<<" "<<a.buyDay1<<" "<<a.sellDay1<<endl;
}

