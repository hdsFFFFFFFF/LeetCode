#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
		int *vector = (int *)calloc(2, sizeof(int));
		if (!vector) {
			*returnSize = 0;
			return NULL;
		}

		for (int i = 0; i < numsSize; i++) {                
			for (int j = i + 1; j < numsSize; j++) {
                        	if (target == nums[i] + nums[j]) {
                                	vector[0] = i;
                                	vector[1] = j;
                                	*returnSize = 2;
                    			return vector;
                        }
                }
        }
        
    	return NULL;    
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5, 6};
	int numsSize = 6;
	int target = 11;
	int returnSize;
	int *p;
	
	p = twoSum(nums, numsSize, target, &returnSize);
	
	for (int i = 0; i < returnSize; i++) {
		if (i == 0)
			printf("[");
		
		printf("%d", p[i]);
		
		if (i != returnSize - 1)
			printf(",");		
		
		if (i == returnSize - 1)
			printf("]");
	}
	
	return 0;		
} 
