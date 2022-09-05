#include <array>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& input, char delimiter)
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
    int values[200]{ };

public:
    // Constructors
    Vector()
    { this->n = 0; }

    template<typename... Args>
    explicit Vector(Args ... args)
    {
        int temp_values[] = { args ... };
        n = sizeof(temp_values) / sizeof(*temp_values);

        for (int i = 0; i < this->n; i++)
            values[i] = temp_values[i];
    }

    // Initialize
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

    // Display
    void display()
    {
        int i;
        cout << '(' << values[0];
        for (i = 1; i < this->n; i++)
            cout << ", " << values[i];
        cout << ')' << endl;
    }

    // Operations

};

int main()
{
    Vector a = Vector(1, 2, 3, 4, 5);

    a.display();

    return 0;
}