#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct frame {
	char b1, b2;
	int ball1, ball2, score;
};

int ball_roll(int pins)
{
	return( rand() % (pins + 1) );
}

void fill_frame(struct frame *f)
{
	f->ball1 = ball_roll(10);

	if( f->ball1==10 )
	{
		f->b1 = ' ';
		f->b2 = 'X';
		f->ball2 = 0;
		f->score = 10;
	}
	else
	{
		f->b1 = f->ball1 ? f->ball1+'0' : '-';
		f->ball2 = ball_roll(10-f->ball1);
		if( f->ball1+f->ball2==10 )
			f->b2 = '/';
		else
			f->b2 = f->ball2 ? f->ball2+'0' : '-';
		f->score = f->ball1+f->ball2;
	}
}

int main()
{
	struct frame game;

	srand( (unsigned)time(NULL) );

	fill_frame(&game);
	printf("| %c|%c|\n",game.b1,game.b2);
	printf("|%3d |\n",game.score);

	return(0);
}
