#include <unistd.h>
#include <stdlib.h> //only system(clear)

#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#define _EXFUN(name, proto) name proto
int _EXFUN(printf, (const char *__restrict, ...)
_ATTRIBUTE ((__format__ (__printf__, 1, 2))));

typedef struct dlist //Structure information
{
	int data;
	struct dlist *right;
	struct dlist *down;
} Matrix;

Matrix *mInit(int data)//Initialization of Structure  --  Matrix 
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	return(temp);
}

Matrix addelemRight(int data, Matrix *head) //Adding element to Right
{
	Matrix *temp, *r; //init temp elem
	temp = (Matrix*)malloc(sizeof(Matrix));
	
	printf("5\n");
	//Setting data
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	printf("6\n");
	//Adding elem to Matrix
	r = head;
	
	while (r->right != NULL)
	{r = r -> right;printf("7\n");}
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
			printf("%d", r->data);
			//printf("1\n");
		}
		d = d->down;//Step lower
		if (d != NULL)
		{
			r = d;
		}
		printf("row done\n");//debug
	}
}

void main() 
{
	system("@cls||clear"); // Clear the console
	Matrix MatrixMain; //Create the Matrix struct
	//int Elem = 0;
	
	mInit(1);
	
	//printf("%d\n", &MatrixMain.right->right->right);
	
	/*
	printf("1\n");//debug
	addelemRight(1, &MatrixMain);
	printf("2\n");//debug
	addelemRight(1, &MatrixMain);
	addelemRight(1, &MatrixMain); 
	
	addelemDown(1, &MatrixMain);
	addelemDown(1, &MatrixMain);
	*/
	
	/* - Matrix view - *\
	
		 |1 1 1 1|
		 |1 |
		 |1 |
		 | |
	
	\*                 */
	//mPrint(&MatrixMain, 1);
}
