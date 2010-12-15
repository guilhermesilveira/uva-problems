#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main(char **argv,int argc) {

    int maxLg = 200;

    map<string,vector<string> > connections = new Hashtable();
    vector<string> v;
    map<string,string> parents;
	string l[2];
    vector queue<string>;

    int caso = 0;

    while(true) {
    	
    	int cs;
    	if((scanf(" %cs",&n))!=1)) break;
    	
        if (caso++ != 0) {
            System.out.println();
        }
        
        connections.clear();

        int cs = Integer.parseInt(readLine().trim());

        for (int i = 0; i != cs; i++) {
            String l[] = split(readLine().trim());
            if (!connections.containsKey(l[0])) {
                connections.put(l[0], new Vector());
            }
            if (!connections.containsKey(l[1])) {
                connections.put(l[1], new Vector());
            }
            ((Vector) connections.get(l[0])).addElement(l[1]);
            ((Vector) connections.get(l[1])).addElement(l[0]);
        }

        l = split(readLine().trim());

        parents.clear();
        String from = l[0], to = l[1];
        parents.put(from, from);
        if (!connections.containsKey(from) || !connections.containsKey(to)) {
            System.out.println("No route");
            return;
        }

        queue.removeAllElements();
        queue.addElement(from);

        while (queue.size() != 0) {

            String next = (String) queue.elementAt(0);
            queue.removeElementAt(0);

            v = ((Vector) connections.get(next));
            for (int i = 0; i != v.size(); i++) {
                String overNext = (String) v.elementAt(i);
                if (overNext.equals(to)) {
                    String t = next, s = "";
                    while (t != from) {
                        s = parents.get(t) + " " + t + "\n" + s;
                        t = (String) parents.get(t);
                    }
                    s += (next + " " + to);
                    System.out.println(s);
                    return;
                }
                if (!parents.containsKey(overNext)) {
                    queue.addElement(overNext);
                    parents.put(overNext, next);
                }
            }

        }

        System.out.println("No route");
        
    }
    
    return 0;


}