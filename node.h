#pragma once
#include "date.h"
#include "condition_parser.h"

// Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode 

class Node {
    public:
    Node() {}; 
    virtual bool Evaluate(const Date& date, const std::string event) = 0;
    virtual ~Node() {}
};

class EmptyNode: public Node {
    public:
    EmptyNode(): Node() {} 
    bool Evaluate(const Date& date, const std::string event){
        return true;
    }
    ~EmptyNode() {}
};

class DateComparisonNode : public Node {
    public:
    DateComparisonNode(Comparison comp, const Date& date) : Node(), cmp_(comp), date_(date) {} //check for errors; no instance of node created directly
    bool Evaluate(const Date& date, const std::string event);
    ~DateComparisonNode() {}
    private:
    Comparison cmp_;
    Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison comp, const std::string& event) : Node(), cmp_(comp), event_(event) {}
    bool Evaluate(const Date& date, const std::string event);
    ~EventComparisonNode() {}
private:
    Comparison cmp_;
    std::string event_;
};

class LogicalOperationNode : public /*DateComparisonNode, EventComparisonNode */ Node{
public:
    LogicalOperationNode(LogicalOperation lo, std::shared_ptr<Node> node1, std::shared_ptr<Node> node2) : 
    Node(), lop_(lo), leftNode(node1), rightNode(node2) {}
    bool Evaluate(const Date& date, const std::string event);
    ~LogicalOperationNode() {}
private:
    LogicalOperation lop_;
    std::shared_ptr<Node> leftNode;
    std::shared_ptr<Node> rightNode;
}