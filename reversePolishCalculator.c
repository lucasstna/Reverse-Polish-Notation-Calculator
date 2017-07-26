/**************************************************
*
* Developed by Lucas Santana Escobar.
* Campo Grande - MS.
* Facom, Federal University of Mato Grosso do Sul
***************************************************/

#include <stdio.h>
#include <limits.h> //INT_MIN, INT_MAX
#include <string.h> //strlen
#include <stdlib.h> //malloc, atof

// Enumeration that defines the data type, opeator or operand
typedef enum {
	NUM,
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/',
	EXP = '^',
	LOG = 'L',
	FAT = '!',
	MOD = '%',
	END = '@'
} op_type;

// Defines a struct type, that can be used in stacks and queues 
typedef struct cell {
	double value;
	op_type type;
	struct cell *prox;
} cell;


//queue functions
void insertOperand(cell **, cell **, double);
void insertOperator(cell **, cell **, char []);
cell* removeCell(cell **, cell **);

//stack functions
void push(double ,cell **);
double pop(cell **);

//calculator functions
double power(double, double);
double log(double);
double factorial(double);
double module(double, double);

op_type identifica(char []);

int main () {
	char character[11];
	int tests;  
	cell *p;
	
	//get the number of test cases
	scanf("%d", &tests);

	for(int i = 0; i < tests; i++) {
		
		//creates a headless queue
		cell *start, *end;
		start = NULL;
		end = NULL;

		//creates a headless stack
		cell *t;
		t = NULL;


		//read the entry untill the '@' symbol
		do {
			scanf(" %s", character);
			
			//identify the character
			if (strlen(character) > 2) 
				insertOperand(&start, &end, atof(character));
			else 
				insertOperator(&start, &end, character);
		} while(character[0] != END);

		//performs the calculator functions
		p = removeCell(&start, &end);

		while (p != NULL) {
			double a = 0, b = 0;
			
			//finds out what operation should be done
			switch(p->type) {

				case ADD:
					a = pop(&t); 
					b = pop(&t);
					push(b + a, &t);
				break;

				case SUB:
					a = pop(&t); 
					b = pop(&t);
					push(b - a, &t);
				break;

				case MUL:
					a = pop(&t); 
					b = pop(&t);
					push(b * a, &t);
				break;

				case DIV:
					a = pop(&t); 
					b = pop(&t);
					push(b / a, &t);
				break;

				case EXP:
					a = pop(&t); 
					b = pop(&t);
					push(power(b, a), &t);
				break;

				case LOG:
					a = pop(&t); 
					push(log(a), &t);
				break;

				case FAT:
					a = pop(&t); 
					push(factorial(a), &t);
				break;

				case MOD:
					a = pop(&t); 
					b = pop(&t);
					push(module(b, a), &t);
				break;

				case END:	
				break;

				case NUM:
					push(p->value,&t);
				break;
			}

			free(p);

			p = removeCell(&start, &end);
		}

		//prints the result
		printf("%.2lf\n", pop(&t));

		//destroys the stack 
		free(t);
	}

	return 0;

}

//Receives a double value and a headless queue, and inserts it in the end of the queue
void insertOperand(cell **start, cell **end, double character) {
	//creates a new cell, and fills its fields
	cell *new;
	new = (cell *)malloc(sizeof(cell));
	new->value = character;
	new->prox = NULL;
	new->type = NUM;

	if((*start) != NULL)
		(*end)->prox = new;
	else 
		(*start) = new;
	(*end) = new;

	return;
}

//Receives a character and a headless queue, and inserts it in the end of the queue
void insertOperator(cell **start, cell **end, char character[]) {
	//creates a new cell, and fills its fields
	cell *new;
	new = (cell *)malloc(sizeof(cell));
	new->prox = NULL;
	new->value = atof(character);
	new->type = identifica(character);

	(*end)->prox = new;
	(*end) = new;

	return;
}

//Receives a headless queue and removes it first elemment
cell* removeCell(cell **i, cell **f) {
	cell *p;
	p = (*i);
	if((*i) != NULL) {
		(*i) = p->prox;
		if((*i) == NULL) 
			(*f) = NULL;
	}
	return p;
}

//Receives a headless stack and a double value, and inserts it on the top of the stack
void push(double x, cell **t) {
	cell *new;
	new = (cell *)malloc(sizeof(cell));

	new->value = x;
	new->prox = (*t);
	(*t) = new;

	return;
}

//Receives a headless stack, and removes the value on its top
double pop(cell **t) {
	double x;
	cell *trash;
	
	if((*t) != NULL) {
		trash = (*t);
		x = trash->value;
		(*t) = trash->prox;
		free(trash);

		return x;
	}

	else 
		return (double)INT_MIN;
}

//Recebe dois números de precisão double, e devolve o primeiro elevado ao piso do segundo
double power(double a, double b) {
	double power = 1;
	while (power < (int)b) {
		a *= a;
		power++;
	}

	return a;
}

//Receives a double value, and returns the floor of its logarithm in base 2
double log(double a) {
	int pot2, p ;
	//initializes the values
	p = 0 ;
	pot2 = 1 ; //2⁰
	
	//enquanto a power de 2 for menor que o número
	while (pot2 <= (int)a) {
		pot2 *= 2 ; //increases by two
		p++ ; //increases the power
	}

	return p - 1 ;
}

//Receives a double value, and returns the factorial of its floor
double factorial(double a) {
	//obtains the number's floor
	int pisoA = (int)a;
	double factorial = pisoA;

	//treats the special cases, fat(0) e fat(1)
	if((pisoA == 0) || (pisoA == 1))
		factorial = 1.0;
	else {
		for (pisoA = (int)a - 1; pisoA > 0; pisoA--)
			factorial = (factorial * pisoA);
	}
		
	return factorial;
}

//Receives two double values, and returns its module's floor
double module(double a, double b) {
	int pisoA, pisoB;
	//obtains the numbers' floor
	pisoA = (int)a;
	pisoB = (int)b;

	return (double)(pisoA % pisoB);
}

//Receives an string and identify the operation it represents
op_type identifica(char value[]) {
	op_type type;

	switch(value[0]) {

		case '+':
			type = ADD;
		break;

		case '-':
			type = SUB;
		break;

		case '*':
			type = MUL;
		break;

		case '/':
			type = DIV;
		break;

		case '^':
			type = EXP;
		break;

		case 'L':
			type = LOG;
		break;

		case '!':
			type = FAT;
		break;

		case '%':
			type = MOD;
		break;

		case '@':
			type = END;
		break;
	}

	return type;
}
