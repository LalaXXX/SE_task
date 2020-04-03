#!/usr/bin/python
# -*- coding: UTF-8 -*-
def maxSubArray(nums):
	n = len(nums)
	max_sum = nums[0]
	for i in range(1, n):
		if nums[i - 1] > 0:
			nums[i] += nums[i - 1] 
		max_sum = max(nums[i], max_sum)

	return max_sum

inp = input("请输入一组数据：\n")
nums = [int(n) for n in inp.split()]
print(maxSubArray(nums))