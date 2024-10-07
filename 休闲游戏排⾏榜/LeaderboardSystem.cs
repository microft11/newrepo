using System;
using System.Collections.Generic;
using System.Linq;

public class LeaderboardSystem
{
    public static List<int> GetTopScores(List<int> scores, int m)
    {
        if (scores == null || scores.Count == 0 || m <= 0)
        {
            return new List<int>();
        }

        // 复制和排序分数，降序排序
        List<int> sortedScores = new List<int>(scores);
        sortedScores.Sort((a, b) => b.CompareTo(a));

        // 如果 m 大于分数的数量，则调整 m 的大小
        if (m > sortedScores.Count)
        {
            m = sortedScores.Count;
        }

        // 返回前 m 个最高分
        return sortedScores.Take(m).ToList();
    }
}

public class LeaderboardSystemTests
{
    public static void TestGetTopScores()
    {
        // 测试用例1：常规输入
        List<int> scores1 = new List<int> { 100, 50, 75, 80, 65 };
        int m1 = 3;
        List<int> result1 = LeaderboardSystem.GetTopScores(scores1, m1);
        System.Diagnostics.Debug.Assert(result1.SequenceEqual(new List<int> { 100, 80, 75 }), "Test case 1 failed");

        // 测试用例2：m 大于数组长度
        List<int> scores2 = new List<int> { 100, 50, 75 };
        int m2 = 5;
        List<int> result2 = LeaderboardSystem.GetTopScores(scores2, m2);
        System.Diagnostics.Debug.Assert(result2.SequenceEqual(new List<int> { 100, 75, 50 }), "Test case 2 failed");

        // 测试用例3：空数组
        List<int> scores3 = new List<int>();
        int m3 = 3;
        List<int> result3 = LeaderboardSystem.GetTopScores(scores3, m3);
        System.Diagnostics.Debug.Assert(result3.SequenceEqual(new List<int>()), "Test case 3 failed");

        // 测试用例4：m 为 0
        List<int> scores4 = new List<int> { 100, 50, 75 };
        int m4 = 0;
        List<int> result4 = LeaderboardSystem.GetTopScores(scores4, m4);
        System.Diagnostics.Debug.Assert(result4.SequenceEqual(new List<int>()), "Test case 4 failed");

        // 测试用例5：负 m
        List<int> scores5 = new List<int> { 100, 50, 75 };
        int m5 = -1;
        List<int> result5 = LeaderboardSystem.GetTopScores(scores5, m5);
        System.Diagnostics.Debug.Assert(result5.SequenceEqual(new List<int>()), "Test case 5 failed");

        Console.WriteLine("All test cases passed!");
    }

    public static void Main(string[] args)
    {
        TestGetTopScores();
    }
}
