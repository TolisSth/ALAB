// Author: Apostolos Chalis 2026 achalis@csd.auth.gr
#include <iostream> 
#include <vector>
#include <string> 

#include "utils.hpp"

Args arg_parser(int argc, char* argv[]) {
	Args args;

	for(int i = 1; i < argc; i++){
		// changing to string to actually compare 
		std::string arg = argv[i]; 

		if (arg == "--size" || arg == "-s"){
			args.size = std::stoi(argv[i+1]);
		}
		else if (arg == "--threads" || arg == "-t"){
			args.num_threads = std::stoull(argv[i+1]);
		}
		else if (arg == "--seed" || arg == "-sd"){
			args.seed = std::stoi(argv[i+1]);
		}
		else if(arg == "--serial"){
			args.serial = true; 
			args.parallel = false; 
		}
		else if (arg == "--parallel"){
			args.parallel = true; 
			args.serial = false; 
		}
		else if (arg == "--help" || arg == "-h"){
			std::cout << "Usage: alab [options]\n";
			std::cout << "Options:\n";
			std::cout << "  --size, -s <size>        Set the size (default: 1000)\n";
			std::cout << "  --threads, -t <num>      Set the number of threads (default: 2)\n";
			std::cout << "  --seed, -sd <seed>         Set the random seed (default: 42)\n";
			std::cout << "  --help, -h               Display this help message\n";
			std::cout << "  --serial                 Run the serial version of the benchmark (default)\n";
			std::cout << "  --parallel               Run the parallel version of the benchmark (please specify number of thread or else it will run in two threads)\n";
			exit(0);
		}
	}

	return args;
}
