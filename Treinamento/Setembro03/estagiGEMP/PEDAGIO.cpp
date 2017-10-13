	#include <iostream>
	#include <queue>

	using namespace std;

	int n, m, s, pmax, teste=1;
	int *saida;

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

	void BFS(Adj_list L[], int u, int n){

		int size = n;
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

		int k = 0;

		for(int i = 0; i < size; i++){

			if(dis[i] <= pmax and  i != s-1){
				saida[k] = i+1;
				k++;
			}
		}

	}

	Adj_list* Graph;

	void create_graph(){


		cin >> n >> m >> s >> pmax;

		while(n != 0){

			saida = new int[n];
			Graph = new Adj_list [n];
			for(int i = 0; i < n; i++){
				Init_G(Graph[i]);
				saida[i] = -1;
			}	
			
			int row, column;			

			for(int i=0; i<m; i++){
				cin >> row >> column;
				G_add_end(Graph[row-1], column, 1);
				G_add_end(Graph[column-1], row, 1);
				
			}

			BFS(Graph, s, n);

			cout << "Teste " << teste++ <<endl;

			for(int i = 0; i < n; i++){
				if(saida[i]!=-1){
					cout << saida[i] << " ";
				}
				else break;
				
			}
			cout << "\n\n";

			cin >> n >> m >> s >> pmax;
		}

	}

	int main() {				
		create_graph();		
		return 0;
	}


