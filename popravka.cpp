#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

float map(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int inRange(int points, int min, int max)
{
	if((points > max) || (points < min)) return FALSE;
	else return TRUE;
}

float getMark(int points)
{
	float mark = 0;

	if(inRange(points,0,16) == TRUE)
	{
		// 0-16=2
		mark = 2.0;
	}
	else if(inRange(points,17,20) == TRUE)
	{
		// 17-20=3
		mark = map(points,17,20,3,3.499);
	}
	else if(inRange(points,21,24) == TRUE)
	{
		// 21-24=4
		mark = map(points,21,24,3.5,4.499);
	}
	else if(inRange(points,25,28) == TRUE)
	{
		// 25-28=5
		mark = map(points,25,28,4.5,5.499);
	}
	else if(inRange(points,29,32) == TRUE)
	{
		// 29-32=6
		mark = map(points,29,32,5.5,6.0);
	}
	else
	{
		mark = -1;
		printf("Deeba ima nekva gre6ka ???\n");
	}

	return mark;
}

int main(int argc, char const *argv[])
{
	int points = atoi(argv[1]);
	
	if(points == 0)
	{
		for (int i = 0; i <= 32; i++)
		{
			printf("%d points = mark %f\n", i, getMark(i));
		}
	}
	else
	{
		printf("%d points = mark %f\n", points, getMark(points));
	}
	
	return 0;
}