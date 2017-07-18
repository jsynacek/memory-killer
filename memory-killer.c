#include <stdlib.h>

/* gcc memory-killer.c -O0 */

int main() {
	int **leak;
	size_t step = 8 * 1024 * 1024;
	size_t i = 0, s = step;

	leak = malloc(s);
	while (1) {
		if (i >= s) {
			s *= 2;
			leak = realloc(leak, s);
		}

		leak[i] = malloc(step);
		++i;
	}
}
