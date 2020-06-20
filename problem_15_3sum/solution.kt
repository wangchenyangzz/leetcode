/**
* 排序 + hashmap
**/
class Solution1 {
    fun threeSum(nums: IntArray): List<List<Int>> {
        if (nums.size < 3) return emptyList()
        nums.sort()
        val list = arrayListOf<List<Int>>()
        val map = hashMapOf<Int, Int>()
        for (i in nums.indices) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue
            val nums_1 = -nums[i]
            for (j in i + 1 until nums.size) {
                val value = nums_1 - nums[j]
                if (map.containsKey(value)) {
                    list.add(listOf(nums[i], value, map[value] ?: 0))
                }
                map[nums[j]] = value
            }
            map.clear()
        }
        return list;
    }
}

/**
* 排序 + 双指针
**/
class Solution2 {
    fun threeSum(nums: IntArray): List<List<Int>> {
        if (nums.size < 3) return emptyList()
        nums.sort()
        var m: Int
        var n: Int
        val list = arrayListOf<List<Int>>()
        for (i in 0 until nums.size - 2) {
            if (i > 0 && nums[i] == nums[i - 1]) continue
            m = i + 1
            n = nums.size - 1
            while (m < n) {
                when {
                    nums[m] + nums[n] < -nums[i] -> m++
                    nums[m] + nums[n] > -nums[i] -> n--
                    else -> {
                        list.add(listOf(nums[i], nums[m], nums[n]))
                        while (nums[n] == nums[n - 1] && m < n) {
                            n--
                        }
                        while (nums[m] == nums[m + 1] && m < n) {
                            m++
                        }
                        n--
                        m++
                    }
                }
            }
        }
        return list
    }
}
