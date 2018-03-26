
/*************************************************************************
 Preprocessor Statements
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define HEIGHT 841
#define WIDTH 595
#define MAXANGLE 360
#define MINANGLE 0
#define PI 3.14159

/*************************************************************************
 Structure Definitions
**************************************************************************/
/*
 * colour_t contains information about the pen colour
 * r,g,b are a number between  [ 0 – 1 ] inclusive
 */
typedef struct colour {
    float r, g, b;
} colour_t;

/*
* Keeps track of the turtle position in the plane
* ( x, y ) * and its direction ( as an angle )
*/
typedef struct turtle {
    double x, y, dir;
} turtle_t;

/*
 * Keeps track of the pen's colour if the pen is down (TRUE) always
 * and if its drawing a filled object
 */
typedef struct pen {
    colour_t colour;
    int down, filled;
} pen_t;

/*************************************************************************
 Function Prototypes
**************************************************************************/
void set_ps_header(int w, int h);
void set_ps_display();
int process_commands(turtle_t *t, pen_t *p);
void turtle_reset (turtle_t *t);
void pen_reset (pen_t *p);
void set_pen_colour( pen_t *p, colour_t c );
void set_pen_filled(pen_t *p);
int valid_colour(colour_t c);
void turtle_goto( turtle_t *t, float x, float y );
void turtle_square( turtle_t *t, int size );
void turtle_turn( turtle_t *t, float angle );
void turtle_walk( turtle_t *t, int d );
void turtle_row(turtle_t *t, int count, int size);
void turtle_polygon(turtle_t *t, pen_t *p, int sides, int size);
void turtle_grid(turtle_t *t, int rows, int columns, int size);
int roll_dice( void );
void turtle_random_walk(turtle_t *t, pen_t *p, int steps);
void turtle_fractal(turtle_t *t, pen_t *p, int sides, int size, float angle, int count);
colour_t random_colour(colour_t c);

/*************************************************************************
 postscript Header and Footer
**************************************************************************/

void set_ps_header(int w, int h) {
	fprintf(stdout, "%%!PS-Adobe-3.0 EPSF-3.0\n");
	fprintf(stdout, "%%%%BoundingBox: 0 0 %d %d\n\n", w, h);

	return;
}

void set_ps_display(){
	fprintf(stdout, "showpage\n");
	return;
}

/*************************************************************************
 Process commands
**************************************************************************/
int process_commands(turtle_t *t, pen_t *p) {
    char cmd;
    colour_t c;
    float x, y, angle;
    int size, d, count, sides, row, columns, steps;

    while((fscanf(stdin, "%c",&cmd)) != EOF ){
        switch ( cmd ) {
            case 'C':
                fscanf( stdin, "%f %f %f\n", &c.r, &c.g, &c.b );
                if ( valid_colour( c ) == 1 )
                    set_pen_colour( p, c );
                break;

            case 'F':
                set_pen_filled(p);
                break;

            case 'G':
                fscanf( stdin, "%f %f\n", &x, &y );
                turtle_goto( t, x, y );
                break;

            case 'S':
                fscanf(stdin, "%d\n", &size );
                turtle_square(t, size);
                break;

            case 'T':
                fscanf (stdin, "%f\n", &angle);
                turtle_turn(t, angle);
                break;

            case 'W':
                fscanf(stdin, "%d\n", &d);
                turtle_walk(t, d);
                fprintf(stdout, "stroke\n");
                break;

            case 'R':
                fscanf(stdin,"%d %d\n", &count, &size);
                turtle_row(t, count, size);
                break;

            case 'P':
                fscanf(stdin, "%d %d\n", &sides, &size);
                turtle_polygon(t, p, sides, size);
                fprintf(stdout, "stroke\n");
                break;

            case 'M':
                fscanf(stdin,"%d %d %d\n", &row, &columns, &size);
                turtle_grid(t, row, columns, size);
                break;

            case 'Z':
                fscanf(stdin,"%d\n", &steps);
                turtle_random_walk(t, p, steps);
                break;

            case 'X':
                fscanf(stdin,"%d %d %f %d\n",&sides, &size, &angle, &count);
                turtle_fractal(t, p, sides, size, angle, count);
                fprintf(stdout, "stroke\n" );
                break;

        }/*end of switch*/
    }/*end of while*/
    return 0;
}

/*************************************************************************
 Functions
**************************************************************************/
void turtle_reset (turtle_t *t) {
    t->x = 0.0;
    t->y = 0.0;
    t->dir = 0.0;

    return;
}

void pen_reset (pen_t *p) {
    p->colour.r = 0;
    p->colour.g = 0;
    p->colour.b = 0;

    p->down = 0;
    p->filled = 0;
}

void set_pen_colour( pen_t *p, colour_t c ) {
    /* Modify the pen colour */
    p->colour.r = c.r;
    p->colour.g = c.g;
    p->colour.b = c.b;
    /* Set commands to ps */
    fprintf(stdout, "%.2f %.2f %.2f setrgbcolor\n", c.r, c.g, c.b );
    return;
}

void set_pen_filled(pen_t *p){
    if(p->filled == 0)
        p->filled = 1;
    else if(p->filled == 1)
        p->filled = 0;

    return;
}

int valid_colour(colour_t c) {
	if( (c.r < 0) || (c.r>1) || (c.g<0) || (c.g>1) || (c.b<0) || (c.b>1) )
    return 0;
	else
    return 1;
}

void turtle_goto( turtle_t *t, float x, float y ) {
    t->x = x;
    t->y = y;

    fprintf(stdout, "%.f %.f moveto\n", x, y );
}

void turtle_square( turtle_t *t, int size ) {
    float x = (t->x - (size/2));
    float y = (t->y - (size/2));
    fprintf(stdout, "%f %f %d %d rectfill\n", x, y, size, size );
}

void turtle_turn( turtle_t *t, float angle ) {
    t->dir = t->dir + angle;

    while(t->dir < MINANGLE){
        t->dir = t->dir + 360;
    }
    while (t->dir > MAXANGLE){
        t->dir = t->dir - 360;
    }

    return;
}

void turtle_walk( turtle_t *t, int d ) {
    double angle = t->dir * (PI/180);
    double x = t->x + (d * cos(angle));
    double y = t->y + (d * sin(angle));

    fprintf(stdout, "%f %f lineto\n", x, y);

    t->x = x;
    t->y = y;

    return;
}

void turtle_row(turtle_t *t, int count, int size) {
    int i;
    float x = t->x;

    for(i=1; i<=count; i++){
        turtle_goto(t, x, t->y);
        turtle_square(t, size);
        x = x + (size + size/2);
    }
}

void turtle_polygon(turtle_t *t, pen_t *p, int sides, int size) {
    int i;
    if (sides>2){
        for(i=0; i < sides; i++){
            turtle_walk(t, size);
			turtle_turn(t, MAXANGLE/sides);
        }
        fprintf(stdout, "closepath\n");
        if(p->filled == 1){
            fprintf(stdout, "fill\n");
        }
    }
    return;
}

void turtle_grid(turtle_t *t, int rows, int columns, int size) {

    int i;
    float x = t->x;
    float y = t->y;
    for(i=0; i<rows; i++){
        turtle_goto(t, x, y);
        turtle_row(t, columns, size);
        y = y - (size + size/2);
    }/*end of outer for*/
}

int roll_dice( void ){
    return 1 + ( rand() % 6);
}

/*Turtle walks randomly in the world*/
void turtle_random_walk(turtle_t *t, pen_t *p, int steps) {
    int i;
    colour_t c;
    c.r = c.g = c.b =0.1;
    set_pen_colour(p, c);

    for(i=0; i<steps; i++){
        int cmd = roll_dice();
        if(0){

        }else if(cmd == 1) {
            fprintf(stdout, "newpath\n");
            turtle_goto(t,t->x,t->y);
            turtle_walk(t, 10);
            fprintf(stdout, "stroke\n" );
        }else if(cmd == 2) {
            turtle_turn(t, -90);
        }else if(cmd == 3) {
            turtle_turn(t, 90);
        }else if(cmd == 4) {
            c.r = (rand() % 10) * 0.10;
            set_pen_colour(p, c);
        }else if(cmd == 5) {
            c.g = (rand() % 10) * 0.10;
            set_pen_colour(p, c);
        }else if(cmd == 6) {
            c.b = (rand() % 10) * 0.10;
            set_pen_colour(p, c);
        }

    }
    return;
}

void turtle_fractal(turtle_t *t, pen_t *p, int sides, int size, float angle, int count){
    colour_t c;
    double i;
    for(i = count; i >0; i--){
        set_pen_colour(p, random_colour(c));
        fprintf(stdout, "newpath\n");
        turtle_goto(t,t->x,t->y);
        turtle_polygon(t, p, sides, size);
        fprintf(stdout, "stroke\n" );
        turtle_turn(t, angle);
        turtle_fractal(t, p, sides, size/3, angle, count-1);
    }
}

colour_t random_colour(colour_t c){
    c.r = (rand() % 10) * 0.10;
    c.g = (rand() % 10) * 0.10;
    c.b = (rand() % 10) * 0.10;
    return c;
}
