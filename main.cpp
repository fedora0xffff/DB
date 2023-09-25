#include <iostream>
#include <stdexcept>

#include "database.h"
//#include "date.h"
#include "condition_parser.h"
//#include "node.h"
//#include "UnitTestFramework.h"
#include "main.h"


//#define DEBUG

void TestAll(); 

std::string ParseEvent(std::istream& is) { //test
	std::string event = {};
	char c;
	bool first = true;
  is >> std::ws;
	if (c != EOF) {
    std::getline(is, event);
    }	
#ifdef DEBUG
		std::cout << "parsed event: " << event << std::endl;
#endif
	return event;
}



int main() {
  using namespace std;

  TestAll();
  Database db;

  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "Add") {
      const auto date = ParseDate(is);
      const auto event = ParseEvent(is);
      #ifdef DEBUG
      cout << "DBG: " << date << " " << event << endl;;
      #endif
      db.Add(date, event);
    } else if (command == "Print") {
      db.Print(cout);
        } else if (command == "Last") {
      try {
          cout << db.Last(ParseDate(is)) << endl;
      } catch (invalid_argument&) {
          cout << "No entries" << endl;
      }
    } else if (command.empty()) {
      continue;
    } else {
      throw logic_error("Unknown command: " + command);
    }
  }

  return 0;
}

void TestParseEvent() {
  using namespace std;
  {
    istringstream is("event");
    AssertEqual(ParseEvent(is), "event", "1 Parse event without leading spaces");
  }
  {
    istringstream is("   sport event ");
    AssertEqual(ParseEvent(is), "sport event ", "2 Parse event with leading spaces");
  }
  {
    istringstream is("  first event  \n  second event");
    vector<string> events;
    events.push_back(ParseEvent(is));
    events.push_back(ParseEvent(is));
    AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
  }
}

void TestAll() {
  std::TestRunner tr;
  tr.RunTest(TestParseEvent, "TestParseEvent");
  tr.RunTest(TestDateOps, "date test");
  tr.RunTest(TestParseCondition, "TestParseCondition");
}

/*
 } else if (command == "Del") {
      auto condition = ParseCondition(is);
      auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
      };
      int count = db.RemoveIf(predicate);
      cout << "Removed " << count << " entries" << endl;
    } else if (command == "Find") {
      auto condition = ParseCondition(is);
      auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
      };

      const auto entries = db.FindIf(predicate);
      for (const auto& entry : entries) {
        cout << entry << endl;
      }
      cout << "Found " << entries.size() << " entries" << endl;

 
 */
