#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;
class Temperature
{
private: 
	vector<int64_t> days;
	int64_t average = 0, avg_q = 0, sum_temp =0;
	int64_t size;
public:
	Temperature() {}
	Temperature(const vector<int64_t>& v)
	{
		days = v;
		size = static_cast<int64_t>(days.size());
	}
	int64_t CalculateAverage()
	{
		for (auto x : days)
		{
			sum_temp += x;
		}
		return average = sum_temp / size;
	}
	int64_t CalculateAvgQ()
	{
		for (auto x : days)
		{
			if (x > average)
			{
				avg_q++;
			}
		}
		return avg_q;
	}
	vector<int64_t> HigherTempElements()
	{
		vector<int64_t> res;
		for (int64_t i = 0; i < size; i++)
		{
			if (days[i] > average)
			{
				res.push_back(i);
			}
		}
		return res;
	}
};

istream& operator>>(istream& is, Temperature& T)
{
	int N;
	is >> N;
	vector<int64_t> days;
	for(int64_t i =0; i < N; ++i)
	{
		int64_t n;
		is >> n;
		days.push_back(n);
	}
	T = Temperature(days);
	T.CalculateAverage();
	return is;
}
ostream& operator<<(ostream& os,Temperature& T)
{
	os << T.CalculateAvgQ() << '\n';
	for(const auto& x: T.HigherTempElements())
	{
		os << x << ' ';
	}
	return os;
}
int main() {
	Temperature temp;
	cin >> temp;
	cout << temp;
  	return 0;
}
