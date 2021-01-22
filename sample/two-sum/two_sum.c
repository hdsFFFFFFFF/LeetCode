#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	for (int i = 0; i < numsSize; i++) {
        	int flag = 0;
                
		for (int j = i + 1; j < numsSize; j++) {
        		if (target == nums[i] + nums[j]) {
                                returnSize[0] = i;
                                returnSize[1] = j;
                                int flag = 1; 
                                
				break;
                        }
                }
                
		if (flag)
                	break;
        }

        return returnSize;
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int numsSize = 8;
	int target = 9;
	int returnSize[2] = {0};
	
	twoSum(nums, numsSize, target, returnSize);
	
	printf("returnSize[0]:%d\n", returnSize[0]);
	printf("returnSize[1]:%d\n", returnSize[1]);

	return 0;		
} 
