#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircleQueue.h"

#define	CUS_COME_TERM	15		

#define CHE_BUR		0		
#define BUL_BUR		1		
#define DUB_BUR		2		

#define CHE_TERM	12		
#define BUL_TERM	15		
#define DUB_TERM	24		

int main(void)
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que;
	int repeat;
	counterr(&que);
	srand((unsigned int)time(NULL));
	int error = ErrorOut(&que);

	for (repeat = 1; repeat < 101; repeat++) {
		QueueInit(&que);
		error = ErrorOut(&que);
		makeProc = 0, cheOrder = 0, bulOrder = 0, dubOrder = 0;
		for (sec = 0; sec < 3600; sec++)
		{
			if (sec % CUS_COME_TERM == 0)
			{
				switch (rand() % 3)
				{
				case CHE_BUR:
					Enqueue(&que, CHE_TERM);
					cheOrder += 1;
					break;

				case BUL_BUR:
					Enqueue(&que, BUL_TERM);
					bulOrder += 1;
					break;

				case DUB_BUR:
					Enqueue(&que, DUB_TERM);
					dubOrder += 1;
					break;
				}
			}
			if (error < ErrorOut(&que)) {
				printf("인원초과! 시뮬레이션 차수 %d, 현재 초과횟수 %d번, 판매량을 조회한 뒤 다시 시뮬레이션합니다. \n", repeat, error);
				printf("치즈 - %d 개, 불고기 - %d 개, 더블 - %d 개 입니다. \n", cheOrder, bulOrder, dubOrder);
				break;
			}
			if (sec == 3599) {
				printf("시뮬레이션 차수 %d, 인원수용 완료, 판매량 조회후 다시 시뮬레이션 합니다.\n", repeat);
				printf("치즈 - %d 개, 불고기 - %d 개, 더블 - %d 개 입니다. \n", cheOrder, bulOrder, dubOrder);
			}
			if (makeProc <= 0 && !QIsEmpty(&que))
				makeProc = Dequeue(&que);
			makeProc--;

		}
	}
	printf("수용인원 %d명, 시뮬레이션 횟수 : %d, 인원초과 횟수 %d, 인원수용 가능성 %.2f%%입니다.", QUE_LEN, repeat - 1, error, ((double)repeat - 1 - (double)error) / ((double)repeat - 1) * 100);
	return 0;
}
