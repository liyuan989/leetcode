/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include <algorithm>
#include <vector>

using namespace std;

// Definition for an interval.
struct Interval
{
    int  start;
    int  end;

    Interval()
        : start(0), end(0)
    {
    }

    Interval(int s, int e)
        : start(s), end(e)
    {
    }
};


class Solution
{
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        if (intervals.empty())
        {
            return result;
        }
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)
            {
                return a.start == b.start ? a.end < b.end : a.start < b.start;
            });
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (!result.empty() && result.back().end >= intervals[i].start)
            {
                if (result.back().end < intervals[i].end)
                {
                    result.back().end = intervals[i].end;
                }
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<Interval> v =
    {
        {74,78},{61,63},{46,50},{51,54},{50,50},{60,64},{39,42},{25,27},{91,95},{14,16},
        {85,85},{5,7},{45,46},{45,49},{66,66},{73,73},{25,26},
    };
    Solution s;
    vector<Interval>&& result = s.merge(v);
    for (auto i : result)
    {
        printf("[%d,%d] ", i.start, i.end);
    }
    printf("\n");
    return 0;
}
