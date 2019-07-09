#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/maximize-distance-to-closest-person/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        if (seats.size() <= 2) return 1;
        int i = 0;
        while (i < seats.size() && seats[i] == 0)
            ++i;
        int maxd = i;
        int last1i = i;
        // stopped at 1
        ++i;
        for (; i < seats.size(); ++i) {
            if (seats[i] == 0) {
                int dist = (i - last1i + 1) / 2;
                if (dist > maxd) {
                    maxd = dist;
                }
            } else {
                last1i = i;
            }
        }
        if (seats.size() - 1 - last1i > maxd)
            return seats.size() - 1 - last1i;
        return maxd;
    }
};

void test1() {
    vector<int> v1{1, 0, 0, 0, 1, 0, 1};

    cout << "2 ? " << Solution().maxDistToClosest(v1) << endl;

    vector<int> v2{0, 0, 0, 0, 0, 1};

    cout << "5 ? " << Solution().maxDistToClosest(v2) << endl;

    vector<int> v3{1, 1, 0, 0, 0, 0};

    cout << "4 ? " << Solution().maxDistToClosest(v3) << endl;

    vector<int> v4{1,1,0,0,1,0,0,1};

    cout << "1 ? " << Solution().maxDistToClosest(v4) << endl;

    vector<int> v5{1,1,0,0,1,0,0,0,1};

    cout << "2 ? " << Solution().maxDistToClosest(v5) << endl;

    vector<int> v6{1,0, 1};

    cout << "1 ? " << Solution().maxDistToClosest(v6) << endl;
}

void test2() {

}

void test3() {

}