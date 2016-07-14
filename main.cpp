#include "customer.h"
#include "depot.h"
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <unordered_map>

#define TOPEVECTOR 200
#define MAXLINEA 255
#define FALSE 0
#define TRUE 1



using namespace std;

typedef char str_linea[MAXLINEA];


int main(int argc, char const *argv[])
{
	FILE *pArchivo;
	customer vNode[TOPEVECTOR];
	depot vDepot;
	char *token;
	str_linea linea;
	map <int, vector<float> > rutasLine; //distancia desde nodo Line a todos los Line
	map <int, vector<float> > rutasBack; //distancia desde nodo Back a todos los Back
	vector<float> distDepotLine; //para depot
	vector<float> distDepotBack; //para depot
	vector<float> testvector, testvector2;
	unordered_map <int,double> distancia_en_cluster; //para saber la distancia en los cluster
	map< int, map< int, vector<int> > > asignacion; //para asignar flota a depositos
	map<int, double> distancia_rutas;
	map<int, int> ruta_demanda;
	map<int, int> demandas_antes_lkh;
	map<float, float> distancias;

	int i=0;
	int j=0;

	vDepot.id = 1;
	vDepot.xi = 5;
	vDepot.yi = 7;

	pArchivo = fopen("instances/GJ01H.csv","rt");
	if (pArchivo == NULL)
	{
		cout << "No se pudo abrir" << endl;
	}
	else{
		cout << "Abierto" << endl;
	}

		while(!feof(pArchivo))
	{

		vNode[i].id = i;
		fgets(linea,MAXLINEA,pArchivo);

		token = strtok(linea,";");
		vNode[i].xi = atoi(token);

		token = strtok(NULL,";");
		vNode[i].yi = atoi(token);

		token = strtok(NULL,";");
		vNode[i].Delivery = atoi(token);

		token = strtok(NULL,";");
		vNode[i].Pickup = atoi(token);

		if (vNode[i].Delivery==0)
		{
			vNode[i].L = FALSE;
			cout << "un false" << endl;
		}

		i++;
	}

		fclose(pArchivo);

		float euclidiana;
		int k=0;

		//Lleno map de linehaul

		for(i=0;i<CUSTOMERS && vNode[i].L ;i++){
		for(j=0;j<CUSTOMERS && vNode[j].L ;j++){
		float euclidiana = sqrt(pow((vNode[i].xi - vNode[j].xi), 2) + pow((vNode[i].yi - vNode[j].yi), 2));
		testvector.push_back(euclidiana);
			}
			rutasLine[i+1] = testvector;
			testvector.clear();
			}

		//Lleno map de Backhaul

		for(i=0;i<CUSTOMERS;++i){
			if(!vNode[i].L){
		for(j=0;j<CUSTOMERS;++j){
			if(!vNode[j].L){
		euclidiana = sqrt(pow((vNode[i].xi - vNode[j].xi), 2) + pow((vNode[i].yi - vNode[j].yi), 2));
		testvector2.push_back(euclidiana);

	}
			
		}
			
			rutasBack[k+1] = testvector2;
			k++;
			testvector2.clear();
			}
			}

		for(i=0;i<CUSTOMERS && vNode[i].L ; i++){
				euclidiana = sqrt(pow((vDepot.xi - vNode[j].xi), 2) + pow((vDepot.yi - vNode[j].yi), 2));
				distDepotLine.push_back(euclidiana);
		}

		for(i=0;i<CUSTOMERS ; i++){
			if(!vNode[i].L){
				euclidiana = sqrt(pow((vDepot.xi - vNode[j].xi), 2) + pow((vDepot.yi - vNode[j].yi), 2));
				distDepotLine.push_back(euclidiana);
			}
		}
		
		//PARA IMPRIMIR!!

		for(map<int, vector<float> >::iterator it=rutasBack.begin(); it!=rutasBack.end(); ++it){
			vector<float> tempVec = (*it).second;
			int key = (*it).first;
			cout << "KEY **************************************"<<key << "    ";
			//cout << tempVec.size() << endl;
			for (unsigned i = 0 ; i< tempVec.size(); i++){
				cout << " " << tempVec[i];
			}
				cout << endl;
			}


		/*for(i=0;i<CUSTOMERS;i++){
		for(j=0;j<CUSTOMERS;j++){
			if(vNode[i].L){
		cout<<"distancia entre "<< vNode[i].id<< " y "<< vNode[j].id <<": "<<rutas[i].testvector[j]<<endl;
			}
			}
		}*/

	//getchar();


	return 0;
}