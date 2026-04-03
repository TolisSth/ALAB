// Author: Apostolos Chalis 2026 achalis@csd.auth.gr
#ifndef UTILS_HPP
#define UTILS_HPP

struct Args {
	int num_threads = 1;
	size_t size = 1000; 
};

Args arg_parser(int argc, char* argv[]);

#endif 
