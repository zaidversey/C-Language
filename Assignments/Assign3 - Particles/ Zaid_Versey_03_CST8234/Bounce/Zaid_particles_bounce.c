/*  PROGRAM: particle functions
*   AUTHOR: Zaid Versey
*   DATE: March 2017
*   Purpose: Assignment 3 -
*/

# include "Zaid_particles.h"

/*********************************************************************
 FUNCTION :  particle_init
 PURPOSE  :  initialize the properties of a single particle
 INPUT    :  pointer to the particle structure to be initialized
 OUTPUT   :  returns -­1 on error, 0 on success
 NOTES    :
 *********************************************************************/
int particle_init(struct particle* p) {

    /*set color*/
    /*p->col =  random_colour(p->col);*/
    p->col.r = (rand() % 10) * 0.10;
    p->col.g = (rand() % 10) * 0.10;
    p->col.b = (rand() % 10) * 0.10;
    p->col.a = 1;

    /*set position*/
    p->pos = random_pos(p->pos,-400, 400);

    /*set direction*/
    p->dir = random_vec(p->dir, -10, 10);

    /*set speed*/
    p->spd.x = p->spd.y = p->spd.z = 0.5 + rand() % 2;

    /*set lifespan of particle*/
    p->lifespan = DELTA_LIFE_SPAN;

    /*set size of particle*/
    p->size = 5;
    /*initailize particle next to NULL*/
    p->next == NULL;

    return 0;
}

/*********************************************************************
 FUNCTION :  particle_add
 PURPOSE  :  add a particle to the dynamic particle linked list
 INPUT    :  struct particle *head. Head of the particle list
 OUTPUT   :  returns -­1 on error, 0 on success
 NOTES    :  Calls particle_init()
 ********************************************************************/
 int particle_add( struct particle **head) {
    particle_t *new;

    if ( (new = (particle_t *) malloc(sizeof(particle_t))) == NULL ) {
    return -1;
    }

    particle_init(new);

    new->next = *head;
    *head  = new;

    return 0;
 }

 /*********************************************************************
 FUNCTION :  particle_remove
 PURPOSE :   remove a specific particle from the dynamic
               particle linked list
 INPUT    :  pointer to the particle to remove
 OUTPUT   :  returns ­-1 on error, 0 on success
 NOTES    :  Particle can be situated in any place in the list.
             Usually deleted because the lifespan ran out
********************************************************************/
int particle_remove(struct particle *p) {
    particle_t *curr = p;
    particle_t *next;
    /*handle if the list is empty*/
    if(p == NULL){
        return -1;
    }
    /*handle if particle is the only element in the list*/
    if(curr->next == NULL){
        /*free (curr);
        p= NULL;*/
        p->col.a = 0;
        return 0;
    }

    /*assign currents next particle to next*/
    next = curr->next;

    /*copy next particle's data into current particle's data and overwrite*/
    curr->col =         next->col;
    curr->pos =         next->pos;
    curr->spd =         next->spd;
    curr->dir =         next->dir;
    curr->lifespan =    next->lifespan;
    curr->size =        next->size;

    /*current paritcle's next is equal to next particle's next*/
    curr->next =        next->next;

    /*free the next particle as it's not needed anymore*/
    free(next);

    return 0;
}

/*********************************************************************
 FUNCTION :  particle_destroy
 PURPOSE  :  free memory used by the dynamic particle linked list
 INPUT    :  struct particle **head. Head of the particle list
 OUTPUT   :  returns ­-1 on error,
               the number of particles destroyed on success
 NOTES    :  removes all particles from the list
               Calls particle_remove()
 ********************************************************************/
int particle_destroy( struct particle **head ) {
    int count_particles = 0;

    /*handle if the list is empty*/
    /*if(*head == NULL){
        return -1;
    }

    while(*head != NULL) {
      particle_remove(*head);
      count_particles++;
    }

    return count_particles;
    */

    struct particle *temp = *head;


    if(*head == NULL){
        return -1;
    }

    while(temp != NULL) {
      free(temp);
      count_particles++;
      temp = temp->next;
    }
    return count_particles;

}

/********************************************************************
 FUNCTION :  particle_update
 PURPOSE  :  update the particles properties to be rendered
               in the next frame
 INPUT    :  struct particle **head. Head of the particle list
 OUTPUT   :  returns ­1 on error, 0 on success
 NOTES    :  Creativity and more creativity here for you !!!
 ********************************************************************/
int particle_update(struct particle **head ) {
    particle_t *curr = *head;

   if (curr == NULL) return -1;

   while (curr != NULL) {
       /* randomize colour */
       /*curr->col = random_colour(curr->col);*/

       /* update x position and reverse direction if particle reaches boundary */
       curr->pos.x += (curr->spd.x * curr->dir.x);
       if(curr-> pos.x > 400 || curr-> pos.x < -400){
			curr-> dir.x *= -1;
		}

       /* update y position and reverse direction if particle reaches boundary */
       curr->pos.y += (curr->spd.y * curr->dir.y);
       if(curr-> pos.y > 400 || curr-> pos.y < -400){
			curr-> dir.y *= -1;
		}

       /* update speed */

       /* decrement lifespan */

       /*curr->lifespan --;*/

       /* increase size and decrease opacity*/
       curr->size += 0.1;
       curr->col.a -= 0.003;

       /* kill particle if particle has fully faded */
       if (curr->col.a <= 0) {
           particle_remove(curr);
           /*curr->lifespan = 10;*/
       }

       curr = curr->next;

   }
   return 0;
}

color4_t random_colour(color4_t c){
    c.r = (rand() % 10) * 0.10;
    c.g = (rand() % 10) * 0.10;
    c.b = (rand() % 10) * 0.10;
    c.a = (rand() % 10) * 0.10;
    return c;
}

Point3D_t random_pos(Point3D_t obj, int min, int max){
    obj.x = ( min + rand() % ( max - min + 1 ) ); /*min + (rand()% max);*/
    obj.y = ( min + rand() % ( max - min + 1 ) ); /*min + (rand()% max);*/
    obj.z = ( min + rand() % ( max - min + 1 ) ); /*min + (rand()% max);*/
    return obj;
}

Vector3D_t random_vec(Vector3D_t obj, int min, int max){
    obj.x = ( min + rand() % ( max - min + 1 ) ); /*min + (rand()% max);*/
    obj.y = ( min + rand() % ( max - min + 1 ) ); /*min + (rand()% max);*/
    obj.z = ( min + rand() % ( max - min + 1 ) ); /*min + (rand()% max);*/
    return obj;
}
