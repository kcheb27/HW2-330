#include "countOOO.h"
// your includes here

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


void MergeSortedIntervals(std::vector<int>& v, int s, int m, int e,int & OOO) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	std::vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
            OOO = OOO + 1 + (1*(m-i));
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(std::vector<int>& v, int s, int e,int & OOO) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m,OOO);
		MergeSort(v, m + 1, e,OOO);
		MergeSortedIntervals(v, s, m, e,OOO);
	}
}



// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB) {

	// your implementation goes here
//variable init
std::vector<int> temp;
int s = rankedListB.size();
int val;
int result = 0;
//take vector rankedListA and assign numerical values to each string using a hashmap
std::unordered_map<string, int> value_table;
    for(int i = 0; i < s; i++){
        value_table[rankedListA[i]] = i;
    }
/// take the second vector and create a new vector that has the integer values replacing the strings
    for(int i = 0; i < s; i++){
        val = value_table.at(rankedListB[i]);
        temp.push_back(val);
    }
MergeSort(temp,0,(s-1),result);
	return result; // don't forget to change this
}

/*
int main(){
    std::vector<string> in1 {"a","b","c"};
    std::vector<string> in2 {"b","c","a"};
    int result = countOOO(in1,in2);
    std::cout<<result;
}
*/