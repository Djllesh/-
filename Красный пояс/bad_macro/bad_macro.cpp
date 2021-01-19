#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl

int main() {
    TestRunner tr;
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
        }, "PRINT_VALUES usage example #1");
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5.6, "red\nbelt");
        ASSERT_EQUAL(output.str(), "5.6\nred\nbelt\n");
        }, "PRINT_VALUES usage example #2");
    ostringstream output2;

    if (true) PRINT_VALUES(output2, 1, 2);
    else PRINT_VALUES(output2, 3, 4);
    
    tr.RunTest([&] {ASSERT_EQUAL(output2.str(), "1\n2\n"); }, "If/else condition");
    ostringstream output;
    for (int i = 1; i <= 5; i++)
        PRINT_VALUES(output, i, "5");
    tr.RunTest([&] {ASSERT_EQUAL(output.str(), "1\n5\n2\n5\n3\n5\n4\n5\n5\n5\n"); }, "For loop");
}
