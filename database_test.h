#pragma once
#include "UnitTestFramework.h"

void TestDB();
std::function<bool(Date, std::string)> predicatFather(std::shared_ptr<Node> root);