#pragma once
#include <stdio.h>

template <typename T>
void print_arr(T** data, size_t width, size_t height, const char* format_str = "%d") {
	printf("%s\n", "{");
	for (size_t i = 0; i < width; i++) {
		printf("%s", "{");
		for (size_t j = 0; j < height; j++) {
			if (j < height - 1)
				printf("%s", ", ");
			printf(format_str, data[i][j]);
		}
		printf("%s", "}");
		if (i < height - 1)
			printf("%s", ", ");

	}
	printf("\n%s", "}");
}
template <typename T, size_t width, size_t height>
void print_arr_size(T data[width][height], const char* format_str = "%d") {
	printf("%s\n", "{");
	for (size_t i = 0; i < width; i++) {
		printf("\t%s", "{");
		for (size_t j = 0; j < height; j++) {
			printf(format_str, data[i][j]);
			if (j < height - 1)
				printf("%s", ", ");
		}
		printf("%s", "}");
		if (i < height - 1)
			printf("%s\n", ",");

	}
	printf("\n%s", "}");
}