// var.24 Chirkov Спросить о алгоритме Манагера

#include <iostream>
#include <stdio.h>
#include<math.h>

using namespace std;

void main()
{
	int  a [] = {1,1,1,4,5,6,7,8,9,10,11,12,13};
	int beg=0, en=0, l1 = 0,l2=0,cn =0 ;
	
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		if (i != 0 && i != (sizeof(a) / 4) - 1)// Проверяем на 1 и последний элемент
		{
			if ((i + 1 <= (sizeof(a) / 4) - 1 && i - 1 >= 0)) 
			{
				if (a[i + 1] == a[i - 1])//НЕчётный полиндром
				{
					l1 += 2;
					cn = 0;
				}
				else if (a[i - 1] == a[i] && (i + 1<= (sizeof(a) / 4) - 1 && i - 2 >= 0))// Чётный полиндром
				{
					if ((a[i + j] == a[i - j - 1]))
					{
						l1 += 2;
						cn = 2;
					}
				}
				else if ((a[i + 1] == a[i]) && (i + 2 <= (sizeof(a) / 4) - 1 && i - j >= 0))
				{
					if ((a[i + j + 1] == a[i - j]))
					{
						l1 += 2;
						cn = 1;
					}
				}
		

			}

/*			for (int j = 1; j <= sizeof(a) / 8; j++)
			{


			}
			*/		
			if (l1 > l2) // сравниваем подмассивы
			{
				if (cn == 0)
				{
					l2 = l1+1;
					beg = i + l2;
					en = i - l2;
				}
				else
				{
					l2 = l1 + 2;
					if (cn == 1) 
					{
						beg = i + l2+1;
						en = i - l2;
					}
					else
					{
						beg = i + l2 ;
						en = i - l2 - 1;
					}
						
				}			
				l1 = 0;

			}
		}

	}

	for (int i = 0; i < sizeof(a) / 4; i++)//вывод
	{
		if (i >= beg && i <= en && beg != en)
		{
			printf_s("%d ", a[i]);
		}
	}

}


