#include <memory>
#include "database.h"
#include "node.h"
#include "database.h"
#include "condition_parser.h"

void TestDB() {
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
        std::shared_ptr<Node> root = ParseCondition(is);
        std::shared_ptr<Node> root1 = ParseCondition(is1);
        auto predicate = [root](const Date& date, const string& event) {
        return root->Evaluate(date, event);
        };
        auto predicate1 = [root1](const Date& date, const string& event) {
        return root1->Evaluate(date, event);
        };
        std::AssertEqual(db.RemoveIf(predicate), 1, "Apocalypse not found");
        std::AssertEqual(db.RemoveIf(predicate1), 2, "Fedor has 2 bdays");
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
        std::shared_ptr<Node> root = ParseCondition(is);
        std::shared_ptr<Node> root1 = ParseCondition(is1);
        auto predicate = [root](const Date& date, const string& event) {
        return root->Evaluate(date, event);
        };
        auto predicate1 = [root1](const Date& date, const string& event) {
        return root1->Evaluate(date, event);
        };
        std::AssertEqual((db.FindIf(predicate)).size(), 2, ">2020-12-4");
        std::AssertEqual((db.FindIf(predicate1)).size(), 3, "not Fedor's bday");
    }
}