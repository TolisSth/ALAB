// Author: Apostolos Chalis 2026 achalis@csd.auth.gr
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <format>    
#include <iomanip>

#include "utils.hpp"

void result_logger(const std::string& kernel_name, const std::string& execution_type, size_t size, double duration, double mflops, double gflops, bool new_file) {
    
    	std::filesystem::create_directories("results/");

    	std::string filename_first_part = "results/ALAB-";
    	std::string filename_num = "0001";
    	std::string file_extension = ".csv";

    	std::string complete_filename = filename_first_part + filename_num + file_extension;

    	if (new_file) {
        	while (std::filesystem::exists(complete_filename)) {
            		int num = std::stoi(filename_num);
            		num++;
            		filename_num = std::format("{:04}", num); 
            
            		complete_filename = filename_first_part + filename_num + file_extension;
        	}
    	}

	bool is_brand_new = !std::filesystem::exists(complete_filename); 

	std::ofstream outfile(complete_filename, std::ios::app); 

	if (outfile.is_open()) {
		if (is_brand_new){
			outfile << "kernel,type,time,mflops,gflops\n"; 
		}

		std::cout << "Writing results to: " << complete_filename << std::endl; 
		outfile << kernel_name << ","
			<< execution_type << ","
			<< size << ","
			<< std::fixed << duration << ","
			<< std::fixed << mflops << ","
			<< std::fixed << gflops << "\n"; 

		outfile.close();
		std::cout<< "Results saved to: " << complete_filename << std::endl;
	} else {
		std::cerr << "ERROR: Could not open: " << complete_filename << std::endl; 
	}
}
