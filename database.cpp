#include "database.h"

void Database::Add(const Date& date, const std::string& event){
	std::string temp = date.PrintDate() + event;
	if (dates_m.count(temp)) return; //delete?
	dates_m.insert(temp);
	db_m[date].push_back(event);
}

void Database::Print(std::ostream& os) const {
	for (const auto& elem: db_m) { 
		for (auto it = elem.second.begin(); it != elem.second.end(); ++it) //the order is mangled!
		os << elem.first << " " << *it << std::endl;
	}
}

std::string Database::Last(const Date& date) const {
	auto last_date = std::upper_bound(db_m.begin(), db_m.end(), date, 
			[](const Date& val, const db_elem_t& date_in_db) {
			return  date_in_db.first > val;
			});
	if (last_date == db_m.begin()) return "No entries";
	auto target = std::prev(last_date);
	size_t last_event = (*target).second.size() - 1;
	std::string res = (*target).first.PrintDate() + " " + (*target).second[last_event];
	return res;
} 

int Database::RemoveIf(std::function<bool(const Date&, const std::string&)> predicat) {
	int count = 0;
	for (auto it = db_m.begin(); it != db_m.end();) {
		auto this_it = it++;
		auto element = *this_it;
		auto res = std::stable_partition(element.second.begin(), element.second.end(), [=] (const std::string& str) {
			return !predicat(element.first, str); //evals to true for the ones to delete
		});
		int curr_count = std::distance(res, element.second.end());
		count += curr_count;
		if (curr_count == 0) continue;
		if (res == element.second.begin()) db_m.erase(element.first); //may be all events under this date were in the condition to delete
		else {
			auto last_elem = std::prev(element.second.end());
			while(last_elem <= res) {
				auto this_it = last_elem--;
				element.second.erase(this_it);
			}
			
		}
	}
	return count;
}

std::vector<std::string> Database::FindIf(std::function<bool(const Date&, const std::string&)> predicat) const {
	std::vector<std::string> res = {};
	for (auto it = db_m.begin(); it != db_m.end();) {
		auto element = *it;
		for (const auto& elem : element.second) {
			if(predicat(element.first, elem)) res.push_back(element.first.PrintDate() + " " + elem);
		}
		++it;
	}
	return res;
}
