#include "database.h"

void Database::Add(const Date& date, const std::string& event){
	if (db_.find(date) != db_.end()){ //improvement:  insert dates in set to check existence fast
		std::cout << "Such a date already exists.\n" << std::endl;
	}
	else {
		db_[date] = event;
	}
	//DBG
	//std::cout << "DB flush : " << db_ << std::endl;
}

void Database::Print(std::ostream& os) const {
	for (const auto& elem: db_) {
		std::cout << elem.first << " " << elem.second << "\n";
	}
}

std::string Database::Last(const Date& date) {
	auto last_date = std::upper_bound(db_.begin(), db_.end(), date, 
			[](const Date& val, const std::pair<Date, std::string>& date_in_db) {
			return  date_in_db.first > val;
			});
	if (last_date == db_.begin()) {
		return "No entries";
	}
	else {
		auto target = std::prev(last_date);
		std::string res = (*target).first.PrintDate() + " " + (*target).second;
		return res;
	}
} 

int Database::RemoveIf(std::function<bool(const Date&, const std::string&)> predicat) {
	int count = 0;
	for (auto it = db_.begin(); it != db_.end();) {
		auto this_it = it++;
		auto element = *this_it;
		if (predicat(element.first, element.second)) {
			std::cout << "Erasing: " << element.first.PrintDate() << " " << element.second << std::endl;
			db_.erase(this_it);
			++count;
		}
	}
	return count;
}


std::vector<std::string> Database::FindIf(std::function<bool(const Date&, const std::string&)> predicat) {
	int count = 0;
	std::vector<std::string> res = {};
	for (auto it = db_.begin(); it != db_.end();) {
		auto element = *it;
		if (predicat(element.first, element.second)) {
			std::cout << "Found: " << element.first.PrintDate() << " " << element.second << std::endl;
			res.push_back(element.first.PrintDate() + " " + element.second);
			++count;
		}
		++it;
	}
	return res;
}
