#include <iostream>
#include <fstream>
#include "element.hpp"
#include "utils.hpp"

using namespace std;

//K-nearest neighbor algorithm

int main(){
    vector<Element> elements;

	ifstream infile;
	infile.open("dataset.txt", ios::in);

	float a,b,c,d;
	string nameClass;

	int count = 0;
	int K = 3;
	int len_train = 60;

	while (infile >> a >> b >> c >> d >> nameClass && count < len_train){
		vector<float> values;
		values.push_back(a);
		values.push_back(b);
		values.push_back(c);
		values.push_back(d);
		elements.push_back(Element(nameClass,values));
		count++;
		cout << values[0] << " " << values[1] << " " << values[2] << " " << values[3] << " " << nameClass << " " << endl;
	}
	
	int acc = 0;
	int len_test = 150 - len_train;
	count = 0;

	// Classifying process
		
	while (infile >> a >> b >> c >> d >> nameClass){
		vector<float> values;

		values.push_back(a);
		values.push_back(b);
		values.push_back(c);
		values.push_back(d);

		count++;

		cout << values[0] << " " << values[1] << " " << values[2] << " " << values[3] << " " << nameClass << " " << endl;
	

		string class_predict = KNN(K, values, elements);
		
		cout << "Class expected: " << nameClass << "\n";
		cout << "Class predict: " << class_predict << "\n\n";
		
		if(nameClass == class_predict)
			acc++;
	}
	
	cout << acc << " Acc of a total " << len_test << " of tests.\n";

	infile.close();

	return 0;
}