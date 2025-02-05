class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int result;
        int wCount = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') wCount++;
        }
        result = wCount;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') wCount++;
            if (blocks[i - k] == 'W') wCount--;
            result = min(wCount, result);
        }
        return result;
    }
};