#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// sketch
class Caminho;
class Node;

bool comp(const Node *n1, const Node *n2);

class Grupo {
public:
	Grupo(int i) {
		this->id = i;
	}
	int id;
	vector<Node *> nodes;
};

Grupo *grupos[25];

// classe para um no
class Node {
public:
  Node(int id) {
    this->id = id;
  }
  int id;
  vector<Node *> vizinhos;
  int grupo;
  bool visitado;
  void clear() {
  	vizinhos.clear();
  	grupo = id;
  	grupos[id]->nodes.clear();
  	grupos[id]->nodes.push_back(this);
  }
  void sorting() {
  	sort(vizinhos.begin(),vizinhos.end(),comp);
  }
  
};

bool comp(const Node *n1, const Node *n2) {
	return n1->id < n2->id;
}

// classe que representa um caminho na arvore
class Caminho {
public:

  // construtor limpo
  Caminho(Node *de) {
    this->nodes.push_back(de);
  }
  
  // construtor que copia um caminho
  Caminho(Caminho *c) {
    for(int i=0;i!=c->nodes.size();i++) {
        this->nodes.push_back(c->nodes[i]);
    }
  }
  
  // nos
  vector<Node *> nodes;
  
  void imprime() {
    for(int i=0;i < nodes.size() - 1; i++) {
        cout << nodes[i]->id << " ";
    }
    if(nodes.size()!=0) {
    	cout << nodes[nodes.size()-1]->id;
    }
    cout << endl;
  }
  
};

// mapa de nos
Node *nodes[25];
int rotas;

void busca(Node *de, Node *nodeAtual, Node *target, Caminho *c) {

  // para cada vizinho
  for(int i = 0; i != nodeAtual->vizinhos.size(); i++) {

    Node *proximo = nodeAtual->vizinhos[i];

    // se o proximo vizinho nao foi visitado e nao eh o inicial
    if(!proximo->visitado && (proximo->id != de->id)) {
    
        c->nodes.push_back(proximo);
        if(proximo->id == target->id) {
        	c->imprime();
        	rotas++;
        } else {
    	    proximo->visitado = true;
	        busca(de, proximo, target, c);
        	proximo->visitado = false;
        }
        c->nodes.erase(c->nodes.end()-1);
        
    }
  
  }

}

int main() {

  // lendo os nos
  for(int i = 0; i != 22; i++) {
  	// gera o grupo
  	grupos[i] = new Grupo(i);
    // gera o no
    Node *n = new Node(i);
    // adiciona na lista
    nodes[i] = n;
  }

  // le o numero de nos
  int targetN, caso = 0;
  while((cin >> targetN)) {
  	
  		cout << "CASE " << ++caso << ":" <<endl;
  
		  // lendo os nos
		  for(int i = 0; i != 22; i++) {
		    nodes[i]->clear();
		  }
		  
		  Node *target = nodes[targetN];
		  
		  // le o numero de conexoes
		  while(true) {
		  
		    int de, para;
		    cin >> de >> para;
		    if(de==0 && para==0) {
		    	break;
		    }
		    
		    Node *d = nodes[de], *p = nodes[para];
		    
		    // assume que as conexoes funcionam em ambas os sentidos
		    //cout << "conectando: " << d->id << " e " << p->id << endl;
		    if(find(d->vizinhos.begin(),d->vizinhos.end(),p)!=d->vizinhos.end()) {
		    	continue;
		    }
		    d->vizinhos.push_back(p);
		    p->vizinhos.push_back(d);
		    
		    if(d->grupo != p->grupo) {
		    	
		    	Grupo *novo, *velho;
		    	int novoI;
		    	if(d->grupo < p->grupo) {
		    		novo = grupos[d->grupo];
		    		velho = grupos[p->grupo];
		    		novoI = d->grupo;
		    	} else {
		    		novo = grupos[p->grupo];
		    		velho = grupos[d->grupo];
		    		novoI = p->grupo;
		    	}
		    	
		    	for(int z = 0; z != velho->nodes.size(); z++) {
		    		velho->nodes[z]->grupo = novoI;
		    		novo->nodes.push_back(velho->nodes[z]);
		    	}
		    	
		    	velho->nodes.clear();
		    	
		    }

		  }

	    // pega o no inicial
	    Node *de = nodes[1];

	    // limpa os caminhos para todos os nos
	    for(int i2 = 0; i2 != 22; i2++) {
	        nodes[i2]->visitado = false;
	        nodes[i2]->sorting();
	    }

	    de->visitado = true;

	    // gera o set de visitados
	    Caminho *caminho = new Caminho(de);
	
	    // executa a recursao
	    //cout << "Buscando a partir de " << de->name << endl;
	    rotas = 0;
	    if(de->grupo == target->grupo) //cout << "!="<<endl;
	    busca(de, de, target, caminho);
	    cout << "There are " << rotas << " routes from the firestation to streetcorner " << targetN << "." << endl;

	    delete caminho;

  }

  return 0;

}

