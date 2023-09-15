#pragma once
#include "date.h"
// Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode 

class Node {
    public:
    Node() {}; //do i need a cstr here?
    virtual bool Evaluate(const Date& date, const std::string event) = 0;
    //virtual ~Node() = 0;
};

class EmptyNode: public Node {
    public:
    EmptyNode() {}
    bool Evaluate(const Date& date, const std::string event){
        return true;
    }
    ~EmptyNode() {}
};

class DateComparisonNode : public Node {
    public:
    DateComparisonNode(Comparison, const Date& date);
    bool Evaluate(const Date& date, const std::string event);
    private:
    Comparison cmp_;
    Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison, const std::string& event);
    bool Evaluate(const Date& date, const std::string event);
private:
    Comparison cmp_;
    Date date_;
};

class LogicalOperationNode : public DateComparisonNode, EventComparisonNode {
public:
    LogicalOperationNode(LogicalOperation, std::shared_ptr<Node> node1, std::shared_ptr<Node> node2);
    bool Evaluate(const Date& date, const std::string event);
private:
    LogicalOperation lop_;
    std::shared_ptr<Node> leftNode;
    std::shared_ptr<Node> rightNode;
}