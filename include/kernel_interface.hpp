// Author: Apostolos Chalis 2026 achalis@csd.auth.gr
#ifndef KERNEL_INTERFACE_HPP
#define KERNEL_INTERFACE_HPP

#include <cstddef> 

// Having to pass the vector happens because I choose to pass the vectors address and not the object
double ddot_serial(const double* vector1, const double* vector2, std::size_t size_of_vectors);


#endif 
