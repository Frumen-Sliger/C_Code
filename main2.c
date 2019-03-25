#include <unistd.h>
#include <stdlib.h> //only system(clear)

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

void mLinkUpd(struct dlist m[])
{//Обновление ссылок
	/* //Старая формула
	m[0].row = &m[1];   m[0].col = &m[2];
	m[1].row = &m[3];   m[1].col = &m[4];
	m[2].row = &m[4];   m[2].col = &m[5];
	m[3].row = &m[6];   m[3].col = &m[7];
	m[4].row = &m[7];   m[4].col = &m[8];
	m[5].row = &m[8];   m[5].col = &m[9];
	m[6].row = 0;       m[6].col = &m[10];
	m[7].row = &m[10];  m[7].col = &m[11];
	m[8].row = &m[11];  m[8].col = &m[12];
	m[9].row = &m[12];  m[9].col = 0;
	m[10].row = 0;      m[10].col = &m[13];
	m[11].row = &m[13]; m[11].col = &m[14];
	m[12].row = &m[14]; m[12].col = 0;
	m[13].row = 0;      m[13].col = &m[15];
	m[14].row = &m[15]; m[14].col = 0;
	m[15].row = 0;      m[15].col = 0;
	//*/
	  //Новая формула
	m[0].row = &m[1];   m[0].col = &m[2];
	m[1].row = &m[4];   m[1].col = &m[3];
	m[2].row = &m[3];   m[2].col = &m[5];
	m[3].row = &m[7];   m[3].col = &m[6];
	m[4].row = &m[8];   m[4].col = &m[7];
	m[5].row = &m[6];   m[5].col = &m[9];
	m[6].row = &m[10];  m[6].col = &m[12];
	m[7].row = &m[11];  m[7].col = &m[10];
	m[8].row = 0;       m[8].col = &m[11];
	m[9].row = &m[12];  m[9].col = 0;
	m[10].row = &m[13]; m[10].col = &m[14];
	m[11].row = 0;      m[11].col = &m[13];
	m[12].row = &m[14]; m[12].col = 0;
	m[13].row = 0;      m[13].col = &m[15];
	m[14].row = &m[15]; m[14].col = 0;
	m[15].row = 0;      m[15].col = 0;
}

void mInit(struct dlist M[])
{//Установка значений матрицы
	/*int i;
	srand(time(NULL));
	for(i =0; i<16; i++)
	{m[i].data = rand() % 10;}*/
	
	
	M[0].data = 3; M[8].data = 4; 
	M[1].data = 2; M[9].data = 4;
	M[2].data = 5; M[10].data = 5;
	M[3].data = 4; M[11].data = 4;
	M[4].data = 5; M[12].data = 3;
	M[5].data = 1; M[13].data = 2;
	M[6].data = 6; M[14].data = 7;
	M[7].data = 3; M[15].data = 6;
	//*/
	/*
	M[0].data = 3; M[8].data = 2; 
	M[1].data = 7; M[9].data = 6;
	M[2].data = 2; M[10].data = 1;
	M[3].data = 4; M[11].data = 0;
	M[4].data = 8; M[12].data = 8;
	M[5].data = 5; M[13].data = 4;
	M[6].data = 1; M[14].data = 2;
	M[7].data = 4; M[15].data = 9;
	//*/
}

void mOut(struct dlist m[])
{//вывод Матрицы
	/*
	printf("|%d %d %d %d|\n",   m[0].data, m[1].data,  m[3].data,  m[6].data);
	printf("|%d %d %d %d|\n",   m[2].data, m[4].data,  m[7].data,  m[10].data);
	printf("|%d %d %d %d|\n",   m[5].data, m[8].data,  m[11].data, m[13].data);
	printf("|%d %d %d %d|\n\n", m[9].data, m[12].data, m[14].data, m[15].data);
	//*/
	
	printf("|%d %d %d %d|\n",   m[0].data, m[1].data,  m[4].data,  m[8].data);
	printf("|%d %d %d %d|\n",   m[2].data, m[3].data,  m[7].data,  m[11].data);
	printf("|%d %d %d %d|\n",   m[5].data, m[6].data,  m[10].data, m[13].data);
	printf("|%d %d %d %d|\n\n", m[9].data, m[12].data, m[14].data, m[15].data);
}

void mSort(struct dlist m[])
{//Сортировка
	int i;
	int j;
	
	for (i =0; i<16; i++)
	{
		int min = i;
		for (j = i + 1; j < 16; j++) 
        {
			if (m[j].data < m[min].data) 
			{
				min = j;
			}
		}
		int ch = m[i].data;
		m[i].data = m[min].data;
		m[min].data = ch;
	}
}

void mOutElem(struct dlist m[])
{//вывод поэлементно
	int i;
 	for(i =0; i <16; i++)
	{
		if(i<9) {printf(" %d - %d: ", i+1, m[i].data );}
		else {printf("%d - %d: ", i+1, m[i].data );}
		if(i==9||i==12||i==14)
		{
			printf("Right:%d, Down:0.\n", m[i].row->data);
		}
		else if(i==8||i==11||i==13)
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

void main() 
{
	system("@cls||clear"); // Clear the console
	struct dlist M[16]; //Create the Matrix struct
	mInit(M); //Initialize the Matrix
	mLinkUpd(M); //Set Matrix links
	mOut(M); //Print unsorted Matrix
	//mOutElem(M); //Print unsorted Matrix links debug
	
	mSort(M);	//Sort the Matrix
	mLinkUpd(M); //Update Matrix links
	mOut(M); //Print sorted Matrix
	//mOutElem(M); //Print sorted Matrix links debug
}
