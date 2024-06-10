class Solution:
    def fun(self, another, sum):
        l = 0
        r = len(another) - 1
        ans = len(another)
        while (l <= r) :
            mid = int((l + r) / 2)
            if another[mid] >= sum:
                l = mid + 1
            else:
                ans = mid
                r = mid - 1
        
        return (len(another) - ans)

    def triangleNumber(self, nums: list[int]) -> int:
        another = []
        nums.sort()
        ans = 0
        for i in range(len(nums) - 1, 0, -1):
            for j in range(i - 1, -1, -1):
                sum = nums[i] + nums[j]
                ans = ans + self.fun(another, sum)
            another.append(nums[i])
        
        return ans

nums = [4,2,3,4]
c = Solution()
print(c.triangleNumber(nums))