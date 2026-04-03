// Author: Apostolos Chalis 2026 achalis@csd.auth.gr 
#include <iostream> 

#include "utils.hpp"

int main(int argc, char* argv[]) {
	Args args = arg_parser(argc, argv);	

	/*
	 * DEBUG CODE TODO: Move this code in a debug mode thingy
	std::cout << args.size << " " << args.num_threads << " " << args.seed << " " << std::endl; 

	std::vector<double> x = generate_vector(args.size, args.seed); 

	for (double element : x) {
        	std::cout << element << " ";
    	}
	*/	

    	std::cout << "ALAB | Another Linear Algebra Benchmark\nApostolos Chalis 2026 <achalis@csd.auth.gr>" << std::endl;
    return 0;
}
