class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        std::unordered_set<char> jewelsSet(jewels.begin(), jewels.end());
        int count = 0;

        for (char stone : stones) {
            if (jewelsSet.find(stone) != jewelsSet.end()) {
                count++;
            }
        }

        return count;
    }

};
