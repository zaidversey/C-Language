# include "turtle_B.h"
/*************************************************************************
 MAIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**************************************************************************/
int main( void ) {

    turtle_t boo;
    pen_t pen;
    colour_t c;
    srand( time( NULL ) );

    turtle_reset( &boo  );
    pen_reset( &pen );

    set_ps_header(WIDTH, HEIGHT);
    turtle_goto(&boo, 100, 400);
    set_pen_colour(&pen, random_colour(c));
    turtle_row(&boo, 10, 30);
    set_ps_display();

    return 0;
}
