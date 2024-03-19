#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
// #include <map>
#include <cctype>
#include <cstdlib>
#include <bitset>
#include <unordered_map>
#include <set>
#include <cmath>
#include <queue>
#include <typeinfo>
#include <string.h>
#include <regex>
#include <stack>
#include <numeric>
#include <unordered_set>
// #include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <utility>
#include <math.h>

using namespace std;

long long block[1000000001];

void placeBlock()
{
    for (long long i = 1; i < 1000000001; i++)
    {
        for (long long j = i + i; j < 1000000001; j += i)
        {
            block[j] = i;
        }
    }
}

vector<int> solution(long long begin, long long end)
{
    vector<int> answer;
    placeBlock();
    for (int i = begin; i < end + 1; i++)
    {
        answer.push_back(block[i]);
    }
    return answer;
}

int main()
{
    long long begin = 1;
    long long end = 10;
    vector<int> result = solution(begin, end);
    for (auto i : result)
        cout << i << endl;
}