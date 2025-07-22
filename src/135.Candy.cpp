#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        auto candiesLeft = ::std::vector<int>(ratings.size(), 0);
        for (int i = 0; i < (int) ratings.size(); ++i) {
            if (i != 0 && ratings[i] > ratings[i - 1]) {
                candiesLeft[i] = candiesLeft[i - 1] + 1;
            } else {
                candiesLeft[i] = 1;
            }
        }
        auto candiesRight = ::std::vector<int>(ratings.size(), 0);
        for (int i = ratings.size() - 1; i >= 0; --i) {
            if (i != (int) ratings.size() - 1 && ratings[i] > ratings[i + 1]) {
                candiesRight[i] = candiesRight[i + 1] + 1;
            } else {
                candiesRight[i] = 1;
            }
        }
        int result = 0;
        for (int i = 0; i < (int) ratings.size(); ++i) {
            result = result + ::std::max(candiesLeft[i], candiesRight[i]);
        }
        return result;
    }
};