#include <future>
#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <algorithm>


std::vector<int> random_vector(int size){
  std::vector<int> v(size);
  std::generate(v.begin(), v.end(), std::rand);
}

int main(){
  std::vector<std::future<std::vector<int>>> r;
  r.push_back(std::async(random_vector, 10));
  r.push_back(std::async(random_vector, 200));
  r.push_back(std::async(random_vector, 3000));
  
  std::vector<int> current;
  
  for(auto &rn :  r){
    for(int i = 0; i < 10; i++){
      std::cout << "_";
    }
    std::cout << std::endl;
    current = rn.get();
    std::cout << "Random vector of integers of length: " << current.size() << std::endl;
    for(auto &i : current){
      std::cout << "Element value: " << i << ". " << std::endl;
    }
    for(int i = 0; i < 10; i++){
      std::cout << "_";
    }
    std::cout << std::endl;
  }
}