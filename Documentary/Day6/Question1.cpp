//Pair Sum Closest to 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> closestPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int closestSum = INT_MAX;
    pair<int, int> result;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (abs(sum) < abs(closestSum)) {
            closestSum = sum;
            result = {nums[left], nums[right]};
        }
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-8, -3, 1, 2, 4, 10};
    pair<int, int> result = closestPairSum(nums);
    cout << "Pair with sum closest to 0: (" << result.first << ", " << result.second << ")" << endl;
    return 0;
}
