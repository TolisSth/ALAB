// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr>
#include "kernel_interface.hpp"

#include <omp.h>
#include <cstddef>

double ddot_parallel(const double* vector1, const double* vector2, std::size_t size_of_vector ){
	double sum = 0.0; 

    	#pragma omp parallel for reduction(+:sum)
    	for (std::size_t i = 0; i < size_of_vector; i++) {
        	sum += vector1[i] * vector2[i];
    	}

    	return sum; 
}
