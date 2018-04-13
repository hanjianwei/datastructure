#include "sparse_matrix.h"

int sparse_matrix_item_position_compare(struct Item *lhs, struct Item *rhs) {
	
	if (lhs->row == rhs->row) {
		return lhs->col - rhs->col;
	} else {
		return lhs->row -rhs->row;
	}
}
