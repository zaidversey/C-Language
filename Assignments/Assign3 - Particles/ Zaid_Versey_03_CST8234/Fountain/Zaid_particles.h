/*  PROGRAM: particles header file
*   AUTHOR: Zaid Versey
*   DATE: March 2017
*   Purpose: Assignment 3 -
*/

/*************************************************************************
 Preprocessor Statements
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*************************************************************************
 Constants
**************************************************************************/
#define DFLT_INIT_NUM_PARTICLES 1
#define DELTA_LIFE_SPAN 100

/*************************************************************************
 Structure Definitions
**************************************************************************/

/*
*
*/
typedef struct color {
   float r;
   float g;
   float b;
   float a;
}color4_t;

/*
*
*/
struct vector {
   float x, y, z;
};
typedef struct vector Point3D_t;
typedef struct vector Vector3D_t;

/*
*
*/
typedef struct particle{
    color4_t            col;
    Point3D_t           pos;
    Vector3D_t          dir;
    Vector3D_t          spd;
    int                 lifespan;
    float                 size;
    struct particle*    next;
}particle_t;

/*************************************************************************
 Function Prototypes
**************************************************************************/
int         particle_init(struct particle* p);
int         particle_add( struct particle **head);
int         particle_remove(struct particle* p);
int         particle_destroy( struct particle **head );
int         particle_update(struct particle **head );
color4_t    random_colour(color4_t c);
Point3D_t   random_pos(Point3D_t obj, int min, int max);
Vector3D_t  random_vec(Vector3D_t obj, int min, int max);
