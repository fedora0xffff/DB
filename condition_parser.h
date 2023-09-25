#pragma once
#include <memory>
#include <iostream>
//#include "token.h"
#include "node.h"

using namespace std;




shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
