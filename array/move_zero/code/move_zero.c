#include <stdio.h>
		
void moveZeroes(int* nums, int numsSize)
{
	int temp;

	for (int i = 0; i < numsSize-1; i++) {/* 遍历数组元素 */
		if (nums[i] == 0) {/* 如果当前元素为零 */
			int j = i + 1;
			while (j < numsSize) {
				if (nums[j] != 0) {/* 从当前元素后面寻找第一个不为零的元素 */
					temp = nums[i];/* 找到后交换当前元素和第一个不为零元素的顺序 */
					nums[i] = nums[j];
					nums[j] = temp;
					break;/* 交换完成后，本轮循环结束，回到for继续下一个数组元素 */
				}
				j++;
			}
		}
	}
}

int main(void)
{
	int arry[] = {0,1,0,3,12};
	int arry_size = 5;

	moveZeroes(arry, arry_size)	;

	for (int i = 0; i < arry_size; i++) {
		printf("%d\n", arry[i]);
	}

	return 0;
}
