#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static bool cmp(std::vector<int> a, std::vector<int> b) {
        if (a[0] < b[0]) {
            return true;
        }
        else if (a[0] > b[0]) {
            return false;
        }
        return (a[0] - a[1] < b[0] - b[1]);
    }

    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        // Sort the intervals based on the start points and differences
        std::sort(intervals.begin(), intervals.end(), cmp);
        
        int mi = 0;  // Initialize the minimum interval start
        int mx = 0;  // Initialize the maximum interval end
        int rem = 0; // Initialize a variable to count removed intervals
        int n = intervals.size(); // Get the total number of intervals
        
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] >= mi && mx >= intervals[i][1]) {
                // The current interval is covered by a previous interval, so remove it
                rem++;
            }
            else {
                // Update the minimum and maximum based on the current interval
                mi = std::min(mi, intervals[i][0]);
                mx = std::max(mx, intervals[i][1]);
            }
        }
        
        // Return the number of remaining intervals
        return n - rem;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    int result = solution.removeCoveredIntervals(intervals);
    
    std::cout << "Number of remaining intervals: " << result << std::endl;
    
    return 0;
}
