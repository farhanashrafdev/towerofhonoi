#include<iostream>
using namespace std;
struct tower {
	int data = 0;
	tower* next;
};
int won;
tower* head[3];
void insert(int n);
void push(int a, int b);
void display();
void displayt(int i);
void changelocation(int old, int newt);
int pop(int loc, int ttt);
bool checkwin();
int main() {
	int run;
	do {
		int t; int shifttower; int old, newt = 0;
		cout << "At which tower do you want to start the game:(1-3):  "; cin >> t;
		insert(t);
		cout << "Enter at which tower to end the game: "; cin >> won;
		do {
			int in = 0;
			system("cls");
			display();
			do {

				cout << "Enter where to push the value and from(old _ new): "; cin >> old >> newt;
				if (old <= 3 && old >= 1 && newt <= 3 && newt >= 1) { changelocation(old, newt); in = 1; }
				else cout << "Invalid enter again; ";
			} while (!in);
			run = 1;
			system("pause");
		}//doend
		while (!checkwin());
		cout << "Do you want to play again:(y:1/N:0) "; cin >> run;
	} while (run);
}//mainend
void insert(int a) {
	a -= 1;
	for (int i = 3; i > 0; i--) {
		push(i, a);
	}//forloop
}//pushend
void push(int i, int a) {
	tower* temp = new tower;
	temp->data = i;
	if (head[a] == NULL) {
		head[a] = temp;
		head[a]->next = NULL;
		temp = NULL; delete temp;
	}
	else {
		if (head[a]->data > temp->data) {
			temp->next = head[a];
			head[a] = temp;
			temp = NULL; delete temp;
		}
		else cout << "Invalid Step pushing in Low value tower..." << endl;
	}
}
void display() {
	cout << "------------TOWER OF HONOI------------------" << endl;
	for (int i = 0; i < 3; i++) {
		displayt(i); cout << " Tower: " << i + 1 << endl;
	}//forend
}//funend
void displayt(int i) {
	tower* thead = head[i];
	while (thead != NULL) {
		cout << thead->data << " "; thead = thead->next;

	}//whileend
}
void changelocation(int old, int newt) {
	newt -= 1; old -= 1;
	if (head[old] != NULL)
		push(pop(old, newt), newt);
	else { cout << "Tower is empty pls select another tower: " << endl; }
}//funend;
int pop(int loc, int ttt) {
	int tdata;
	if (head[ttt] != NULL) {
		if (head[ttt]->data > head[loc]->data) {
			tower* tempd = head[loc];
			tdata = head[loc]->data;
			head[loc] = head[loc]->next;
			delete tempd;
			return tdata;
		}
		else return 10;
	}
	else {
		tower* tempd = head[loc];
		tdata = head[loc]->data;
		head[loc] = head[loc]->next;
		delete tempd;
		return tdata;
	}
}
bool checkwin() {
	int count = 0;
	tower* thead = head[won - 1];
	while (thead != NULL)
	{
		thead = thead->next;
		count++;
	}
	if (count == 3) {
		cout << "Congrats you have won the game: " << endl;
		return true;
	}
	else return false;
}
