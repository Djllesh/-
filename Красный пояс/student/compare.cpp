#include "student.h"
#include "test_runner.h"
#include "profile.h"
#include <algorithm>

using namespace std;

//Оптимизируйте эту функцию
bool Compare(const Student& first,const Student& second) {
    
    return first.Less(second);
}
