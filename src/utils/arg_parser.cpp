// Author: Apostolos Chalis 2026 achalis@csd.auth.gr
#include <iostream> 
#include <vector>
#include <string> 

#include "utils.hpp"

Args arg_parser(int argc, char* argv[]) {
	Args args;

	for(int i = 0; i < argc; i++){
		// changing to string to actually compare 
		std::string arg = argv[i]; 

		if (arg == "--size" || arg == "-s"){
			args.size = std::stoi(argv[i+1]);
		}
		else if (arg == "--threads" || arg == "-t"){
			args.num_threads = std::stoi(argv[i+1]);
		}
		else if (arg == "--help" || arg == "-h"){
			std::cout << "Usage: alab [options]\n";
			std::cout << "Options:\n";
			std::cout << "  --size, -s <size>        Set the size (default: 1000)\n";
			std::cout << "  --threads, -t <num>      Set the number of threads (default: 1)\n";
			std::cout << "  --help, -h               Display this help message\n";
			exit(0);
		}
	}

	return args;
}
