// Author: Apostolos Chalis 2026 achalis@csd.auth.gr 
#include <random> // Chose this because of non-determinism
#include <vector> 

#include "utils.hpp"

std::vector<double> generate_vector (size_t size_of_vector, unsigned int seed){
	std::vector<double> v(size_of_vector); 
	std::mt19937 gen(seed); // Use the seed provided by the user
    	std::uniform_real_distribution<double> dist(0.0, 1.0);

    	for (size_t i = 0; i < size_of_vector; ++i) {
        	v[i] = dist(gen);
    	}
    	
	return v;	
}
