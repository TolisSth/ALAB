// Author: Apostolos Chalis 2026 achalis@csd.auth.gr 
#include <iostream> 
#include <chrono> 

#include "utils.hpp"
#include "kernel_interface.hpp"

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
	
	// DDOT kernel 
	std::cout << "Generating vectors..." << std::endl; 
	std::vector<double> vector1 = generate_vector(args.size, args.seed);
	std::vector<double> vector2 = generate_vector(args.size, args.seed);

	std::cout << "Calculating DDOT..." << std::endl; 
	auto start_of_DDOT = std::chrono::high_resolution_clock::now();
	double DDOT_calc = ddot_serial(vector1.data(), vector2.data(), args.size);
	auto end_of_DDOT = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> dur_of_DDOT = end_of_DDOT - start_of_DDOT;
	std::cout << "Finished DDOT calculation at: (" << std::fixed << std::setprecision(6) << dur_of_DDOT.count() << "s)" << std::endl;

    return EXIT_SUCCESS;
}
