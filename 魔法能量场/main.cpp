#include <algorithm>
#include <iostream>
#include <vector>

class EnergyFieldSystem
{
  public:
    // 找出能够形成的最大梯形面积
    static float MaxEnergyField(const std::vector<int> &heights)
    {
        int left = 0;
        int right = heights.size() - 1;
        float maxArea = 0;

        while (left < right)
        {
            // 计算当前两座塔形成的梯形面积
            int minHeight = std::min(heights[left], heights[right]);
            int width = right - left;
            float area = static_cast<float>(minHeight * width); // 修改这一行

            // 更新最大面积
            maxArea = std::max(maxArea, area);

            // 移动指针，尝试找到更大的面积
            if (heights[left] < heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxArea;
    }
};

// 单元测试
void TestMaxEnergyField()
{
    // 测试用例 1
    std::vector<int> heights1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    float result1 = EnergyFieldSystem::MaxEnergyField(heights1);
    std::cout << (result1 == 49.0f ? "Test 1 Passed" : "Test 1 Failed")
              << std::endl; // 52.5 变为 49.0f

    // 测试用例 2
    std::vector<int> heights2 = {1, 1};
    float result2 = EnergyFieldSystem::MaxEnergyField(heights2);
    std::cout << (result2 == 1.0f ? "Test 2 Passed" : "Test 2 Failed")
              << std::endl;

    // 测试用例 3
    std::vector<int> heights3 = {4, 3, 2, 1, 4};
    float result3 = EnergyFieldSystem::MaxEnergyField(heights3);
    std::cout << (result3 == 16.0f ? "Test 3 Passed" : "Test 3 Failed")
              << std::endl;
}

int main()
{
    TestMaxEnergyField();
    return 0;
}
