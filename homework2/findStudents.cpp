#include <vector>
#include<algorithm>
#include<iterator>
#include<iostream>




// implement a modified version of merge sort where instead 
// of comparing by size you compare by mod 330 results
//used https://www.geeksforgeeks.org/merge-sort/ as reference
std::vector<int> findStudents(std::vector<int> id){
  if (id.size() <= 1)
        return id;
    
    std::vector<int> firsthalf,secondhalf;
    firsthalf.insert(firsthalf.begin(), id.begin(),id.end()- (id.size()/2));
    secondhalf.insert(secondhalf.begin(), id.begin() + ((id.size() + 1) /2), id.end());
    return merge(findStudents(firsthalf),findStudents(secondhalf));
    
}

std::vector<int> merge(std::vector<int> first, std::vector<int> second){
    std::vector<int> merged;
    


}

int main(){
    std::vector<int> vec1{1,2,3,4,5,6,7,8,9,10,11,12,13};

    findStudents(vec1);
}