// Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode 
#include "node.h"


bool DateComparisonNode::Evaluate(const Date& date, const std::string event) {
    if (cmp_ == Comparison::Equal) return date_ == date;
    else if (cmp_ == Comparison::Less) return date_ < date;
    else if (cmp_ == Comparison::LessOrEqual)  return date_ < date || date_ == date; //improvement: overload ops
    else if (cmp_ == Comparison::Greater) return date_ > date;
    else if (cmp_ == Comparison::GreaterOrEqual) return date_ > date || date_ == date;
    else if (cmp_ == Comparison::NotEqual) return date_ != date;
    else return false;
}

bool EventComparisonNode::Evaluate(const Date& date, const std::string event) {
     if (cmp_ == Comparison::Equal) return event_ == event; // lexicographic comp 
    else if (cmp_ == Comparison::Less) return event_ < event;
    else if (cmp_ == Comparison::LessOrEqual)  return event_ <= event; //improvement: overload ops
    else if (cmp_ == Comparison::Greater) return event_ > event;
    else if (cmp_ == Comparison::GreaterOrEqual) return event_ >= event;
    else if (cmp_ == Comparison::NotEqual) return event_ != event;
    else return false; 
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string event) {
    bool left = leftNode->Evaluate(date, event);
    bool right = rightNode->Evaluate(date, event);

    if (lop_ == LogicalOperation::And) return left && right;
    else if (lop_ == LogicalOperation::Or) return left || right;
    else return false;
}