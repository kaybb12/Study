#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output(const vector<int>& nums) {
	for (const auto num : nums) {
		cout << num << " ";
	}

	cout << "\n";
}  

void get_bubble_sort_ver1(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = nums.size() - 1; j > i; --j) {
			if (nums[j - 1] > nums[j])
				swap(nums[j - 1], nums[j]);
		}
	}

	output(nums);
}

void get_bubble_sort_ver2(vector<int>& nums) {
	for (int i = nums.size() - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j + 1] < nums[j]) {
				swap(nums[j], nums[j + 1]);
			}
		}
	}

	output(nums);
}

void get_bubble_sort_ver3(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int cnt = 0;

		for (int j = nums.size() - 1; j > i; --j) {
			if (nums[j - 1] > nums[j]) {
				swap(nums[j - 1], nums[j]);
				++cnt;
			}
		}

		if (cnt == 0)
			break;
	}

	output(nums);
}

void get_bubble_sort_ver4(vector<int>& nums) {
	int cnt = 0;
	while (cnt < nums.size() - 1) {
		int last = nums.size() - 1;

		for (int j = nums.size() - 1; j > cnt; --j) {
			if (nums[j - 1] > nums[j]) {
				swap(nums[j - 1], nums[j]);
				last = j;
			}
		}
		cnt = last;
	}

	output(nums);
}

void get_cell_sort(vector<int>& nums) {
	for (int h = (nums.size() - 1) / 2; h > 0; h /= 2) {
		for (int i = h; i < nums.size() - 1; ++i) {
			int j;
			int temp = nums[i];
			for (j = i - h; j >= 0 && nums[j] > temp; j -= h) {
				nums[j + h] = nums[j];
			}
			nums [j + h] = temp;
 		}
	}

	output(nums);
}

int partition(vector<int>& nums, int low, int high) {
	int pivot = nums[high];
	int i = (low - 1);

	for (int j = low; j < high; ++j) {
		if (nums[j] <= pivot) {
			++i;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i + 1], nums[high]);

	return (i + 1);
}

void get_quick_sort(vector<int>& nums, int low, int high) {
	if (low < high) {
		int pi = partition(nums, low, high);

		get_quick_sort(nums, low, pi - 1);
		get_quick_sort(nums, pi + 1, high);
	}

}

void get_fsort(vector<int>& nums) {
	int max = *max_element(nums.begin(), nums.end());
	vector<int> f(max + 1);
	vector<int> b(nums.size());

	for (int i = 0; i < nums.size(); ++i)
		++f[nums[i]];
	for (int i = 1; i <= max; ++i)
		f[i] += f[i - 1];
	for (int i = nums.size() - 1; i >= 0; --i)
		b[--f[nums[i]]] = nums[i];
	for (int i = 0; i < nums.size(); ++i)
		nums[i] = b[i];
}

int main() {
	vector<int> nums(9);

	for (int i = 0; i < 9; ++i) {
		cin >> nums[i];
	}

	//get_bubble_sort_ver1(nums);
	//get_bubble_sort_ver2(nums);
	//get_bubble_sort_ver3(nums);
	//get_bubble_sort_ver4(nums);
	//get_cell_sort(nums);
	//get_quick_sort(nums, 0, nums.size() - 1);
	get_fsort(nums);

	output(nums);

	return 0;
}