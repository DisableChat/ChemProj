// Wesley Ryder
// Hw8 Header File
// 4/20/17
// Description: header file for Hw8.

class Chemical{
	public:
		string get_symbol();
		int get_number();					// declaring funcs and freind funcs
		float get_weight();
		Chemical();
		Chemical(string s);
		Chemical(string s, int n, double w);
		void get_element(string& chemsym, istream& fin, Chemical& element);
		void clear();
		void set(string s, int n, double w);
		friend ofstream& operator <<(ofstream& out, const Chemical& molecule);
		friend ostream& operator <<(ostream& out, const Chemical& molecule);
		friend istream& operator >>(istream& input, Chemical& element);
		friend Chemical operator +(const Chemical& molecule, const Chemical& element);
		friend Chemical operator *(const Chemical& element, int& multiplier);

	private:
		string symbol;  // private variable declarations
		int number;
		double weight;
};

string itostr(int num); // prototype functions 
int menu();