#include "date.h"
#include "UnitTestFramework.h"
#include "testDate.h"

void TestDateParsing(){
    {
        std::istringstream is("2015-12-12");
        Date d = ParseDate(is);
        std::AssertEqual(Date{2015,12,12}, d, "2015-12-12 - a simple test");
    }
    {
        std::istringstream is("0-0-0");
        Date d = ParseDate(is);
        std::AssertEqual(Date{0,1,1}, d, "0-0-0 - month not 0");
    }
}

void TestDateClass() {
    {
        Date d{3000, 12, 5};
        std::cout << d << std::endl;
    }
    {
        Date d{115, 10, 10};
        std::cout << d << std::endl;
    }
    {
        Date d{9999, 1, 31};
        std::cout << d << std::endl;
    }

}

void TestAll() {
    std::TestRunner tr;
    TestDateClass();
    tr.RunTest(TestDateParsing, "Parsing test");
}

int main() {
    TestAll();
    return 0;
}
