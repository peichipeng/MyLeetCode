class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> totalPrefix(n);
        vector<int> leftPrefix(n);
        int totalCustomers = 0;
        int customersLeft = 0;
        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i];
            totalPrefix[i] = totalCustomers;
            if (grumpy[i] == 0) {
                customersLeft += customers[i];
            }
            leftPrefix[i] = customersLeft;
        }

        if (minutes == n) return totalCustomers;
        int maxCustomers = totalPrefix[minutes - 1] + leftPrefix[n - 1] - leftPrefix[minutes - 1];
        for (int i = minutes; i < n - 1; i++) {
            int currWindow = totalPrefix[i] - totalPrefix[i - minutes] + leftPrefix[i - minutes] + leftPrefix[n - 1] - leftPrefix[i];
            maxCustomers = max(currWindow, maxCustomers);
        }
        int currWindow = totalPrefix[n - 1] - totalPrefix[n - 1 - minutes] + leftPrefix[n - 1 - minutes];
        return max(maxCustomers, currWindow);
    }
};