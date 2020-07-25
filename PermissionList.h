#pragma once
#include <vector>

template <typename T>
class PermissionList {
private:
	std::vector<T> denied;

public:
	void allow(T value) {
		auto find = std::find(denied.begin(), denied.end(), value);
		if (find != denied.end())
			denied.erase(denied.begin() + find);
	}

	void deny(T value) {
		auto find = std::find(denied.begin(), denied.end(), value);
		if (find == denied.end())
			denied.push_back(value);
	}

	bool allowed(T value) {
		return std::find(denied.begin(), denied.end(), value) == denied.end();
	}

	std::vector<T> getAllowed(T* pool, size_t pool_size) {
		std::vector<T> out;
		for (int i = 0; i < pool_size; i++) {
			if (allowed(pool[i]))
				out.push_back(pool[i]);
		}
		return out;
	}
	template <int pool_size> std::vector<T> getAllowed(T pool[pool_size]) {
		std::vector<T> out;
		for (int i = 0; i < pool_size; i++) {
			if (allowed(pool[i]))
				out.push_back(pool[i]);
		}
		return out;
	}
	std::vector<T> getDenied() {
		return denied;
	}
};
