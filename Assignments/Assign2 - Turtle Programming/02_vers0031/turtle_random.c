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
    turtle_random_walk(&boo,&pen, 800000);
    set_ps_display();

    return 0;
}
