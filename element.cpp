#include "element.hpp"


Element::Element(string className, vector<float> features){
    this->className = className;
    this->features = features;
}

vector<float> Element::getFeatures(){
    return features;
}

string Element::getClass(){
    return className;
}
