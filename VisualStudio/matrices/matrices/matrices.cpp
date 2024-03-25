#include<stdio.h>
#include<iostream>
using namespace std;
/*
struct Matrix
{
	int A[10];
	int n;
};
void Set(struct Matrix* m, int i, int j, int x)
{
	if (i == j)
		m->A[i - 1] = x;

}
int Get(struct Matrix m, int i, int j)
{
	if (i == j)
		return m.A[i - 1];
	else
		return 0;
}
void Display(struct Matrix m)
{
	int i, j;
	for (i = 0; i < m.n; i++)
	{
		for (j = 0; j < m.n; j++)
		{
			if (i == j)
				printf("%d ", m.A[i]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}
int main()
{
	struct Matrix m;
	m.n = 4;

	Set(&m, 1, 1, 5); Set(&m, 2, 2, 8); Set(&m, 3, 3, 9); Set(&m,4, 4, 12);
	printf("%d \n", Get(m, 2, 2));
	Display(m);
	return 0;
}
*/



// C++ Class for Diagonal matrix
class diagonal {
private:
	int n;
	int* A;
public:
	diagonal() {
		n = 2;
		A = new int[2];
	}
	diagonal(int n) {
		this->n = n;
		A = new int[n];
	}
	~diagonal() {
		delete []A;

	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void Display();
	
};

void diagonal::set(int i, int j, int x) {
	if (i == j)
		A[i - 1] = x;
}

int diagonal::get(int i, int j) {
	if (i == j)
		return A[i - 1];
	else
		return 0;
}

void diagonal::Display() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j)
				cout << A[i]<<" ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int main() {
	diagonal d(4);
	d.set(1, 1, 5);
	d.set(2, 2, 10);
	d.set(3, 3, 15);
	d.set(4, 4, 20);

	d.Display();
	return 0;
}