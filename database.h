#pragma once
#include <functional>
#include <map>
#include <set>
#include <utility>

#include "UnitTestFramework.h" //includes date


class Database {
    public:
    using db_t = std::map<Date, std::vector<std::string>>;
    using db_elem_t = std::pair<Date, std::vector<std::string>>;
    
    Database() {}
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& os) const;
    int RemoveIf(std::function<bool(const Date&, const std::string&)> predicat);
    std::vector<std::string> FindIf(std::function<bool(const Date&, const std::string&)> predicat) const;
    std::string Last(const Date& date) const;

    private:
    //std::multimap<Date, std::string> db_; 
    db_t db_m;
    std::set<std::string> dates_m;
};
