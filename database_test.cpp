#include <memory>
#include "database.h"
#include "node.h"
#include "database.h"
#include "condition_parser.h"

std::function<bool(Date, std::string)> predicatFather(std::shared_ptr<Node> root) {
        auto predicate = [root](const Date& date, const string& event) {
        return root->Evaluate(date, event);
        };
    return predicate;
}

void TestDB() {
    {
        Database db;
        db.Add(Date{2021,2,2}, "a");
        db.Add(Date{2021,2,2}, "b");
        db.Add(Date{2021,2,2}, "c");
        std::istringstream is(R"(event == "b")");
        auto predicate = predicatFather(ParseCondition(is));
        std::AssertEqual(db.RemoveIf(predicate), 1, "b not deleted");
    }
    {
        Database db;
        db.Add(Date{1997, 05, 27}, "BirthDay");
        db.Add(Date{2012, 12, 12}, "Apocalypse");
        db.Add(Date{2021, 01, 15}, "C++ start");
        db.Add(Date{2020, 12, 4}, "Fedor's Bday");
        db.Add(Date{2021, 12, 4}, "Fedor's Bday");
        //db.Print(std::cout);
        std::istringstream is(R"(event == "Apocalypse")");
        std::istringstream is1(R"(event == "Fedor's Bday")");
        auto predicat = predicatFather(ParseCondition(is));
        auto predicat1 = predicatFather(ParseCondition(is1));
        std::AssertEqual(db.RemoveIf(predicat), 1, "Apocalypse not found");
        std::AssertEqual(db.RemoveIf(predicat1), 2, "Fedor has 2 bdays");
       //db.Print(std::cout);
    }
    {
        Database db;
        db.Add(Date{1997, 05, 27}, "BirthDay");
        db.Add(Date{2012, 12, 12}, "Apocalypse");
        db.Add(Date{2021, 01, 15}, "C++ start");
        db.Add(Date{2020, 12, 4}, "Fedor's Bday");
        db.Add(Date{2021, 12, 4}, "Fedor's Bday");
        std::istringstream is("date < 2020-12-4");
        std::istringstream is1(R"(event != "Fedor's Bday")");
        auto predicat = predicatFather(ParseCondition(is));
        auto predicat1 = predicatFather(ParseCondition(is1));
        std::AssertEqual((db.FindIf(predicat)).size(), 2, ">2020-12-4");
        std::AssertEqual((db.FindIf(predicat1)).size(), 3, "not Fedor's bday");
    }
}