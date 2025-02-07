class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int points = 0;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }
        if (sum > upper) points++;
        else if (sum < lower) points--;
        for (int i = k; i < calories.size(); i++) {
            sum += calories[i] - calories[i - k];
            if (sum > upper) points++;
            else if (sum < lower) points--;
        }
        return points;
    }
};