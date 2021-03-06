	#include <iostream>
	#include <fstream>	
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

	void Init_G(Adj_list &L){
		L.ActualSize = 0;
		L.front	 = NULL;
		L.end 	 = NULL;
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

	void BFS(Adj_list L[], int u, int num){

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

		int menor = 999999;

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
			//esquerda
			if(j-1 >= 0)
				if (caverna[i][j-1] != 2)				
					G_add_end(Graph[node], (node-1)+1, 1);
					
			//direita
			if(j+1 < m)
				if (caverna[i][j+1] != 2) G_add_end(Graph[node], (node+1)+1, 1);				
				
			//cima
			if(i-1 >= 0)
				if (caverna[i-1][j] != 2) G_add_end(Graph[node], (node-m)+1, 1);

			//baixo
			if(i+1 < n)
				if (caverna[i+1][j] != 2) G_add_end(Graph[node], (node + m)+1, 1);	
		}	

		return;
	}	

	void create_graph(){

		cin >> n >> m;

		saidas = new int [n*m];
		Graph = new Adj_list [n*m];
		for(int i = 0; i < n*m; i++){
			Init_G(Graph[i]);
			saidas[i] = -1;					
		}

		caverna = new int* [n];
		

		for(int i = 0; i < n; i++){
			caverna[i] = new int [m] ;
						
		}	

		int k = 0, aux = 0;	 

		for(int i=0; i < n; i++){
			for (int j = 0; j < m; ++j){
				cin >> caverna[i][j];					
				if(caverna[i][j] == 3) start = k;
				if(caverna[i][j] == 0) saidas[aux++] = k;
				k++;
			}				
		}

		k = 0;
		
		for(int i = 0; i < n; i++){
			for (int j = 0; j < m; ++j){
				Init_grid(Graph, i, j, k++);				
			}				
		}

		BFS(Graph, start+1, n*m);

	}

	int main() {		
		
		create_graph();		
		return 0;
	}


