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
	printf("|%d %d %d %d|\n", m[0].data,  m[1].data,  m[2].data,  m[3].data); 
	printf("|%d %d %d %d|\n", m[4].data,  m[5].data,  m[6].data,  m[7].data); 
	printf("|%d %d %d %d|\n", m[8].data,  m[9].data,  m[10].data, m[11].data); 
	printf("|%d %d %d %d|\n", m[12].data, m[13].data, m[14].data, m[15].data); 
	printf("\n");
}

void sortRow(struct dlist m[], int R)
{//сортировка строк - не идеально
	int a;
	int e;
	for(a=R-4; a<R; a++)
	{
		for(e =a+1; e<R; e++)
		{
			if(m[a].data > m[e].data)
			{
				int ch = m[a].data;
				m[a].data = m[e].data;
				m[e].data = ch;
				mOut(m);
			}
		}
	}
}

void sortCol(struct dlist m[], int C)
{//сортировка столбцов - не идеально
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
				mOut(m);
			}
		}
	}

}

void main() 
{
	// на for
	int i;
	
	//задание матрицы
	struct dlist M[16];
	M[0].data = 3; M[8].data = 4; 
	M[1].data = 2; M[9].data = 4;
	M[2].data = 5; M[10].data = 6;
	M[3].data = 4; M[11].data = 4;
	M[4].data = 5; M[12].data = 3;
	M[5].data = 1; M[13].data = 2;
	M[6].data = 6; M[14].data = 7;
	M[7].data = 3; M[15].data = 6;
	
	//Сортировка ссылок элементов матрицы
	mLinkSort(M);

	//вывод матрицы
	mOut(M);
	
	//Вывод каждого эл. матрицы со всеми ссылками
	mOutElem(M);
	
	//Сортировка 
	int b;
	for (b =4; b>0; b--)
	{
		sortRow(M, b*4);
	}
	for (b =3; b>=0; b--)
	{
		sortCol(M, b);
	}
	
	
 	/*for(i =0; i <16; i++)
	{
		if(M[i].row->data > M[i].col->data)
		{
			int ch = M[i].data;
			M[i].data = M[i].row->data;
			M[i].row->data = ch;
			mLinkSort(M);
		}
	}*/
	
	mOut(M);

	//Сортировка ссылок элементов матрицы
	mLinkSort(M);

	//вывод матрицы
	mOut(M);
	
	//Вывод каждого эл. матрицы со всеми ссылками
	mOutElem(M);
}
