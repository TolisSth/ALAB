// Author: Apostolos Chalis 2026 achalis@csd.auth.gr
#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector> 

// Infrastructure utilities code
struct Args {
	int num_threads = 2;
	int seed = 42; 
	size_t size = 1000; 
	bool serial = true; 
	bool parallel = false; 
	bool save_to_file = false; 
	bool save_to_new_file = false; 

};
Args arg_parser(int argc, char* argv[]);

// result logger code
void result_logger(const std::string& kernel_name, const std::string& execution_type, size_t size, double duration, double mflops, double gflops, bool new_file);

// Generators code
std::vector<double> generate_vector(size_t size_of_vector, unsigned int seed);
// TODO: Add generate_matrix()


#endif 
