# include <iostream>
using namespace std;

class Point
{
	protected:
		double _x;
		double _y;
	public:
		// * Constructors
		Point(double x, double y)
		{
			this->_x = x;
			this->_y = y;
		}
		Point(double n)
		{
			this->_x = n;
			this->_y = n;
		}
		Point()
		{
			this->_x = 0;
			this->_y = 0;
		}

		// * Destructors
		~Point()
		{
			
		}

		// * Operators
		Point operator+(Point other)
		{
			Point out;
			out._x = this->_x + other._x;
			out._y = this->_y + other._y;
			return out;
		}
		Point operator+(Point* other)
		{
			Point out;
			out._x = this->_x + other->_x;
			out._y = this->_y + other->_y;
			return out;
		}

		void operator+=(Point other)
		{
			this->_x += other._x;
			this->_y += other._y;
		}
		void operator+=(Point* other)
		{
			this->_x += other->_x;
			this->_y += other->_y;
		}

		Point operator*(double other)
		{
			Point out;
			out._x = this->_x * other;
			out._y = this->_y * other;
			return out;
		}

		// * Getters
		double getX()
		{
			return this->_x;
		}
		double getY()
		{
			return this->_y;
		}
};

int main()
{
	Point a = Point(3, 2);
	a += Point(1, 9);

	cout << a.getX() << " " << a.getY() << endl;
}