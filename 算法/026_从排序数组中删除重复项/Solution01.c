﻿/*
https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/21/
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
给定一个[排序数组]，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成.
示例 1:
给定数组 nums = [1,1,2], 
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。
说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/


/*
基本思想:
把数组分为两个部分:
第一部分:已经没有重复项的部分(由num[0]开始)
第二部分:可能还有重复性的部分
逐一"消灭"第二部分的元素.
"挤压队列"
*/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int  len            = 0;
    int  inner_count    = 0;
    int  i              = 0;
    do{
        /* 输入参数检查,能直接处理的直接处理*/
        if(  (nums == NULL)
        ||(numsSize <= 0)
        )
        {
            len = 0;
            break;
        }
        if(numsSize==1)
        {
            len = 1;
            break;
        }

        len           = 1;/* 已经保证数组长度至少为2,len既是长度计数,也指向未进入无重复项区域的元素 */
        inner_count   = 1;/* 标记已经处理过的原始数组的数据个数                                     */
        while(1)
        {
            if(nums[len-1]==nums[len]) /* 本来要遍历0~len-1,但已经确认是"排序数组",只需要比较前一个就可用了*/
            {
                
                // 已经索引到原始数组的 已经处理掉count个,覆盖一个相当于尾巴去掉一个,所以 i = [0,numsSize - inner_count - 1)
                for( i = 0; i < numsSize - inner_count - 1 ; i++ )    /*挪动可能还有重复数的部分,使得(nums+len)指向下一个要判断的元素*/
                {
                    nums[len+i] = nums[len+i+1];    
                }
            }
            else
            {
                len++;  /* 纳入已经没有重复项的部分 */
            }
                
            inner_count++;  /* */
            if(inner_count > numsSize - 1)
            {
                break;
            }
        };
        
        break;
    }while(0);
    return len;
}






int main(void)
{
    int nums[5] = {112,112,113,114,115};
    
    int len = removeDuplicates(nums,4);
    
    
    for(int i = 0;i<5;i++)
    {
        printf("%d\n",nums[i]);
    }
    return 0;
}







/*
161 / 161 个通过测试用例
状态：通过
执行用时 : 504 ms, 在Remove Duplicates from Sorted Array的C提交中击败了9.31% 的用户
内存消耗 : 9.8 MB, 在Remove Duplicates from Sorted Array的C提交中击败了74.91% 的用户
执行耗时爆表了.
*/
