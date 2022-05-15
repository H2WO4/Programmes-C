#include <array>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter)
{
	stringstream input2(input);
	vector<string> output;
	string segment;

	while (getline(input2, segment, delimiter))
		output.push_back(segment);
	
	

	return output;	
}

class Vector
{
	protected:
		int n;
		int values[200];

	public:
		// * Constructors
		Vector() { this->n = 0; }
		template<typename... Args>
		Vector(Args ... args)
		{
			int values[] = { args ... };
			this->n = sizeof(values)/sizeof(*values);

			for (int i = 0; i < this->n; i++)
				this->values[i] = values[i];
		}

		// * Initialize
		static Vector initialize()
		{
			Vector out = Vector();

			string input;
			cin >> input;
			vector<string> vals = split(input, ' ');

			out.n = vals.size();
			for (int i = 0; i < out.n; i++)
				cout << vals[i] << ' ';

			for (int i = 0; i < out.n; i++)
				out.values[i] = stoi(vals[i]);

			return out;
		}

		// * Display
		void display()
		{
			int i;
			cout << '(';
			for (i = 0; i < this->n - 1; i++)
				cout << this->values[i] << ", ";
			cout << this->values[i+1] << ')' << endl;
		}

		// * Operations

};

int main()
{
	Vector a = Vector::initialize();

	a.display();

	return 0;
}