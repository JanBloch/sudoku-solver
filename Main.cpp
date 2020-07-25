#include <stdio.h>
#include <stdlib.h>
#include "print_array.h"
#include "PermissionList.h"
#include <vector>

int testData[9][9] = {
	{1, 0, 0, 0, 0, 6, 8, 3, 0},
	{0, 8, 0, 5, 7, 3, 0, 9, 0},
	{0, 0, 0, 0, 2, 8, 0, 0, 0},
	{0, 7, 0, 3, 0, 1, 9, 8, 0},
	{5, 4, 9, 0, 8, 7, 6, 1, 0},
	{8, 0, 0, 4, 0, 9, 2, 0, 0},
	{0, 0, 0, 0, 0, 2, 3, 0, 0},
	{7, 6, 3, 0, 0, 0, 0, 0, 9},
	{9, 2, 8, 7, 0, 0, 5, 0, 0}
};

int allowedPool[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

bool solved(int data[9][9]) {
	return false;
}
bool filled(int data[9][9], size_t width, size_t height, int empty_value = 0) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (data[i][j] == empty_value)
				return false;
		}
	}
	return true;
}
void solve(int data[9][9], size_t column, size_t row) {
	PermissionList<int> permissionList;
	for (size_t i = 0; i < 9; i++) {
		int val = data[i][row];
		if (val != 0)
			permissionList.deny(val);
	}
	for (size_t i = 0; i < 9; i++) {
		int val = data[column][i];
		if (val != 0)
			permissionList.deny(val);
	}
	int area_x = column / 3;
	int area_y = row / 3;
	int area_x_start = area_x * 3;
	int area_y_start = area_y * 3;
	//printf("Field [%d, %d] in area [%d, %d]\n", column, row, field_x, field_y);
	for (size_t i = area_x_start; i < area_x_start + 3; i++) {
		for (size_t j = area_y_start; j < area_y_start + 3; j++) {
			int val = data[i][j];
			if (val != 0)
				permissionList.deny(val);
		}
	}
	std::vector<int> vec = permissionList.getAllowed<9>(allowedPool);
	if (vec.size() == 1) {
		printf("Solved field [%d, %d]\n", column + 1, row + 1);
		data[column][row] = vec[0];
	}
	if (vec.size() == 0) {
		exit(-1);
	}

}



int main() {
	while (!filled(testData, 9, 9)) {


		print_arr_size<int, 9, 9>(testData);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				//print_arr_size<int, 9, 9>(testData);
				if (testData[i][j] == 0) {
					solve(testData, i, j);
				}
			}
		}
		//print_arr_size<int, 9, 9>(testData);

	}
	//solve(testData, 0, 1);
	print_arr_size<int, 9, 9>(testData);
	return 0;
}

