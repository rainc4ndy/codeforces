#include <cstdio>
#include <cstring>

int main() {
	int rows = 0; //总行数
	char cache[1001]; // +1 给 \n

	scanf("%d", &rows);
	getchar();
	scanf("%[^\n]", &cache);

	int len = strlen(cache); 
	int columns = (len / rows); //总列数
	if (((float)len / (float)rows) - (len / rows) != 0)
		columns++;

	char **all = new char*[rows];
	for (int i = 0; i < rows; i++)
		all[i] = new char[columns];
	
	int ci = 0;

	int current_row = 1;
	int current_column = columns;
	while (true) {
		if (ci < len) {
			//还要-1给引索
			all[current_row - 1][current_column - 1] = cache[ci];
			ci++;
		}
		else {
			all[current_row - 1][current_column - 1] = ' ';
		}
		current_row++;
		if (current_row > rows) {
			current_row = 1;
			current_column--;
		}
		if (current_column == 0)
			break;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%c", all[i][j]);
		}
		putchar('\n');
		delete[] all[i];
	}
	delete[] all;
	return 0;
}