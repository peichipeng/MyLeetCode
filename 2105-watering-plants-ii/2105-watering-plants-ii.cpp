class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int left = 0, right = plants.size() - 1;
        int count = 0;
        int canA = capacityA;
        int canB = capacityB;
        while (left <= right) {
            if (left == right) {
                count += (max(canA, canB) >= plants[left]) ? 0 : 1;
            } else {
                if (canA < plants[left]) {
                    canA = capacityA - plants[left];
                    count++;
                } else {
                    canA -= plants[left];
                }
                if (canB < plants[right]) {
                    canB = capacityB - plants[right];
                    count++;
                } else {
                    canB -= plants[right];
                }
            }
            left++;
            right--;
        }
        return count;
    }
};