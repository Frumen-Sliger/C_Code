#include <unistd.h>
#include <stdio.h> // <----- Debugging
#include <time.h>   // <----- 
#include <stdlib.h> //only system(clear)

/*#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#define _EXFUN(name, proto) name proto
int _EXFUN(printf, (const char *__restrict, ...)
_ATTRIBUTE ((__format__ (__printf__, 1, 2))));*/

typedef struct dlist //Structure information
{
	int data;
	struct dlist *right;
	struct dlist *down;
	
	int col;
	int row;
	int all;
} Matrix;

Matrix * mInit(int data)//Initialization of Structure
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	temp->all = 1;
	temp->row = 1;
	temp->col = 1;
	
	return(temp);
}

Matrix addelemRight(int data, Matrix *head) //Adding element to Right
{
	Matrix *temp, *r;//init temp elem
	temp = (Matrix*)malloc(sizeof(Matrix));
	
	//Setting data
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	//Adding elem to Matrix
	r = head;
	while (r->right != NULL)
	{r = r -> right;}
	r -> right = temp;

}

Matrix addelemDown(int data, Matrix *head) //Adding element to Down
{
	Matrix *temp, *d; //init temp elem
	temp = (Matrix*)malloc(sizeof(Matrix));
	
	//Setting data
	temp -> data = data;
	temp -> right = NULL;
	temp -> down = NULL;
	
	//Adding elem to Matrix
	d = head; 
	while (d->down != NULL)
	{d = d -> down;}
	d -> down = temp;
	
}

void mPrint(Matrix *lst, int Row) //Outputs All Matrix Elements
{								  //Prints full row, then step lower
	Matrix *r, *d;
	d = lst;
	int i;
	for(i =0; i <Row; i++) //By row count
	{
		for (r = d; r != NULL; r = r->right)//Out full row
		{
			if(r->down!=NULL)
			{printf("|");}
			else {printf(" ");}
			
			printf("%d", r->data);
			
			if(r->right!=NULL)
			{printf("- ");}
			else {printf("  ");}
		}
		d = d->down;//Step lower
		if (d != NULL)
		{
			r = d;
		}
		printf("\n\n");
	}
}

void MatrixGeneration(Matrix *m, int Rand)
{
	int i, r, g;
	Matrix *temp = m;
	m->row--;
	for(i =0; i <Rand; i++)
	{
		m->row++;
		for(r =0; r <Rand; r++)
		{
			if(r != 0) 
			{
				addelemRight(rand() % 9, temp);
				m->all++;
			}
		}
		if(i != Rand-1) 
		{
			addelemDown(rand() % 9, temp);
			m->all++;
			m->col++;
		}
		
		temp = temp->down;
	}
	Matrix *upper =m;
	Matrix *lower =m;
	Matrix *t;
	
	for(r =0; r< Rand-1; r++)
	{
		t = upper;
		lower = upper -> down;
		for(g =0; g< Rand-1; g++)
		{
			upper = upper -> right;
			lower = lower -> right;
			
			upper -> down = lower;
		}
		upper = t;
		upper = upper -> down;
	}
}

void mSort(Matrix *m)
{
	printf("right -> down -> data: %d \n", m->right->down->data);
	printf("right -> down -> right -> down -> data: %d\n", m->right->down->right->down->data);
}

void main() 
{
	system("@cls||clear"); // Clear the console
	
	time_t t;
	srand((unsigned) time(&t));//Rand time tick
	int cNum =0;
	int rNum =0;
	int all =0;
	Matrix *MatrixMain;
	MatrixMain = mInit(rand() % 9); //Create the Matrix struct
	
	int mSize = 0;
	while (mSize < 1) {mSize = rand() % 10;} //Creating Random number
	
	printf("Matrix size - %d\n\n", mSize);
	MatrixGeneration(MatrixMain, mSize); //Generate Matrix
	mPrint(MatrixMain, mSize); //Outputs generated Matrix
	
	cNum = MatrixMain->col;
	rNum = MatrixMain->row;
	all = MatrixMain->all;
	
	
	printf("R- %d C- %d All- %d\n", rNum, cNum, all);
	
	mSort(MatrixMain);
}

