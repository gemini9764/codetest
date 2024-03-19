#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
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

using namespace std;

int outdegree[1234567] = {0};
int indegree[1234567] = {0};
int vis[1234567] = {0};

vector<int> g[1234567]; // 인접리스트
vector<int> ans(4);

void dfs(int now)
{
    if (vis[now])
    {
        ans[1]++;
        return;
    }
    if (outdegree[now] == 2)
    {
        ans[3]++;
        return;
    }
    if (indegree[now] == 0)
    {
        ans[2]++;
        return;
    }

    vis[now] = 1;

    for (auto next : g[now])
    {
        dfs(next);
    }
}

vector<int> solution(vector<vector<int>> edges)
{
    for (auto edge : edges)
    {
        outdegree[edge[0]]++;
        indegree[edge[1]]++;

        g[edge[0]].push_back(edge[1]);
    }

    for (int i = 1; i <= 1000000; i++)
    {
        if (indegree[i] == 0 && outdegree[i] >= 2)
        { // 핵심 정점을 찾음
            ans[0] = i;
            break;
        }
    }

    for (auto child : g[ans[0]])
    {
        dfs(child);
    }

    return ans;
}

int main()
{
    vector<vector<int>> edges1 = {{2, 3}, {4, 3}, {1, 1}, {2, 1}};
    vector<vector<int>> edges2 = {{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}};

    vector<int> result1 = solution(edges1);
    vector<int> result2 = solution(edges2);

    cout << "result1 : {";
    for (auto i : result1)
    {
        cout << i << " ";
    }
    cout << "}" << endl;

    cout << "result2 : {";
    for (auto i : result2)
    {
        cout << i << " ";
    }
    cout << "}" << endl;
}