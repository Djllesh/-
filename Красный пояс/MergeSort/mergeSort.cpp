#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (range_end - range_begin < 2) return; 
	vector<typename RandomIt::value_type> result(make_move_iterator(range_begin), make_move_iterator(range_end));
	vector<typename RandomIt::value_type> temp;
	
	const auto third = (range_end - range_begin) / 3;
	auto first_third_end = range_begin + third;
	auto second_third_end = first_third_end + third;
	MergeSort(move(range_begin), move(first_third_end));
	MergeSort(move(first_third_end), move(second_third_end));
	MergeSort(move(second_third_end), move(range_end));
	merge(make_move_iterator(range_begin), make_move_iterator(first_third_end),
		make_move_iterator(first_third_end), make_move_iterator(second_third_end),
		back_inserter(temp)
	);	
	merge(make_move_iterator(temp.begin()), make_move_iterator(temp.end()),
		make_move_iterator(second_third_end), make_move_iterator(range_end),
		range_begin
	);
	
}

void TestIntVector() {
	vector<int> numbers = { 6, 1, 3, 9, 1, 9, 8, 12, 1 };
	MergeSort(begin(numbers), end(numbers));
	ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestIntVector);
	return 0;
}
