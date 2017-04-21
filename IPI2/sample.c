#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/times.h>
#include <termios.h>
#include <unistd.h>

const int H=10, L=10;


int readKey(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

void init(char board[H][L], int H, int L) {
	int i,j;
	for(i=0;i<H;i++) {
		for(j=0;j<L;j++) {
			board[i][j]=' ';
		}
	}
		
}

void display(char board[H][L], int H, int L) {
	int i,j;
	system("clear");
	for(i=0;i<H;i++) {
		for(j=0;j<L;j++) {
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int go=1;
	int px=L/2, py=H/2;
	char b[H][L], c;
	init(b,H,L);
	b[py][px]='#';
	while (go) {
		display(b,H,L);
		c=readKey();
		b[py][px]=' ';
		switch (c) {
			case 'x':
			case 66:
				py = py+1; if (py==H) py = 0;
				break;
			case 'e':
			case 65:
				py = py-1; if (py<0) py = H-1;
				break;
			case 'd':
			case 67:
				px = px+1; if (px==L) px = 0;
				break;
			case 's':
			case 68:
				px = px-1; if (px<0) px = L-1;
				break;
			case 'q':
				go=0;
				break;
			default:
				break;
		}
		b[py][px]='#';
	}
	return EXIT_SUCCESS;
}
