	#include <iostream>
	#include <map>
	#include <set>
	#include <fstream>
	#include <utility>
	#include <limits>
	#include <queue>

	using namespace std;

	int n, m;
	
	int start, *saidas;
	int ** caverna;
	
	struct edge
	{
		int u;			//incident vertex
		double weight;	//actual weight of the edge
		edge* next;
		edge* previus;
	};

	struct Adj_list{

		int   ActualSize;
		edge* front;
		edge* end;

	};

	int size 		(Adj_list L);
	void destroy	(Adj_list &L);



	void Init_G(Adj_list &L){
		L.ActualSize = 0;
		L.front	 = NULL;
		L.end 	 = NULL;
	}

	void G_add_front(Adj_list &L, int u, double w){

		edge* newE = new edge;
		newE -> u 			= u;
		newE -> weight  	= w;	
		newE -> previus		= NULL;	

		if(L.ActualSize == 0 ){
			newE -> next	= NULL;
			//newE -> previus = NULL;
			L.front 		= newE;
			L.end 			= newE;
		}
		else{
			newE -> next 	   = L.front;
			L.front -> previus = newE;
			L.front 		   = newE;
		} 

		L.ActualSize++;

	}

	void G_add_end(Adj_list &L, int u, double w){

		edge* newE = new edge;
		newE -> u		= u;
		newE -> weight 	= w;
		newE -> next	= NULL;
			
		if(L.ActualSize == 0) {
			L.front = newE;
			L.end 	= newE;
			newE -> previus	= NULL;
		}
		else{
			newE -> previus	= L.end;
			L.end->next 	= newE;
			L.end 	= newE;
		}

		L.ActualSize++;
	}

	edge* G_reomve_front(Adj_list &L) {	
		edge* value = new edge;

		// standard values in case of empty graph
		value -> next	 = NULL;
		value -> previus = NULL;
		value -> u 		= 999999; 		
		value -> weight = 999999;

		//if not empty
		if (size(L)!=0){
			//special case of size=1
		    if ( size(L)==1){
			    value -> u      = L.end->u;
			    value -> weight = L.end->weight;
			    destroy(L);
		    }
		    //general case
			else{
				value -> u      = L.front->u;
			    value -> weight = L.front->weight;
				edge* aux 		= L.front->next;
				delete L.front;
				L.front = aux;
				--L.ActualSize;
			}
		}
		
		return value;
	}

	edge* G_remove_end(Adj_list &L) {
		edge* value 	 = new edge;
		// standard values in case of empty graph
		value -> next	 = NULL;
		value -> previus = NULL;	
		value -> u 		 = 999999; 		
		value -> weight  = 999999;

		//if not empty
		if (L.ActualSize > 0) {
			value-> u 	   = L.end->u;
			value-> weight = L.end->weight;

			//special case of size=1
			if (L.ActualSize == 1) {
				delete L.end;
				L.end = NULL;
				L.front = NULL;
			}
			// Sgeneral case
			else { 
				edge *aux = L.end->previus;
				delete L.end;
				L.end = aux;
				L.end->next = NULL;
			}		
			L.ActualSize--;
		}

		return value;
	}


	int size(Adj_list L) {
		return L.ActualSize;
	}

	void destroy(Adj_list &L) {
		while (L.front != NULL) {
			edge *p  = L.front;
			L.front = L.front->next;
			delete p;
		}
		L.ActualSize = 0;
	}

	void BFS(Adj_list L[], int u, int num){
		//cout << "\n\n";
		//cout << "Starting BFS algorithm.\n";

		int size = num;
		int* color = new int [size];
		int* dis   = new int [size];
		int* pi    = new int [size];
		for(int i = 0; i < size; i++){
			color[i] = 0;
			dis[i] 	 = 9999999;
			pi[i] 	 = -1;
		}
		color[u-1] = 1;
		dis[u-1]   = 0;
		pi[u-1]	   = -1;

		queue<int> Q;
		Q.push(u-1);

		int aux;
		edge* auxE = new edge;
		while(Q.empty() == 0){
			
			aux = Q.front(); Q.pop();			
			
			auxE = L[aux].front;
			while(auxE != NULL){
				if(color[(auxE->u)-1] == 0){

					color[(auxE->u)-1] = 1;				
					dis[(auxE->u)-1]   = dis[aux]+1;
					pi[(auxE->u)-1]	   = aux+1;
					Q.push((auxE->u)-1);
					
				}
				auxE = auxE -> next;
			}
			color[aux] = 2;
		}

		int menor = dis[0];

		for(int i = 0; i < size; i++){
			if(saidas[i] == -1 ){
				cout << menor << endl;
				return;
			}
			if(dis[saidas[i]] < menor) menor = dis[saidas[i]];
		}

		cout << menor << endl;



	}

	Adj_list* Graph;

	void Init_grid(Adj_list L[], int i, int j, int node){
		if (caverna[i][j] != 2){	
			cout << "flag2!!!\n"	;;	
			//esquerda
			if(j-1 >= 0){
				if (caverna[i][j-1] != 2)
				{
					G_add_end(Graph[node], node-1, 1);
					G_add_end(Graph[node-1], node, 1);
				}
			}
			//direita
			if(j+1 < m)
				if (caverna[i][j+1] != 2)
				{
					G_add_end(Graph[node], node+1, 1);
					G_add_end(Graph[node+1], node, 1);
				}
			//cima
			if(i-1 >= 0){
				if (caverna[i-1][j] != 2){
					G_add_end(Graph[node], node-m, 1);
					G_add_end(Graph[node-m], node, 1);
				}
			}
			//baixo
			if(i+1 < n){
				if (caverna[i-1][j] != 2)
				{
					G_add_end(Graph[node], node+m, 1);
					G_add_end(Graph[node+m], node, 1);
				}
			}
			cout << "flag3!!!\n"	;;			
			
		}

		return;
	}	

	void create_graph(const char* filename){

		ifstream dados(filename, ifstream::in);

		dados >> n >> m;

		Graph = new Adj_list [n*m];
		for(int i = 0; i < n*m; i++){
			Init_G(Graph[i]);				
		}

		caverna = new int* [n];
		saidas = new int [n*m];

		for(int i = 0; i < n; i++){
			caverna[i] = new int [m] ;
			saidas[i] = -1;				
		}			
		

		int k = 0, aux = 0;
		 

		for(int i=0; i < n; i++){
			for (int j = 0; j < m; ++j){
				dados >> caverna[i][j];					
				if(caverna[i][j] == 3) start = k;
				if(caverna[i][j] == 0) saidas[aux++] = k;
				k++;
			}				
		}
		for(int i=0; i < n; i++){
			for (int j = 0; j < m; ++j){
				cout << caverna[i][j] << " ";									
			}
			cout << endl;				
		}

		k = 0;
		cout << "teste novo!!!\n"	;	
		for(int i = 0; i < n*m; i++){
			if (i > 0) G_add_end(Graph[i], i-1, 1);				
		}
		cout << "teste nvov!!!\n"	;	

		cout << "flag!!!\n"	;	
		for(int i = 0; i < n; i++){
			for (int j = 0; j < m; ++j){
				Init_grid(Graph, i, j, k);
				k++;				
			}				
		}



		cout << "flag4!!!\n"	;
		BFS(Graph, start, n*m);

	}

	int main(int argc, char *argv[]) {		
		
		create_graph(argv[1]);		
		return 0;
	}


