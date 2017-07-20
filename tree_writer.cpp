#include "tree_writer.h"
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
#include <fstream>
#include "list"

using namespace std;

int index_from_id(vertex* vs, int id) {
    for(int i = 0; i < scen_tree_sz; i++)
        if(vs[i].id == id)
            return i;
    return 0;
}

vertex *load_from_file(string filename)
{
	//freopen(filename.c_str(), "r", stdin);

	{
        ifstream in(filename.c_str());
        //cin >> x; // reading from file
    

	//vertex vs[scen_tree_sz];
	vertex *vs = new vertex[scen_tree_sz];

	for(int i = 0; i < scen_tree_sz; i++)
		vs[i].id = vs[i].next1 = vs[i].next2 = -1;

   int vsi = 0;
   string s = "";
   while(getline(in, s)) {
      string id;
      string nt;
      string next1, next2;
      string img_id;
      string text;
      string q;

      int t = s.find('@');
      id = s.substr(0, t);
      s = s.substr(t + 1);
      t = s.find('@');
      nt = s.substr(0, t);
      int tt = nt.find(';');
      next1 = nt.substr(0, tt);
      next2 = nt.substr(tt + 1);
      s = s.substr(t + 1);
      t = s.find('@');
      img_id = s.substr(0, t);

      s = s.substr(t + 1);
      int tttt = s.find('@');
      text = s.substr(0, tttt);

      q = s.substr(tttt);

      vertex g;
      g.id = stoi(id);
      g.next1 = stoi(next1);
      g.next2 = stoi(next2);
      g.text = text;
      g.id_img = stoi(img_id);
      g.question = q;

      vs[vsi++] = g;
   }


   for(int i = 0; i < vsi; i++) {
      cerr << vs[i].id << '\n';
   }

   return vs;
   }
}

void chose(vertex* vs) 
{

	string result = "";

	vertex cur = vs[0];
	//cout << cur.question << '\n';
	while(cur.next1 != -1) {
		cout << cur.question << "\n";
		int t;


		cin >> t;

		if(t == 1) {
			result += cur.text + " ";
			cur = vs[index_from_id(vs, cur.next1)];
		}
		else if(t == 2) {
			result += cur.text + " ";
			cur = vs[index_from_id(vs, cur.next2)];

		}
		else
			cout << "Only 1 or 2\n";
	}

	cout << result << " ";
}