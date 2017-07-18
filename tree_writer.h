#include "cstdio"
#include "iostream"
#include "map"
#include "vector"
#include "string"
#include "sstream"
#include <time.h>
#include <conio.h>
#include "chrono"
#include "thread"
#include "set"
#include "vector"
#include "list"
using namespace std;

struct vertex {
    int id;
    int next1, next2;
    int id_img;
    std::string text;
    std::string question;
};


#define scen_tree_sz 100000
//typedef vertex[scen_tree_sz] scen_tree;
//extern int vsi = 0;

vertex *load_from_file(string filename);

void chose(vertex* vs);