// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr> 
#include <catch2/catch_all.hpp>

#include "kernel_interface.hpp"

TEST_CASE("DOT Product (parallel) math are correct", "[ddot_parallel]") {
	std::vector<double> first_vector = {1.0, 2.0, 3.0};
	std::vector<double> second_vector = {4.0, 5.0, 6.0}; 

	double result = ddot_parallel(first_vector.data(), second_vector.data(), 3);
	
	REQUIRE(result == 32.0);
}
