
class Solution {
    struct Node {
        int child[2] = {-1, -1};
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        vector<Node> trie;
        trie.reserve(nums.size() * 31 + 1);
        trie.emplace_back();

        for (int num : nums) {
            int node = 0;

            for (int i = 30; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (trie[node].child[bit] == -1) {
                    trie[node].child[bit] = trie.size();
                    trie.emplace_back();
                }

                node = trie[node].child[bit];
            }
        }

        int ans = 0;

        for (int num : nums) {
            int node = 0;
            int curXor = 0;

            for (int i = 30; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int opposite = bit ^ 1;

                if (trie[node].child[opposite] != -1) {
                    curXor |= (1 << i);
                    node = trie[node].child[opposite];
                } else {
                    node = trie[node].child[bit];
                }
            }

            ans = max(ans, curXor);
        }

        return ans;
    }
};
