#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class LeaderboardSystem
{
  public:
    static std::vector<int> GetTopScores(const std::vector<int> &scores, int m)
    {
        if (scores.empty() || m <= 0)
        {
            return {};
        }

        // 复制输入数组
        // std::vector<int> sortedScores =
        //     std::copy(scores.begin(), scores.end(), std::vector<int>());
        std::vector<int> sortedScores(scores);

        // sort 降序
        std::sort(sortedScores.begin(), sortedScores.end(),
                  std::greater<int>());

        // 如果 m 超过了分数的数量，返回尽可能多的分数
        if (m > static_cast<int>(sortedScores.size()))
        {
            m = sortedScores.size();
        }

        // 返回前 m 个最高分
        return std::vector<int>(sortedScores.begin(), sortedScores.begin() + m);
    }
};

// 单元测试
void TestGetTopScores()
{
    // 测试用例1：常规输入
    std::vector<int> scores1 = {100, 50, 75, 80, 65};
    int m1 = 3;
    std::vector<int> result1 = LeaderboardSystem::GetTopScores(scores1, m1);
    assert((result1 == std::vector<int>{100, 80, 75}) && "Test case 1 failed");

    // 测试用例2：m 大于数组长度
    std::vector<int> scores2 = {100, 50, 75};
    int m2 = 5;
    std::vector<int> result2 = LeaderboardSystem::GetTopScores(scores2, m2);
    assert((result2 == std::vector<int>{100, 75, 50}) && "Test case 2 failed");

    // 测试用例3：空数组
    std::vector<int> scores3 = {};
    int m3 = 3;
    std::vector<int> result3 = LeaderboardSystem::GetTopScores(scores3, m3);
    assert((result3 == std::vector<int>{}) && "Test case 3 failed");

    // 测试用例4：m 为 0
    std::vector<int> scores4 = {100, 50, 75};
    int m4 = 0;
    std::vector<int> result4 = LeaderboardSystem::GetTopScores(scores4, m4);
    assert((result4 == std::vector<int>{}) && "Test case 4 failed");

    // 测试用例5：负 m
    std::vector<int> scores5 = {100, 50, 75};
    int m5 = -1;
    std::vector<int> result5 = LeaderboardSystem::GetTopScores(scores5, m5);
    assert((result5 == std::vector<int>{}) && "Test case 5 failed");

    std::cout << "All test cases passed!" << std::endl;
}

int main()
{
    TestGetTopScores();
    return 0;
}
