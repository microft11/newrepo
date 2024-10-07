#include <algorithm>
#include <iostream>
#include <vector>

class TreasureChestSystem
{
  public:
    static int MaxTreasureValue(const std::vector<int> &treasures)
    {
        int n = treasures.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return treasures[0];

        std::vector<int> dp(n, 0);
        dp[0] = treasures[0];
        dp[1] = std::max(treasures[0], treasures[1]);

        // 状态转移
        for (int i = 2; i < n; ++i)
        {
            dp[i] = std::max(dp[i - 1], treasures[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};

// 单元测试
void TestMaxTreasureValue()
{
    // 测试用例 1
    std::vector<int> treasures1 = {1, 2, 3, 1};
    int result1 = TreasureChestSystem::MaxTreasureValue(treasures1);
    std::cout << (result1 == 4 ? "Test 1 Passed" : "Test 1 Failed")
              << std::endl;

    // 测试用例 2
    std::vector<int> treasures2 = {2, 7, 9, 3, 1};
    int result2 = TreasureChestSystem::MaxTreasureValue(treasures2);
    std::cout << (result2 == 12 ? "Test 2 Passed" : "Test 2 Failed")
              << std::endl;

    // 测试用例 3
    std::vector<int> treasures3 = {2, 1, 1, 2};
    int result3 = TreasureChestSystem::MaxTreasureValue(treasures3);
    std::cout << (result3 == 4 ? "Test 3 Passed" : "Test 3 Failed")
              << std::endl;

    // 测试用例 4
    std::vector<int> treasures4 = {5, 3, 4, 11, 2};
    int result4 = TreasureChestSystem::MaxTreasureValue(treasures4);
    std::cout << (result4 == 16 ? "Test 4 Passed" : "Test 4 Failed")
              << std::endl;

    // 测试用例 5
    std::vector<int> treasures5 = {1, 2, 3};
    int result5 = TreasureChestSystem::MaxTreasureValue(treasures5);
    std::cout << (result5 == 4 ? "Test 5 Passed" : "Test 5 Failed")
              << std::endl;
}

int main()
{
    TestMaxTreasureValue();
    return 0;
}
