# include "turtle_B.h"
/*************************************************************************
 MAIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**************************************************************************/
int main( void ) {

    turtle_t boo;
    pen_t pen;
    srand( time( NULL ) );

    turtle_reset( &boo  );
    pen_reset( &pen );

    set_ps_header(WIDTH, HEIGHT);
    turtle_goto(&boo, 300, 400);
    turtle_fractal(&boo, &pen, 360, 100, 2, 6);
    set_ps_display();

    return 0;
}
