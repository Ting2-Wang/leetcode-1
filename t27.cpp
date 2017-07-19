# include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int cnt = 0;
        if (nums.size() == 0) return cnt;
        for (int i = 0; i < nums.size() - cnt; i++) {
            if (nums[i] == val) {
                for (int k = i + 1; k < nums.size() - cnt; k++) {
                    nums[k - 1] = nums[k];
                }
                cnt++;
                i--;
            }
        }
        return nums.size() - cnt;
    }
};

int main27() {
    Solution s;
    vector<int> v;
//    v.push_back(3);
//    v.push_back(2);
//    v.push_back(2);
//    v.push_back(3);
    v.push_back(1);
    s.removeElement(v, 1);
//    s.removeElement(v, 3);
    return 0;
}