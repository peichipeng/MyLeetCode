class Solution {
private:
    bool isValid(string pString) {
        int leftCount = 0;
        for (char p : pString) {
            if (p == '(') {
                leftCount++;
            } else {
                leftCount--;
            }
            if (leftCount < 0) return false;
        }
        return leftCount == 0;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        queue<string> queue;
        queue.push("");
        while (!queue.empty()) {
            string curString = queue.front();
            queue.pop();
            if (curString.size() == 2 * n) {
                if (isValid(curString)) {
                    answer.push_back(curString);
                }
                continue;
            }
            queue.push(curString + ")");
            queue.push(curString + "(");
        }
        return answer;
    }
};