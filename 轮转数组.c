//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//	向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]

 void Reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		++left;
		--right;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	if (k >= numsSize)
	{
		k %= numsSize;
	}

	Reverse(nums, numsSize - k, numsSize - 1);
	Reverse(nums, 0 , numsSize -k - 1);
	Reverse(nums, 0 , numsSize - 1);

}
