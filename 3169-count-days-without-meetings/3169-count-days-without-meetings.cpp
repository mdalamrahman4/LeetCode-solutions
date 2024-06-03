class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;
        sort(meetings.begin(), meetings.end());
        vector<pair<int, int>> mergedMeetings;
        mergedMeetings.push_back({meetings[0][0], meetings[0][1]});
        
        for (int i = 1; i < meetings.size(); i++) {
            int lastEnd = mergedMeetings.back().second;
            if (meetings[i][0] <= lastEnd) {
                mergedMeetings.back().second = max(lastEnd, meetings[i][1]);
            } else {
                mergedMeetings.push_back({meetings[i][0], meetings[i][1]});
            }
        }
        
        int availableDays = mergedMeetings[0].first - 1;
        for (int i = 1; i < mergedMeetings.size(); i++) {
            availableDays += (mergedMeetings[i].first - mergedMeetings[i-1].second - 1);
        }
        availableDays += (days - mergedMeetings.back().second);
        
        return availableDays;
    }
};
