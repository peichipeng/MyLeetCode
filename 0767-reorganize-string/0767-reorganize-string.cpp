class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCounts(26, 0);
        for (char c : s) {
            charCounts[c - 'a']++;
        }

        // Max heap ordered by character counts
        // Elements are sorted in descending order based on the first element
        priority_queue<vector<int>> pq;
        for (int i = 0; i < charCounts.size(); i++) {
            if (charCounts[i] > 0) {
                // Not to use (), as parentheses calls a constructor of vector<int>
                pq.push(vector<int>{charCounts[i], i + 'a'});
            }
        }

        string result;
        while (!pq.empty()) {
            // first will be of type vector<int>
            auto first = pq.top();
            pq.pop();
            if (result.empty() || first[1] != result.back()) {
                result += char(first[1]);
                // Decrements first[0] by 1 before evaluating the condition
                if (--first[0] > 0) {
                    pq.push(first);
                }
            } else {
                if (pq.empty()) {
                    return "";
                }
                auto second = pq.top();
                pq.pop();
                result += char(second[1]);
                if (--second[0] > 0) {
                    pq.push(second);
                }
                pq.push(first);
            }
        }
        return result;
    }
};