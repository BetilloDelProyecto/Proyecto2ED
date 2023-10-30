#include "StructDemonio.h"

#ifndef STRUCT_CIELO_H
#define STRUCT_CIELO_H

struct nodoAvl{
    StructHumano *h;
    nodoAvl *l;
    nodoAvl *r;
};

struct avl_tree{
    nodoAvl *root;
    
    avl_tree() {
        root = NULL;
    }

    int height(nodoAvl * t){
        int h = 0;
        if (t != NULL) {
            int l_height = height(t->l);
            int r_height = height(t->r);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        return h;
    }

    int difference(nodoAvl * t){
        int l_height = height(t->l);
        int r_height = height(t->r);
        int b_factor = l_height - r_height;
        return b_factor;
    }

    nodoAvl *rr_rotat(nodoAvl *parent){
        nodoAvl *t;
        t = parent->r;
        parent->r = t->l;
        t->l = parent;
        cout<<"Right-Right Rotation";
        return t;
    }

    nodoAvl *ll_rotat(nodoAvl *parent){
        nodoAvl *t;
        t = parent->l;
        parent->l = t->r;
        t->r = parent;
        cout<<"Left-Left Rotation";
        return t;
    }

    nodoAvl *lr_rotat(nodoAvl *parent){
        nodoAvl *t;
        t = parent->l;
        parent->l = rr_rotat(t);
        cout<<"Left-Right Rotation";
        return ll_rotat(parent);
    }

    nodoAvl *rl_rotat(nodoAvl *parent){
        nodoAvl *t;
        t = parent->r;
        parent->r = ll_rotat(t);
        cout<<"Right-Left Rotation";
        return rr_rotat(parent);
    }

    nodoAvl *balance(nodoAvl *t){
        int bal_factor = difference(t);
        if (bal_factor > 1) {
            if (difference(t->l) > 0)
                t = ll_rotat(t);
            else
                t = lr_rotat(t);
        } else if (bal_factor < -1) {
            if (difference(t->r) > 0)
                t = rl_rotat(t);
            else
                t = rr_rotat(t);
        }
        return t;
    }

    nodoAvl *insert(StructHumano *x, nodoAvl *t){
        if (t == NULL) {
            t = new nodoAvl;
            t->h = x;
            t->l = NULL;
            t->r = NULL;
            return t;
        } else if (x->id < t->h->id) {
            t->l = insert(x, t->l);
            t = balance(t);
        } else if (x->id > t->h->id) {
            t->r = insert(x, t->r);
            t = balance(t);
        }
        return t;
    }

    void show(nodoAvl *t, int level){
        int i;
        if (t != NULL) {
            show(t->r, level + 1);
            cout<<endl;
            if (t == root)
                cout<<"Root -> ";
            for (i = 0; i < level && t != root; i++)
                cout<<"        ";
            cout<<t->h->id;
            show(t->l, level + 1);
        }
    }
    
    void inOrder(nodoAvl *t) {
        if (t != nullptr) {
            inOrder(t->l);
            std::cout << t->h->id << " ";
            inOrder(t->r);
        }
    }

};

struct Cielo{
    avl_tree * cielo[1000];

    Cielo(){
        //cout << "hola xd" << endl;
    }

    int getID(StructHumano * h){
        return h->id%1000;
    }

    void insertar(StructHumano * h){
        h->salvado = true;
        h->condenado = false;
        cielo[getID(h)]->insert(h,cielo[getID(h)]->root);
    }

};



#endif