#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;
class Matrix
{
public:
	Matrix() {
		myvec.resize(0);
		col_vec.resize(0);
	}
	Matrix(int num_rows, int num_cols)
	{
		if (num_rows > 0 && num_cols > 0)
		{
			rows = num_rows;
			cols = num_cols;
			myvec.resize(rows);
			col_vec.resize(cols);
		}
		else
		{
			throw out_of_range("");
		}
	}
	void Reset(int new_rows, int new_cols)
	{
		if (new_rows < 0 || new_cols < 0)
		{
			throw out_of_range("");
		}
		rows = new_rows;
		cols = new_cols;
		myvec.clear();
		col_vec.clear();
		myvec.resize(rows);
		col_vec.resize(cols);
	}
	int At(int row_num, int col_num) const
	{
		if (row_num >= rows || col_num >= cols)
		{
			throw out_of_range("");
		}
		return myvec[row_num][col_num];
	}
	int& At(int row_num, int col_num)
	{
		if (row_num >= rows || col_num >= cols)
		{
			throw out_of_range("");
		}
		int& res = myvec[row_num][col_num];
		return res;
	}
	int GetNumRows() const
	{
		return rows;
	}
	int GetNumColumns() const
	{
		return cols;
	}
	void ChangeVector(const vector<vector<int>>& v)
	{
		myvec = v;
	}
private:
	int rows = 0, cols = 0;
	vector<vector<int>> myvec;
	vector<int> col_vec;
};

istream& operator>>(istream& is, Matrix& m)
{
	int rows, cols;
	is >> rows >> cols;
	m.Reset(rows, cols);
	if (is)
	{
		vector<vector<int>> temp(rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (is)
				{
					int num;
					is >> num;
					temp[i].push_back(num);
				}
			}
		}
		m.ChangeVector(temp);
	}
	return is;
}
ostream& operator<<(ostream& os, const Matrix& m)
{
	os << m.GetNumRows() << ' ' << m.GetNumColumns() << endl;
	for (int i = 0; i < m.GetNumRows(); i++)
	{
		for (int j = 0; j < m.GetNumColumns(); j++)
		{
			os << m.At(i, j) << ' ';
		}
		os << endl;
	}
	return os;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.GetNumRows() == rhs.GetNumRows() && lhs.GetNumColumns() == rhs.GetNumColumns())
	{
		if (lhs.GetNumRows() == 0 && rhs.GetNumRows() == 0)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < lhs.GetNumRows(); i++)
			{
				for (int j = 0; j < lhs.GetNumColumns(); j++)
				{
					if (lhs.At(i, j) != rhs.At(i, j))
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	return false;
}
Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.GetNumRows() == rhs.GetNumRows() && lhs.GetNumColumns() == rhs.GetNumColumns())
	{
		Matrix result = { lhs.GetNumRows(), lhs.GetNumColumns() };
		vector<vector<int>> temp(lhs.GetNumRows());
		for (int i = 0; i < lhs.GetNumRows(); i++)
		{
			for (int j = 0; j < lhs.GetNumColumns(); j++)
			{
				temp[i].push_back(lhs.At(i, j) + rhs.At(i, j));
			}
		}
		result.ChangeVector(temp);
		return result;
	}
	else
	{
		throw invalid_argument("");
	}
}
// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {
	try
	{
		Matrix one;
		//Matrix two;

		cin >> one;
		cout << one;
	}
	catch (exception& ex)
	{
		cout << ex.what();
	}
	return 0;
}
