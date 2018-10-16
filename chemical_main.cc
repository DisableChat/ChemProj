// Wesley Ryder
// Hw8 Header File
// 4/20/17
// Description: The purpose of this program is to use the chemical.cc file and header file to make afunctioning main.
// It is a program that allows users to add atoms together to make a molecule.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
#include "chemical.h" //including header file


int main(){
   ifstream fin;
   ofstream fout;
   Chemical element, molecule;
   string chemsym;
   int multiplier;
   int chosen;

   fin.open("elements.txt");
   if(fin.fail()){
	cout<<"Unable to open the File of Elements.\n";
	cout<<"Exiting the program.\n";
	return 1;
   }

   fout.open("Mychemicals.txt");   //opens "mychemicsl.txt"
   if(fout.fail()){
	cout<<"Unable to open output file.\n";
	cout<<"Exiting program.\n";
	return 1;
   }

   do{
	chosen = menu();						// menu cases 1-9 and 0.
	switch(chosen){
	    case 1: cout<<molecule<<endl;
		break;
	    case 2: fin.clear();
		fin.seekg(0, ios::beg);
		element.clear();
                cout<<"Give the Chemical Symbol for your element: ";
                cin>>chemsym;
		element.get_element(chemsym, fin, element);
                break;
	    case 3: cout<<"Multiply your element by what? ";
   		cin>>multiplier;
		element = element*multiplier;
		break;
	    case 4: molecule = molecule + element;
 		break;
	    case 5: fout<<molecule<<endl;
		break;
	    case 6: molecule.clear();
		break;
	    case 7: cout<<"Enter your own element:\n";
		element.clear();
		cin>>element;
		break;
	    case 0: cout<<"Thank you for using Chemical Builder.\n";
		cout<<"I hope that you have used it for good and not for evil.\n";
		break;
	    default: cout<<"Not a valid choice.\n";
		break;
	    } // bottom of the switch;
    }while(chosen != 0);
    fin.close();
    fout.close();  

return 0;
}