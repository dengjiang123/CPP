#include<iostream>
#include"brass.h"
int main() {
	using std::cout;
	using std::endl;

	Brass piggy("Porcelot Pigg", 381299, 4000.0);
	BrassPlus hoggy("Horation Hogg", 382288, 3000.0);

	piggy.ViewAcct();
	cout << endl;
	hoggy.ViewAcct();
	cout << endl;

	cout << "Depositing $1000 into the Hogg Account:\n";
	hoggy.Deposit(1000);
	cout << "New Balance: $" << hoggy.Balance() << endl;
	cout << endl;

	cout << "WithDrawing $4200 from the Pigg Account:\n";
	piggy.Withdraw(4200.0);
	cout << "Pigg account balance: $" << piggy.Balance() << endl;
	cout << endl;

	cout << "WithDrawing $4200 from the hogg Account:\n";
	hoggy.Withdraw(4200.0);
	cout << endl;
	cout << endl;
	hoggy.ViewAcct();

	return 0;
}