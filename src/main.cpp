// Author: Apostolos Chalis 2026 achalis@csd.auth.gr 
#include <iostream> 
#include <chrono> 
#include <iomanip>

#include "utils.hpp"
#include "kernel_interface.hpp"

int main(int argc, char* argv[]) {
	Args args = arg_parser(argc, argv);	
	std::cout << "ALAB | Another Linear Algebra Benchmark\nApostolos Chalis 2026 <achalis@csd.auth.gr>" << std::endl;

	if (args.serial) {	
		// DDOT kernel (serial)
		std::cout << "Generating vectors..." << std::endl; 
		std::vector<double> vector1 = generate_vector(args.size, args.seed);
		std::vector<double> vector2 = generate_vector(args.size, args.seed + args.size);

		std::cout << "Calculating DDOT (serial)..." << std::endl; 
		auto start_of_DDOT = std::chrono::high_resolution_clock::now();
		double DDOT_calc = ddot_serial(vector1.data(), vector2.data(), args.size);
		auto end_of_DDOT = std::chrono::high_resolution_clock::now();
		
		// Time calculation and output
		std::chrono::duration<double> dur_of_DDOT = end_of_DDOT - start_of_DDOT;
		std::cout << "Finished DDOT (serial) calculation at: (" << std::fixed << std::setprecision(6) << dur_of_DDOT.count() << "s)" << std::endl;

		// MFLOPS & GFLOPS calculation and output
		double mflops = (2.0 * args.size) / (dur_of_DDOT.count() * 1e6);
		double gflops = mflops / 1e3;
		std::cout << "DDOT Performance (serial): " << std::fixed << std::setprecision(2) << mflops << " MFLOPS (" << std::fixed << std::setprecision(2) << gflops << " GFLOPS)" << std::endl;
	}
	else if (args.parallel) {
		// DDOT kernel (parallel)
		std::cout << "Generating vectors..." << std::endl; 
		std::vector<double> vector1 = generate_vector(args.size, args.seed);
		std::vector<double> vector2 = generate_vector(args.size, args.seed + args.size);

		std::cout << "Calculating DDOT (parallel)..." << std::endl; 
		auto start_of_DDOT = std::chrono::high_resolution_clock::now();
		double DDOT_calc = ddot_parallel(vector1.data(), vector2.data(), args.size);
		auto end_of_DDOT = std::chrono::high_resolution_clock::now();
		
		// Time calculation and output
		std::chrono::duration<double> dur_of_DDOT = end_of_DDOT - start_of_DDOT;
		std::cout << "Finished DDOT (parallel) calculation at: (" << std::fixed << std::setprecision(6) << dur_of_DDOT.count() << "s)" << std::endl;

		// MFLOPS & GFLOPS calculation and output
		double mflops = (2.0 * args.size) / (dur_of_DDOT.count() * 1e6);
		double gflops = mflops / 1e3;
		std::cout << "DDOT Performance (parallel): " << std::fixed << std::setprecision(2) << mflops << " MFLOPS (" << std::fixed << std::setprecision(2) << gflops << " GFLOPS)" << std::endl;
	}

    return EXIT_SUCCESS;
}
