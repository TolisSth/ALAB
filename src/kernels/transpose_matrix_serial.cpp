// Author: Apostolos Chalis 2026 <achalis@csd.auth.gr> 
#include "kernel_interface.hpp"

void transpose_matrix_serial(const double** original_matrix, double** transpose_matrix, int size_of_matrix) {
	for (int i = 0; i < size_of_matrix; i++) {
			for (int j =0; i < size_of_matrix; j++){
				transpose_matrix[j][i] = original_matrix[i][j];
		}
	}
}

