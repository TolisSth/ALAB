// Author: Apostolos Chalis 2026 achalis@csd.auth.gr
#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector> 

// Argument parser code
struct Args {
	int num_threads = 1;
	int seed = 42; 
	size_t size = 1000; 
};

Args arg_parser(int argc, char* argv[]);

// Generators code
std::vector<double> generate_vector(size_t size_of_vector, unsigned int seed);

// TODO: Add generate_matrix()


#endif 
