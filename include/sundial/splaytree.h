

#ifndef SUNDIAL_SPLAYTREE_H_INCLUDED_
#define SUNDIAL_SPLAYTREE_H_INCLUDED_


#include "sundial/sundial.h"


ENV_CPP(extern "C" {)


typedef struct tree_node_s_ splaytree_t;

struct tree_node_s_ {
    struct tree_node_s_ *left;
    struct tree_node_s_ *right;
    int key;
    int size;   /* maintained to be the number of nodes rooted here */

    void *data;
};


SUNDIAL_API splaytree_t * splaytree_splay(splaytree_t *t, int key);
SUNDIAL_API splaytree_t * splaytree_insert(splaytree_t *t, int key, void *data);
SUNDIAL_API splaytree_t * splaytree_delete(splaytree_t *t, int key);
SUNDIAL_API splaytree_t * splaytree_size(splaytree_t *t);


#define splaytree_size(x) (((x)==NULL) ? 0 : ((x)->size))
/* This macro returns the size of a node.  Unlike "x->size",     */
/* it works even if x=NULL.  The test could be avoided by using  */
/* a special version of NULL which was a real node with size 0.  */


ENV_CPP(})


#endif /* SUNDIAL_SPLAYTREE_H_INCLUDED_ */

