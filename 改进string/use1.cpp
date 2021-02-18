#include<iostream>
#include"string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main() {
	{
		using std::cin;
		using std::cout;
		using std::endl;
		String name;
		cout << "Hi,what's your name?\n>>";
		cin >> name;
		cout << name << " , please enter up to " << ArSize << " short saying <empty line to quit>:\n";
		String sayings[ArSize];
		char temp[MaxLen];
		int i = 0;
		for (; i < ArSize; i++) {
			cout << i + 1 << ": ";
			cin.get(temp, MaxLen);
			while (cin && cin.get() != '\n')
				continue;
			if (!cin || temp[0] == '\0')
				break;
			else
				sayings[i] = temp;
		}
		int total = i;
		if (total > 0) {
			cout << "\n\nHere are your saying:\n";
			for (int i = 0; i < total; i++) {
				cout << sayings[i][0] << ": " << sayings[i] << "    " << (sayings + i)->length() << endl;
			}

			int shortest = 0;
			int first = 0;
			for (i = 1; i < total; i++) {
				if (sayings[i].length() < sayings[shortest].length())
					shortest = i;
				if (sayings[i] < sayings[first])
					first = i;
			}
			cout << "Shortest sayings:\n" << sayings[shortest] << endl;
			cout << "First alphabetically:\n" << sayings[first] << endl;
			cout << "This program used " << String::HowMany() << " String object Bye!\n";
		}

		else {
			cout << "No input! Bye!\n";
		}
	}
	std::cout << "end of exe" << std::endl;
	return 0;
}