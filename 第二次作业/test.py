import unittest

class TestClass:
	def maxSubArray(nums):
		n = len(nums)
		max_sum = 0
		for i in range(1, n):
			if nums[i - 1] > 0:
				nums[i] += nums[i - 1] 
			max_sum = max(nums[i], max_sum)

		return max_sum


class TestDemo(unittest.TestCase):
    def setUp(self):
        pass
    def tearDown(self):
        pass
    def test1(self):
        self.assertEqual(TestClass.maxSubArray([-2, 11, -4, 13, -5, -2]), 20, "test 1 fail")
    def test2(self):   
        self.assertEqual(TestClass.maxSubArray([1, 2, 3, 4, 5]), 15, "test 2 fail")
    def test3(self):   
        self.assertEqual(TestClass.maxSubArray([-1, -2, -3, -4, -5]), 0, "test 3 fail")
    def test4(self):   
        self.assertEqual(TestClass.maxSubArray([-3, -1, 0, 5, 99, -150]), 104, "test 4 fail")
   
        
if __name__ == "__main__":
    unittest.main(argv=['first-arg-is-ignored'], exit=False)
