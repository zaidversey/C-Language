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

    turtle_goto(&boo, 250, 300);
    set_pen_colour(&pen, random_colour(c));
    turtle_polygon(&boo, &pen, 8, 100);
    fprintf(stdout, "stroke\n");

    turtle_goto(&boo, 260, 322);
    set_pen_filled(&pen);
    turtle_polygon(&boo, &pen, 8, 80);
    fprintf(stdout, "stroke\n");

    set_ps_display();

    return 0;
}
