#include <stdio.h>

int main(int argc, char **argv)
{
	
	printf("          A=>B = !A||B\n");
	printf("    __________________________\n");
	printf("   |     |     |      |       |\n");
	printf("   |  A  |  B  |  !A  | !A||B |\n");
	printf("   |_____|_____|______|_______|\n");
	printf("   |     |     |      |       |\n");
	printf("   |  0  |  0  |   1  |   1   |\n");
	printf("   |_____|_____|______|_______|\n");
	printf("   |     |     |      |       |\n");
	printf("   |  0  |  1  |   1  |   1   |\n");
	printf("   |_____|_____|______|_______|\n");
	printf("   |     |     |      |       |\n");
	printf("   |  1  |  0  |   0  |   0   |\n");
	printf("   |_____|_____|______|_______|\n");
	printf("   |     |     |      |       |\n");
	printf("   |  1  |  1  |   0  |   1   |\n");
	printf("   |_____|_____|______|_______|\n");
	printf("    \n");
	printf("    \n");
	printf("                   A<=>B = A&&B || !A&&!B\n");
	printf("    ________________________________________________________\n");
	printf("   |     |     |      |      |      |        |              |\n");
	printf("   |  A  |  B  |  !A  |  !B  | A&&B | !A&&!B | A&&B||!A&&!B |\n");
	printf("   |_____|_____|______|______|______|________|______________|\n");
	printf("   |     |     |      |      |      |        |              |\n");
	printf("   |  0  |  0  |   1  |   1  |   0  |    1   |      1       |\n");
	printf("   |_____|_____|______|______|______|________|______________|\n");
	printf("   |     |     |      |      |      |        |              |\n");
	printf("   |  0  |  1  |   1  |   0  |   0  |    0   |      0       |\n");
	printf("   |_____|_____|______|______|______|________|______________|\n");
	printf("   |     |     |      |      |      |        |              |\n");
	printf("   |  1  |  0  |   0  |   1  |   0  |    0   |      0       |\n");
	printf("   |_____|_____|______|______|______|________|______________|\n");
	printf("   |     |     |      |      |      |        |              |\n");
	printf("   |  1  |  1  |   0  |   0  |   1  |    0   |      1       |\n");
	printf("   |_____|_____|______|______|______|________|______________|\n");
	
	return 0;
}
