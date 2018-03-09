//Dit programma voert berekeningen uit op de 2 ingevoerde wardes
#include "std_lib_facilities.h"

int main()
{
	int val1 = 0;
	int val2 = 0;
	cout << "Please enter two integer values separated by a space: ";
	cin >> val1 >> val2;
	
	cout << "Sum = " << val1 + val2								
		<< "\nProduct = " << val1 * val2 << "\n";
	if (val1 < val2) {						//Dit wordt uitgevoerd als waarde 1 kleiner is dan waarde 2
		cout << "Smallest = " << val1 << "\n"						
			<< "Largest = " << val2 << "\n"							
			<< "Difference = " << val2 - val1 << "\n";				
	}
	else if (val1 > val2) {						//Dit wordt uitgevoerd als waarde 1 groter is dan waarde 2
		cout << "Smallest = " << val2 << "\n"						
			<< "Largest = " << val1 << "\n"						
			<< "Difference = " << val1 - val2 << "\n";
	}
	else {								//Als val1 en val2 gelijk zijn dan wordt dit ook zo weergegeven
		cout << "Both values (" << val1 << " & " << val2 << ") are equal\n"
			<< "Difference = " << val1 - val2 << "\n";
	}
	cout << "Ratio = " << val1 << ":" << val2 << "\n";		//Geeft de ratio tussen de 2 getallen weer
	
	system("pause");
	return 0;
}
