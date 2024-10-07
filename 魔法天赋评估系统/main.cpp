#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>


class TalentEvaluationSystem
{
  public:
    static double FindMedianTalentIndex(const std::vector<int> &fireAbility,
                                        const std::vector<int> &iceAbility)
    {
        int m = fireAbility.size();
        int n = iceAbility.size();

        // 确保 fireAbility 是较短的数组，以便我们对其进行二分查找
        if (m > n)
        {
            return FindMedianTalentIndex(iceAbility, fireAbility);
        }

        int low = 0, high = m;
        int totalLeft = (m + n + 1) / 2;

        while (low <= high)
        {
            int partitionA = (low + high) / 2;
            int partitionB = totalLeft - partitionA;

            int maxLeftA =
                (partitionA == 0) ? INT_MIN : fireAbility[partitionA - 1];
            int minRightA =
                (partitionA == m) ? INT_MAX : fireAbility[partitionA];

            int maxLeftB =
                (partitionB == 0) ? INT_MIN : iceAbility[partitionB - 1];
            int minRightB =
                (partitionB == n) ? INT_MAX : iceAbility[partitionB];

            // 判断划分是否合理
            if (maxLeftA <= minRightB && maxLeftB <= minRightA)
            {
                if ((m + n) % 2 == 0)
                {
                    return (std::max(maxLeftA, maxLeftB) +
                            std::min(minRightA, minRightB)) /
                           2.0;
                }
                else
                {
                    return std::max(maxLeftA, maxLeftB);
                }
            }
            else if (maxLeftA > minRightB)
            {
                high = partitionA - 1;
            }
            else
            {
                low = partitionA + 1;
            }
        }

        throw std::invalid_argument(
            "Input arrays are not sorted or have incorrect sizes.");
    }
};

// 单元测试
void TestFindMedianTalentIndex()
{
    // 测试用例 1
    std::vector<int> fireAbility1 = {1, 3, 8};
    std::vector<int> iceAbility1 = {7, 9, 10, 11};
    std::cout << (TalentEvaluationSystem::FindMedianTalentIndex(
                      fireAbility1, iceAbility1) == 8.0
                      ? "Test 1 Passed"
                      : "Test 1 Failed")
              << std::endl;

    // 测试用例 2
    std::vector<int> fireAbility2 = {1, 2};
    std::vector<int> iceAbility2 = {3, 4};
    std::cout << (TalentEvaluationSystem::FindMedianTalentIndex(
                      fireAbility2, iceAbility2) == 2.5
                      ? "Test 2 Passed"
                      : "Test 2 Failed")
              << std::endl;

    // 测试用例 3
    std::vector<int> fireAbility3 = {0, 0};
    std::vector<int> iceAbility3 = {0, 0};
    std::cout << (TalentEvaluationSystem::FindMedianTalentIndex(
                      fireAbility3, iceAbility3) == 0.0
                      ? "Test 3 Passed"
                      : "Test 3 Failed")
              << std::endl;

    // 测试用例 4
    std::vector<int> fireAbility4 = {1, 2, 3, 4};
    std::vector<int> iceAbility4 = {5, 6, 7, 8};
    std::cout << (TalentEvaluationSystem::FindMedianTalentIndex(
                      fireAbility4, iceAbility4) == 4.5
                      ? "Test 4 Passed"
                      : "Test 4 Failed")
              << std::endl;
}

int main()
{
    TestFindMedianTalentIndex();
    return 0;
}
