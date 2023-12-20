#include <stdio.h>

int main(void) {
	int i11, i12, i13, i14;
	int i21, i22, i23, i24;
	int i31, i32, i33, i34;
	int i41, i42, i43, i44;

	printf("Enter the numbers from 1 to 16 in any order:\n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
	      &i11, &i12, &i13, &i14, &i21, &i22, &i23, &i24,
	      &i31, &i32, &i33, &i34, &i41, &i42, &i43, &i44);

	printf("%2d %2d %2d %2d\n", i11, i12, i13, i14);
	printf("%2d %2d %2d %2d\n", i21, i22, i23, i24);
	printf("%2d %2d %2d %2d\n", i31, i32, i33, i34);
	printf("%2d %2d %2d %2d\n", i41, i42, i43, i44);

	printf("Row sums: %2d %2d %2d %2d\n",
	       i11 + i12 + i13 + i14, i21 + i22 + i23 + i24,
	       i31 + i32 + i33 + i34, i41 + i42 + i43 + i44);
	printf("Column sums: %2d %2d %2d %2d\n",
	       i11 + i21 + i31 + i41, i12 + i22 + i32 + i42,
	       i13 + i23 + i33 + i43, i14 + i24 + i34 + i44);
	printf("Diagonal sums: %2d %2d\n",
	       i11 + i22 + i33 + i44, i14 + i23 + i32 + i41);

	return 0;
}
