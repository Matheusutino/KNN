#pragma once

#include "element.hpp"

float euclideanDistance(vector<float> v1, vector<float> v2){
    float sum = 0.0;
    for(int i = 0; i < v1.size(); i++)
        sum += pow((v1[i] - v2[i]), 2);

    return sqrt(sum);
}

string getMostFrequentElement(vector<string> &arr)
{
    if (arr.empty())
        return "Empty";

    sort(arr.begin(), arr.end());

    auto last_int = arr.front();
    auto most_freq_int = arr.front();
    int max_freq = 0, current_freq = 0;

    for (const auto &i : arr) {
        if (i == last_int)
            ++current_freq;
        else {
            if (current_freq > max_freq) {
                max_freq = current_freq;
                most_freq_int = last_int;
            }

            last_int = i;
            current_freq = 1;
        }
    }

    if (current_freq > max_freq) {
        max_freq = current_freq;
        most_freq_int = last_int;
    }

    return most_freq_int;
}

string KNN(int K, vector<float> feature, vector<Element> data){
    vector<pair <float, string>> distance;

    for(int i = 0; i < data.size(); i++){
        distance.push_back(make_pair(euclideanDistance(feature, data[i].getFeatures()), data[i].getClass()));
    }
    sort(distance.begin(), distance.end());

    vector<string> kElements;

    for(int i = 0; i < K; i++){
        kElements.push_back(distance[i].second);
    }

    return getMostFrequentElement(kElements);
}