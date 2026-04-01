// midIndex为左区间最后一个元素下标
void merge(std::vector<int>& inputs, int startIndex, int midIndex, int endIndex) {
	int i = startIndex, j = midIndex + 1, k = 0;
	std::vector<int> temp(endIndex - startIndex + 1, 0);
	while (i <= midIndex && j <= endIndex) {
		if (inputs[i] <= inputs[j]) {
			temp[k++] = inputs[i++];
		}
		else {
			temp[k++] = inputs[j++];
		}
	}
	while (i <= midIndex) {
		temp[k++] = inputs[i++];
	}
	while (j <= endIndex) {
		temp[k++] = inputs[j++];
	}
	for (i = startIndex, k = 0; i <= endIndex; ++i, ++k) {
		inputs[i] = temp[k];
	}
}

void mergeSort(std::vector<int>& inputs, int startIndex, int endIndex) {
	if (startIndex >= endIndex) {
		return;
	}
	int mid = startIndex + (endIndex - startIndex) / 2;
	mergeSort(inputs, startIndex, mid);
	mergeSort(inputs, mid + 1, endIndex);
	merge(inputs, startIndex, mid, endIndex);
}