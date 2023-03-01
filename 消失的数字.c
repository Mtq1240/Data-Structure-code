//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//输入：[3,0,1]
//输出：2
//思路一:
//数组nums包含 0 ~ n 的所有整数,要找出其中缺的那一个数字,我们按将其数组元素进行排序,
//例如: [2 ,3, 1, 4, 5, 7, 6, 9],将其排序之后就会变成[1,2,3,4,5,6,7,9].然后就很简单了,
//要找到消失的数就可以将排序后的元素遍历一遍,看后一个数是不是比前一个数大1,如果不是那就直接找到了.

//代码如下:

int missingNumber(int* nums, int numsSize){
    for(int i = numsSize - 1; i > 0; i--)
    {
        //冒泡排序
        flag = 1;
        for(int j = 0; j < i; j++)
        {
            if(nums[i] > nums[i + 1])
            {
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
                if(flag)
                    flag = 0;
            }
            if(flag)
                break;
        }
    }
    //检查每个元素前后是否相差为1
    for(int z = 0; z < numsSize - 2; z++)
    {
        if(nums[z + 1] - nums[z] != 1)
            return nums[z + 1] - 1;
    }    
    //考虑头尾
    if(nums[0])
    return 0;
    return numsSize;
}

//但是题目要求算法的时间复杂度要求是 O(N) ,如果使用最快的排序只能达到O(N*logN),所以排序并不合适.

//思路二:
//要求 0 ~ n 中缺失的那个,可以将 0 ~ n 的所有元素相加,得到的结果再与原数组里元素的和相减,结果就得到消失的数字.

//代码如下:

int missingNumber(int* nums, int numsSize){
    int misNum = 0;
    for(int j = 0; j < numsSize + 1; j++)
    misNum += j;
    for(int i = 0; i < numsSize; i++)
    misNum -= nums[i];
    return misNum;
}

//异或:将数组中的数依次跟 0 ~ n 的所有数异或,最后剩下的数据就是缺的那个数字(异或:按位异或相同为 0 ,不同为 1 ).
//我们知道相同的数异或到一起就没了,是0. 此题如果把 0 ~ n 的数与原数组里的元素进行异或,然后相同的两个数异或没了,
//那么剩下的就是消失的那个数,(两数组进行异或时不需要有序,因为异或满足交换律,相同的会消失,最后剩下的就是要求的数)
//这个例子我们可以看到虽然数据没有有序,但是相同的两个数被相互消去,得到的是不同的那个数.

int missingNumber(int* nums, int numsSize){
    int x = 0;
    //用for循环求出数组中的异或之和
    for(int i = 0; i < numsSize; i++)
       x ^= nums[i];
    for(int j = 0; j < numsSize + 1; j++)//原数组比0~n少1个数,要+1
    //再和(0~n)之间的数异或
       x ^= j;
    return x;
}
