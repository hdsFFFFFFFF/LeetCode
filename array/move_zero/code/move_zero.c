#include <stdio.h>
		
void moveZeroes(int* nums, int numsSize)
{
	int temp;

	for (int i = 0; i < numsSize-1; i++) {/* ��������Ԫ�� */
		if (nums[i] == 0) {/* �����ǰԪ��Ϊ�� */
			int j = i + 1;
			while (j < numsSize) {
				if (nums[j] != 0) {/* �ӵ�ǰԪ�غ���Ѱ�ҵ�һ����Ϊ���Ԫ�� */
					temp = nums[i];/* �ҵ��󽻻���ǰԪ�غ͵�һ����Ϊ��Ԫ�ص�˳�� */
					nums[i] = nums[j];
					nums[j] = temp;
					break;/* ������ɺ󣬱���ѭ���������ص�for������һ������Ԫ�� */
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
