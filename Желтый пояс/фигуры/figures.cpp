#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include <iomanip>
#include <math.h>
const float pi = 3.14f;
using namespace std;
class Figure
{
public:
	virtual string Name() const = 0;
	virtual float Perimeter()const = 0;
	virtual float Area()const = 0;
};


class Rect : public Figure
{
public:
	Rect(const float width_ , const float height_)
	{
		width = width_;
		height = height_;
	}
	string Name() const override
	{
		return "RECT";
	}
	float Perimeter() const override
	{
		return 2.00f * (width + height);
	}
	float Area() const override
	{
		return width * height;
	}
private:
	float width = 0.00f, height = 0.00f;
};


class Triangle : public Figure
{
public:
	Triangle(const float a_, const float b_, const float c_)
	{
		a = a_; b = b_; c = c_;
		p = (a + b + c) / 2;
	}
	float Perimeter() const override
	{
		return a + b + c;
	}
	float Area() const override
	{
		return sqrtf(p * (p - a) * (p - b) * (p - c));
	}
	string Name() const override
	{
		return "TRIANGLE";
	}
private:
	float a, b, c, p;
};


class Circle : public Figure
{
public:
	Circle(const float r_)
	{
		r = r_;
	}
	float Area() const override
	{
		return pi * r * r;
	}
	string Name() const override
	{
		return "CIRCLE";
	}
	float Perimeter() const override
	{
		return 2 * pi * r;
	}
private:
	float r;
};


shared_ptr<Figure> CreateFigure(istream& is)
{
	string figure;
	is >> figure;
	if (figure == "RECT")
	{
		float width, height;
		is >> width >> height;
		Rect r(width, height);
		return make_shared<Rect>(r);
	}
	else if (figure == "TRIANGLE")
	{
		float a, b, c;
		is >> a >> b >> c;
		Triangle t(a, b, c);
		return make_shared<Triangle>(t);
	}
	else if (figure == "CIRCLE")
	{
		float r;
		is >> r;
		Circle c(r);
		return make_shared<Circle>(c);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			
			is >> ws;
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}