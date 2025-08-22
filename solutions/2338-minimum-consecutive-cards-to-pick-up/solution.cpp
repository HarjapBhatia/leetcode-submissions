class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastIndex;
        int len = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            if (lastIndex.find(cards[i]) != lastIndex.end()) {
                len = min(len, i - lastIndex[cards[i]] + 1);
            }
            lastIndex[cards[i]] = i;
        }

        return len == INT_MAX ? -1 : len;
    }
};

