#include <unistd.h>

#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#define _EXFUN(name, proto) name proto
int _EXFUN(printf, (const char *__restrict, ...)
_ATTRIBUTE ((__format__ (__printf__, 1, 2))));

struct dlist
{
	int data;
	struct dlist *row;
	struct dlist *col;
};

void mLinkSort(struct dlist m[])
{// Установка ссылок 
	int i;
	for(i =0; i <16; i++)
	{
		if(i!=3||i!=7||i!=11)
		{
			m[i].row = &m[i+1];	
		}
		else { m[i].row = 0; }
		if(i<=11)
		{
			m[i].col = &m[i+4];	
		}
		else { m[i].col = 0; }
	}
	
}

void mOutElem(struct dlist m[])
{//вывод поэлементно
	int i;
 	for(i =0; i <16; i++)
	{
		if(i<9) {printf(" %d - %d: ", i+1, m[i].data );}
		else {printf("%d - %d: ", i+1, m[i].data );}
		if(i==12||i==13||i==14)
		{
			printf("Right:%d, Down:0.\n", m[i].row->data);
		}
		else if(i==3||i==7||i==11)
		{
			printf("Right:0, Down:%d.\n", m[i].col->data);
		}
		else if(i==15)
		{
			printf("Right:0, Down:0.\n\n");
		}
		else {printf("Right:%d, Down:%d.\n", m[i].row->data, m[i].col->data);}
	}
}

void mOut(struct dlist m[])
{//вывод матрицы
	int i;
	for (i=0;i<16;i++)
	{
		if(i==0||i==4||i==8||i==12)
		{
			printf("|%d ", m[i].data);
		} else if (i==3||i==7||i==11||i==15)
		{
			printf("%d|\n", m[i].data);
		} else
		{
			printf("%d ", m[i].data);
		}
	}
	printf("\n");
}

void sortRow(struct dlist m[], int R)
{//сортировка по строкам
	int a;
	int e;
	//int R;

	R=R*4;
	for(a=R-4; a<R; a++)
	{
		for(e =a+1; e<R; e++)
		{
			if(m[a].data > m[e].data)
			{
				int ch = m[a].data;
				m[a].data = m[e].data;
				m[e].data = ch;
				
				//printf("Mode: Row\n");
				//mOut(m); //дебаг
			}
		}
	}
	mLinkSort(m);
}

void sortCol(struct dlist m[], int C)
{//сортировка по столбам
	int a;
	int e;

	for(a =C; a<16; a=a+4)
	{
		for(e =a+4; e<16; e=e+4)
		{
			if(m[a].data > m[e].data){
				int ch = m[a].data;
				m[a].data = m[e].data;
				m[e].data = ch;
				
				//printf("Mode: Col\n");
				//mOut(m); //дебаг
			}
		}
	}
	mLinkSort(m);
}

void ColRowSort(struct dlist m[])
{
	int b;
	for(b =0; b<16; b++)
	{
		if(m[b].row!=0 && m[b].col!=0)
		{
			if( (m[b].row->data < m[b].col->data))
			{
				int ch = m[b].row->data;
				m[b].row->data = m[b].col->data;
				m[b].col->data = ch;
				
				//printf("Mode: Col/Row\n");
				//mOut(m); //дебаг
			}
		}
	}
	mLinkSort(m);
}

void SortFull(struct dlist m[])
{
	int b;
	int k;
	for (b =1; b<5; b++)
	{
		sortRow(m, b);
	}
	for (b =0; b<4; b++)
	{
		sortCol(m, b);
	}
	mLinkSort(m);
}

void SortDown(struct dlist m[])
{
	int b;
	for(b =0; b<15; b++)
	{
		if(m[b].col!=0)
		{
			if(m[b].data>m[b].col->data)
			{
				int ch = m[b].data;
				m[b].data = m[b].col->data;
				m[b].col->data = ch;
			}
		}
	}
	mLinkSort(m);
}

void SortRight(struct dlist m[])
{
	int b;
	for(b =0; b<15; b++)
	{
		if(m[b].row!=0)
		{
			if(m[b].data>m[b].row->data)
			{
				int ch = m[b].data;
				m[b].data = m[b].row->data;
				m[b].row->data = ch;
			}
		}
	}
	mLinkSort(m);
}

void Sort1(struct dlist m[])
{
	SortRight(m);
	mLinkSort(m);
	SortDown(m);
	
	SortRight(m);
	mLinkSort(m);
	SortDown(m);
}

void treeSortRight(struct dlist m[], int t)
{
	int nextRight;
	if(m[t].row!=0);
	{
		if(m[t].data > m[t].row->data)
		{
			int ch = m[t].data;
			m[t].data = m[t].row->data;
			m[t].row->data = ch;
		}
		mLinkSort(m);
	}
	if(m[t].row != 0)
	{
		nextRight = t+1;
	} else {nextRight = 0;}
}

void treeSortDown(struct dlist m[], int t)
{
	int nextDown;
	if(m[t].col!=0);
	{
		if(m[t].data > m[t].col->data)
		{
			int ch = m[t].data;
			m[t].data = m[t].col->data;
			m[t].col->data = ch;
		}
		mLinkSort(m);
	}
	if(m[t].col != 0)
	{
		nextDown = t+4;
	} else {nextDown = 0;}
}

void treeSort(struct dlist m[])
{
	int g;
	do 
	{
		treeSortRight(m, g);
	} 
	while (); 
	g =0;
	do 
	{
		
	} 
	while ();
}

void main() 
{
	// на for
	int i;
	
	//задание матрицы
	struct dlist M[16];
	/*M[0].data = 0; M[8].data = 1; 
	M[1].data = 1; M[9].data = 2;
	M[2].data = 2; M[10].data = 2;
	M[3].data = 3; M[11].data = 3;
	M[4].data = 3; M[12].data = 3;
	M[5].data = 4; M[13].data = 4;
	M[6].data = 4; M[14].data = 5;
	M[7].data = 5; M[15].data = 6;//*/ //На редактирование
	
	M[0].data = 3; M[8].data = 4; 
	M[1].data = 2; M[9].data = 4;
	M[2].data = 5; M[10].data = 5;
	M[3].data = 4; M[11].data = 4;
	M[4].data = 5; M[12].data = 3;
	M[5].data = 1; M[13].data = 2;
	M[6].data = 6; M[14].data = 7;
	M[7].data = 3; M[15].data = 6;//*/ //Работающий вариант
	


	mLinkSort(M); //Сортировка ссылок
	mOut(M); //Вывод матрицы
	mOutElem(M); //Вывод элементов с ссылками

	//Сортировка
	
	//Sort1(M); 
	//ColRowSort(M);
	//SortFull(M);
	treeSort(M);
	
	mLinkSort(M); //Сортировка ссылок
	mOut(M); //Вывод матрицы
	mOutElem(M); //Вывод элементов с ссылками
}
