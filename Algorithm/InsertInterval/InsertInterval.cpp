/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include <vector>
#include <stdio.h>

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
    vector<Interval> insert(vector<Interval>& intervals, const Interval& new_interval)
    {
        vector<Interval> result;
        result.reserve(intervals.size() + 1);
        int index = 0;
        while (index < intervals.size() && compare(intervals[index], new_interval))
        {
            result.push_back(intervals[index]);
            ++index;
        }
        if (result.empty())
        {
            result.push_back(new_interval);
        }
        else if (new_interval.start <= result.back().end && result.back().end < new_interval.end)
        {
            result.back().end = new_interval.end;
        }
        else if (result.back().end < new_interval.start)
        {
            result.push_back(new_interval);
        }
        while (index < intervals.size())
        {
            if (intervals[index].start <= result.back().end && result.back().end < intervals[index].end)
            {
                result.back().end = intervals[index].end;
                ++index;
            }
            else if (result.back().end >= intervals[index].end)
            {
                ++index;
            }
            else
            {
                result.push_back(intervals[index]);
            }
        }
        return result;
    }

    bool compare(const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    }
};

int main(int argc, char* argv[])
{
    vector<Interval> array = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    Solution s;
    vector<Interval>&& result = s.insert(array, Interval(4, 9));
    for (auto i : result)
    {
        printf("[%d,%d] ", i.start, i.end);
    }
    printf("\n");
    return 0;
}
