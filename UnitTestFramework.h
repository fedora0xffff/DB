#pragma once

#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include "date.h"

namespace std {
    //interface 
    template<class T, class U>
    void AssertEqual(const T& t, const U& u, const string& hint);
    
    template <class T>
    ostream& operator << (ostream& os, const set<T>& s);
    template <class K, class V>
    ostream& operator << (ostream& os, const map<K, V>& m);
    template <class K, class V>
    ostream& operator << (ostream& os, const unordered_map<K, V>& m);
    template <typename Collection>
    std::string Join(const Collection& collection, char delim);

    //impl

    template <class T>
    ostream& operator << (ostream& os, const set<T>& s) {
        os << "{";
        bool first = true;
        for (const auto& x : s) {
            if (!first) {
                os << ", ";
            }
            first = false;
            os << x;
        }
        return os << "}";
    }

    template <class K, class V>
    ostream& operator << (ostream& os, const map<K, V>& m) {
        os << "{";
        bool first = true;
        for (const auto& kv : m) {
            if (!first) {
                os << ", ";
            }
            first = false;
            os << kv.first << ": " << kv.second;
        }
        return os << "}";
    }

    template <class K>
    ostream& operator << (ostream& os, const vector<K>& vec) {
        os << "[";
        bool first = true;
        for (const auto& elem : vec) {
            if (!first) {
                os << ", ";
            }
            first = false;
            os << elem ;
        }
        return os << "]";
    }

    template <class K, class V>
    ostream& operator << (ostream& os, const unordered_map<K, V>& m) {
        os << "{";
        bool first = true;
        for (const auto& kv : m) {
            if (!first) {
                os << ", ";
            }
            first = false;
            os << kv.first << ": " << kv.second;
        }
        return os << "}";
    }

    template<class T, class U>
    void AssertEqual(const T& t, const U& u,
        const string& hint)
    {
        if (t != u) {
            ostringstream os;
            os << "Assertion failed: " << t << " != " << u
                << " hint: " << hint;
            throw runtime_error(os.str());
        }
    }

    inline void Assert(bool b, const string& hint) { //must be true
        AssertEqual(b, true, hint);

    } 

    class TestRunner {
    public:
        template <class TestFunc>
        void RunTest(TestFunc func, const string& test_name) {
            try {
                func();
                cerr << test_name << " OK" << endl;
            }
            catch (runtime_error& e) {
                ++fail_count;
                cerr << test_name << " fail: " << e.what() << endl;
            }
        }
        ~TestRunner();
    private:
        int fail_count = 0;
    };

    template <typename Collection>
    std::string Join(const Collection& collection, char delim)
    {
        std::stringstream ss;
        bool first = true;
        int ctr = 0;
        for (const auto& i : collection)
        {
            if (!first)
            {
               // ss << " (" << ctr << ") " << delim;
                ss << delim;
            }
            first = false;
           // ss << " (" << ctr << ") " << i;
            ss << i;
            ++ctr;
        }
        return ss.str();
    }

 
    /*template <typename First, typename Second>
    std::ostream& operator << (std::ostream& out, const std::pair<First, Second>& p) {
        return out << '(' << p.first << ',' << p.second << ')';
    }

    template <typename T>
    std::ostream& operator << (std::ostream& out, const std::vector<T>& vi) {
        return out << '[' << Join(vi, ',') << ']';
    }

    template <typename Key, typename Value>
    std::ostream& operator << (std::ostream& out, const std::map<Key, Value>& m) {
        return out << '{' << Join(m, ',') << '}';
    }*/
}
