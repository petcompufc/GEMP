	#include <iostream>
	#include <fstream>	
	#include <queue>

	using namespace std;

	int n, m;
	
	int start, dirty[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	char ** room;
	
	struct edge{
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

		int total = 0;

		cout << u << endl;

		for (int i = 0; i < 10; ++i)
		{
			cout << dirty[i] << " ";
		}

		cout << endl;

		for (int i = 0; i < 10; ++i)
		{
			cout << dis[dirty[i]] << " ";
		}

		cout << endl;

		for (int i = 0; i < size; ++i)
		{
			cout << dis[i] << " ";
		}

		cout << endl;

		for(int i = 0; i < 10; i++){
			if(dirty[i] == -1 ){
				cout << total << endl;
				return;
			}
			else if (dis[dirty[i]] == 9999999){
				cout << -1 << endl;
				return;
			}
			total += dis[dirty[i]];
		}
	}	

	void Init_grid(Adj_list Graph[], int i, int j, int node){
		if (room[i][j] != 'x'){			
			//esquerda
			if(j-1 >= 0)
				if (room[i][j-1] != 'x') G_add_end(Graph[node], (node-1)+1, 1);
					
			//direita
			if(j+1 < m)
				if (room[i][j+1] != 'x') G_add_end(Graph[node], (node+1)+1, 1);				
				
			//cima
			if(i-1 >= 0)
				if (room[i-1][j] != 'x') G_add_end(Graph[node], (node-m)+1, 1);

			//baixo
			if(i+1 < n)
				if (room[i+1][j] != 'x') G_add_end(Graph[node], (node + m)+1, 1);	
		}	

		return;
	}	

	void create_graph(){

		Adj_list* Graph;

		cin >> m >> n;

		while(n != 0){			

			Graph = new Adj_list [n*m];

			for(int i = 0; i < n*m; i++){
				Init_G(Graph[i]);								
			}

			room = new char* [n];		

			for(int i = 0; i < n; i++){
				room[i] = new char [m] ;
							
			}	

			int k = 0, aux = 0;	 

			for(int i=0; i < n; i++){
				for (int j = 0; j < m; ++j){
					cin >> room[i][j];					
					if(room[i][j] == 'o') start = k;
					if(room[i][j] == '*') dirty[aux++] = k;
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

			delete Graph;

			for(int i = 0; i < n; i++){
				delete room[i];
			}

			delete room;

			cin >> m >> n;
		}

	}

	int main() {		
		
		create_graph();		
		return 0;
	}


