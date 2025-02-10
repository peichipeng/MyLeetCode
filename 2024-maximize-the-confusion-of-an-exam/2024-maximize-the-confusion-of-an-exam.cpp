class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxLength = 0;
        int start = 0;
        int change = 0;
        for (int end = 0; end < answerKey.size(); end++) {
            change += answerKey[end] == 'F';
            while (change > k) {
                change -= answerKey[start] == 'F';
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        start = 0, change = 0;
        for (int end = 0; end < answerKey.size(); end++) {
            change += answerKey[end] == 'T';
            while (change > k) {
                change -= answerKey[start] == 'T';
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};