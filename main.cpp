#include <stdio.h>
#include <stdint.h>

uint32_t ntohl(uint32_t netlong);

int main(int argc, char** argv) {
	
	FILE* fp1;
	FILE* fp2;
	uint32_t num1;
	uint32_t num2;
	
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");

	fread(&num1, 4, 4, fp1);
	fread(&num2, 4, 4, fp2);

	fclose(fp1);
	fclose(fp2);

	num1 = ntohl(num1);
	num2 = ntohl(num2);

	printf("%d + %d = %d\n", num1, num2, num1 + num2);
}


uint32_t ntohl(uint32_t netlong) {

	uint32_t tmp1, tmp2, tmp3, tmp4;

	tmp1 = netlong & 0xff000000;
	tmp2 = netlong & 0x00ff0000;
	tmp3 = netlong & 0x0000ff00;
	tmp4 = netlong & 0x000000ff;

	tmp1 = tmp1 >> 24;
	tmp2 = tmp2 >> 8;
	tmp3 = tmp3 << 8;
	tmp4 = tmp4 << 24;

	return tmp1 | tmp2 | tmp3 | tmp4;
}










