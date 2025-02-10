class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int countT = 0, countF = 0;
        int left = 0;
        int maxSize = 0;
        for (int right = 0; right < answerKey.size(); right++) {
            if (answerKey[right] == 'T') countT++;
            else countF++;

            while (min(countT, countF) > k) {
                if (answerKey[left] == 'T') countT--;
                else countF--;
                left++;
            }
            maxSize = max(right - left + 1, maxSize);
        }
        return maxSize;
    }
};