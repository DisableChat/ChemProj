// Wesley Ryder
// Hw8 Header File
// 4/20/17
// Description: This is the defining functions for the functions that were declared in the header files.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
#include "chemical.h"		// including header file.



int menu(){			// this is the menu cout statements.
    int choice;
    cout<<"Chose from the options below.\n";
    cout<<"1) View your molecule thus far.\n";
    cout<<"2) Input an element for your molecule.\n";
    cout<<"3) Use multiples of your element.\n";
    cout<<"4) Add your multi-atom element to your molecule.\n";
    cout<<"5) Save your molecule into your collection.\n";
    cout<<"6) Clear your molecule.\n";
    cout<<"7) Invent your own element - must know atomic number and atomic weight.\n";
    cout<<"0) Quit The Chemical Builder.\n";
    cout<<"Choice: ";
    cin>>choice;
return choice;
}
Chemical::Chemical(){  //defualt constructor
	symbol = " ";
	number = 0;
	weight = 0.0;
}

Chemical::Chemical(string s){ //constructor with one argument
	symbol = s;
}

Chemical::Chemical(string s, int n, double w){ //constructor with 3 arguments
	symbol = s;
	number = n;
	weight = w;
}

string Chemical::get_symbol(){	// accesor functions
	return symbol;
}

int Chemical::get_number(){
	return number;
}

float Chemical::get_weight(){
	return weight;
}

void Chemical::get_element(string& chemsym, istream& fin, Chemical& element){  // setting elements info to object symbol,number and weight.
	Chemical temp;																
	
	fin >> temp.symbol >> temp.number >> temp.weight;
	while (!  fin.eof()){
		if (chemsym == temp.symbol){
			element.symbol = temp.symbol;
			element.number = temp.number;
			element.weight = temp.weight;
		}
		fin >> temp.symbol >> temp.number >> temp.weight;
	}
}

void Chemical::clear(){		// clear function for menu
	symbol = " ";
	number = 0;
	weight = 0;
}

Chemical operator +(const Chemical& molecule, const Chemical& element){	// overiding + operator func
	Chemical temp;
	temp.symbol = molecule.symbol + element.symbol;
	temp.number = molecule.number + element.number;
	temp.weight = molecule.weight + element.weight;
	return temp;
}

Chemical operator *(const Chemical& element, int& multiplier){		// overiding * operator func
	Chemical temp;
	string mult;
	temp.number = element.number * multiplier;
	temp.weight = element.weight * multiplier;
	mult = itostr(multiplier);
	temp.symbol = element.symbol + mult;
	return temp;
}

void Chemical::set(string s, int n, double w){ // set function to set vars
	symbol = s;
	number = n;
	weight = w;
}

ofstream& operator <<(ofstream& out, const Chemical& molecule){ // output to text file
	out << "Molecular Compound:" << molecule.symbol << endl;
	out << "Total atomic number: " << molecule.number << endl;
	out << "Total atomic weight: " << molecule.weight << endl;
	out << "--------------------------------------------------" << endl;
	return out; 
}
ostream& operator <<(ostream& out, const Chemical& molecule){ // ouput to console
	out << "Molecular Compound:" << molecule.symbol << endl;
	return out;
}

istream& operator >>(istream& input, Chemical& element){  // input element symbol func 
	input >> element.symbol;
	return input;
}

string itostr(int num){			// *NOTE* given function by Professor Dolan to int to string 
    string one,result;
    while(num > 0){
    	one += static_cast<char>(num%10)+'0';
		result.insert(0,one);     
        one = "";  
        num /= 10; 
    }
    return result;
}
