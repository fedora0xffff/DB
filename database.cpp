#include "database.h"

Database::Add(const Date& date, const std::string& event){
	if (db_.find(date)){
		std::cout << "Such a date already exists. Overwrite (o) or ignore (i)?\n" << std::endl;
		char action;
		std::cin >> action;
		if (action == 'o'){
			db_[date] = event;
		}
	}
	else {
		db_[date] = event;
	}
}

void Database::Print(std::ostream& os){
	for (const auto& elem: db_) {
		std::cout << elem.first << " " << elem.second << "\n";
		//std::cout << std::endl;
	}
}

std::string Database::Last(const Date& date) {
	auto last_date = std::upper_bound(db_.begin(), db_.end(), date, 
			[](const Date& val, const Date& date_in_db) {
			return  date_in_db > val;
			});
	if (last_date == db_.begin()) {
		std::cout << "No entries";
	}
	else {
		auto target = std::prev(last_date);
		std::cout << (*target).first << " " << (*target).second;
	}
} 
