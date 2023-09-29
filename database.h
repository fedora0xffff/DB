#pragma once
#include <functional>
#include <map>
//#include "date.h"
#include "UnitTestFramework.h" //includes date


class Database {
    public:
    Database() {}
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& os) const;
    int RemoveIf(std::function<bool(const Date&, const std::string&)> predicat);
    std::vector<std::string> FindIf(std::function<bool(const Date&, const std::string&)> predicat);
    std::string Last(const Date& date);

    private:
    std::map<Date, std::string> db_;
};
