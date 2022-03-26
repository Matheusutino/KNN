#pragma once

#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Element{
    private:
        string className;
        vector<float> features;
    
    public:
        Element(string, vector<float>);
        vector<float> getFeatures();
        string getClass();
};
