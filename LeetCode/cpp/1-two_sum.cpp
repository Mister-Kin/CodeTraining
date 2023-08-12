/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 暴力枚举
        // 时间复杂度为 O(n^2)；空间复杂度为 O(1)。
        /*
        for (int i = 0; i < nums.size() - 1; i++) // size-1：第一层遍历无需遍历到最后一个数
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
        */

        // map和unordered_map这两种字典结构都是通过键值对（key-value）存储数据的。
        // unordered_map内部元素是无序的，而map中的元素是按照二叉搜索树存储。
        // unordered_map::count()是C++中的内置方法，用于通过给定key对unordered_map中存在的元素数量进行计数。用法：size_type count(Key);
        // 注意：由于unordered_map不允许存储具有重复键的元素，因此count()函数本质上检查unordered_map中是否存在具有给定键的元素。
        // 定义 int 的 unordered_map 的变量dict（映射到 int）

        // 两遍哈希表，先建表后查找。先建表的话，注意找到的元素要排除自身。
        // 时间复杂度为 O(n)；空间复杂度为 O(n)。
        /*
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++)
            dict.insert({nums[i], i});
        for (int i = 0; i < nums.size(); i++)
            if (dict.count(target - nums[i]) > 0 && (dict[target - nums[i]] != i))
                return {i, dict[target - nums[i]]};
        return {};
        */

        // 一遍哈希表，边查找边建表。
        // 时间复杂度为 O(n)；空间复杂度为 O(n)。
        unordered_map<int, int>
            dict;
        for (int i = 0; i < nums.size(); i++)
        {
            if (dict.count(target - nums[i]))
                return {i, dict[target - nums[i]]};
            dict.insert({nums[i], i}); // 必须要先查找后建表，不然找到的元素没法排除自身
        }
        return {};
    }
};
// @lc code=end
