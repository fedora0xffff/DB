// Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode 
#include "node.h"


bool DateComparisonNode::Evaluate(const Date& date, const std::string event) {
    if (cmp_ == Comparison::Equal) return date == date_;
    else if (cmp_ == Comparison::Less) return date < date_;
    else if (cmp_ == Comparison::LessOrEqual)  return date < date_ || date == date_; //improvement: overload ops
    else if (cmp_ == Comparison::Greater) return date > date_;
    else if (cmp_ == Comparison::GreaterOrEqual) return date > date_ || date == date_;
    else if (cmp_ == Comparison::NotEqual) return date != date_;
    else return false;
}

bool EventComparisonNode::Evaluate(const Date& date, const std::string event) {
     if (cmp_ == Comparison::Equal) return event == event_; // lexicographic comp 
    else if (cmp_ == Comparison::Less) return event < event_;
    else if (cmp_ == Comparison::LessOrEqual)  return event <= event_; //improvement: overload ops
    else if (cmp_ == Comparison::Greater) return event > event_;
    else if (cmp_ == Comparison::GreaterOrEqual) return event >= event_;
    else if (cmp_ == Comparison::NotEqual) return event != event_;
    else return false; 
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string event) {
    bool left = leftNode->Evaluate(date, event);
    bool right = rightNode->Evaluate(date, event);

    if (lop_ == LogicalOperation::And) return left && right;
    else if (lop_ == LogicalOperation::Or) return left || right;
    else return false;
}