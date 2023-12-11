// var.24 Chirkov Спросить о алгоритме Манагера

#include <iostream>
#include <stdio.h>
#include<math.h>

using namespace std;


bool isExist(int s, int a, int b)
{
	bool bo = false;
	if (a < s-1 && b >=0)
		bo = true;
	return bo;
}

void main()
{
	char  s [] = "5454555555211112";
	int beg=0, en=0, l1 = 0,max=0,count =1 ;
	char  a = ' ', b = ' ';
	int raz = sizeof(s);
	for (int i = 0; i < raz; i++)
	{
		
		if (i != 0 && i != (raz) - 2) // 1 и последний не учитываются
		{
			if (s[i] == s[i + 1] && i + 1< (raz - 1))
			{
				a = s[i + 1];
				b = s[i];
				while (a == b && isExist(raz, i + count, i - count + 1)) // ищем палендром
				{
					count++;
					a = s[i + count];
					b = s[i - count + 1];			
				}
				count--;
				if (max < count)
				{
					max = count;
					beg = i - count+1;
					en = i + count;
					l1 = 1;
				}
				count = 1;
			}
			if (s[i] == s[i - 1] && (i - 1 > 0))
			{
				a = s[i];
				b = s[i-1];
				while (a == b && isExist(raz, i + count-1, i - count)) // ищем палендром
				{
					count++;
					a = s[i + count - 1];
					b = s[i - count];
				}
				count--;
				if (max < count)
				{
					max = count;
					beg = i - count;
					en = i + count-1;
					l1 = 2;
				}
				count = 1;
			}
			if ((i - 1 > 0) && i + 1 < (raz - 2) && s[i + 1] == s[i - 1])
			{
				a = s[i + 1];
				b = s[i - 1];
				while (a == b && isExist(raz, i + count, i - count)) // ищем палендром
				{
					count++;
					a = s[i + count];
					b = s[i - count];
				}
				count--;
				if (max < count)
				{
					max = count;
					beg = i - count ;
					en = i + count ;
					l1 = 3;
				}
				count = 1;
			}
		}
	}
	for (int i = 0; i < raz; i++)//вывод
	{
		if (i >= beg && i <= en && beg != en)
		{
			printf_s("%c ", s[i]);
		}
	}
	printf_s("\n%d", l1);

	/*for (int i = 0; i < sizeof(a) / 4; i++)
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
	}*/
	

}


