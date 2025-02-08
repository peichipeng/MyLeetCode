class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indexToNumbers.find(index) != indexToNumbers.end()) {
            int preNum = indexToNumbers[index];
            numberToIndices[preNum].erase(index);
            if (numberToIndices[preNum].empty()) {
                numberToIndices.erase(preNum);
            }
        }
        indexToNumbers[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end()) {
            return *numberToIndices[number].begin();
        }
        return -1;
    }

private:
    // Map from number to set of indices
    unordered_map<int, set<int>> numberToIndices;
    // Map from index to number
    unordered_map<int, int> indexToNumbers;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */