
#include <stdio.h>
#include <inttypes.h>

int64_t pentag[1000002];

void init() {
	for (int64_t n = 0; n <= 1000001; n++)
		pentag[n] = (n + 1)*(3 * n + 2) / 2;
}


int low_bound(int64_t value, int64_t arr[], int n) {
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) >> 1;
		if (arr[mid] >= value)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

int main()
{
	init();

	int n = 100000;

	int64_t dmin = 100000000ll;
	for (int k = 1; k < 9999; k++) {
		for (int i = k+1; i < n; i++) {
			int64_t pn = pentag[i];
			int64_t pnk = pentag[i - k];
			int64_t psearch = pn + pnk;
			int j = low_bound(psearch, pentag, 1000000);
			if (pentag[j] == psearch) {
				psearch = pn - pnk;
				j = low_bound(psearch, pentag, 1000000);
				if (pentag[j] == psearch) {
					printf("%" PRId64 "\n", psearch);
					break;
				}
			}

		}
	}
	

	return 0;
}
