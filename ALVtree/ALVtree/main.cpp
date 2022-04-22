#include "Tree.h"
#include <set>
#include <map>

#include <iterator>
#include <fstream>
#include <chrono>

void readFromFile(set<string>& mySet)
{
    ifstream file;
    string word;
    string myFile = "100anios.txt";
    file.open(myFile);

    if (!file)
        cout << "No se puede abrir";
    else
        while (!file.eof() && file >> word)
        {
            cout<<word<<endl;
            mySet.insert(word);
        }
    cout << " cargado . . . " << endl;
    file.close();
}

void readFromFile(map<string,int>& myMap)
{
    ifstream file;
    string num;
		int i=0;
    string myFile = "100anios.txt";
    file.open(myFile);

    if (!file)
        cout << "No se puede abrir";
    else
        while (!file.eof() && file >> num)
        {
           // cout<<nim<<endl;

		   myMap[num]++;

		  
        }
    cout << " cargado . . . " << endl;
    file.close();
}


void readThousandNumbers(Tree<int>& myTree)
{
    ifstream file;
    int num;

    file.open("10000_Numeros.txt");

    if (!file)
        cout << "No se puede abrir";
    else
        while (!file.eof() && file >> num)
        {
            myTree.insertar(num);
        }
    cout << " cargado . . . " << endl;
    file.close();
}

void read100anios(Tree<string>& myTree)
{
    ifstream file;
    string num;

    file.open("100anios.txt");

    if (!file)
        cout << "No se puede abrir";
    else
        while (!file.eof() && file >> num)
        {
						            cout<<num<<endl;

            myTree.insertar(num);

        }
    cout << " cargado . . . " << endl;
    file.close();
}







int testMenu()
{

    Tree<string> myTree;

    set<string > mySet;

	map<string, int> myMap;

    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1--Insertar nodos---" << endl;
        cout << "2--Mostrar arbol inorder---" << endl;
        cout << "3--Mostrar arbol preorder--" << endl;
        cout << "4--Mostrar arbol postorder--" << endl;
        cout << "5-- buscar " << endl;
        cout << "6--obtener altura--" << endl;
        cout << "7. contar nodos " << endl;
        cout << "8. Leer de archivo" << endl;
        cout << "9. eliminar" << endl;
        cout << "10.  medir tiempo arbol " << endl;
        cout << "11. medir tiempo MAP " << endl;
        cout << "12.  mostar MAP " << endl;
        cout << "13.  " << endl;
        cout << "14-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
           string dato;
			//int dato;
            int cant;

            cout << "cuantos nodos va a insertar: "; cin >> cant;
            for (int i = 0; i < cant; i++) {
                cout << "nodo dato: "; cin >> dato;
                myTree.insertar(dato);
            }
        }


        if (opcion == 2)
        {
            myTree.mostrarInOrder();

        }
        if (opcion == 3)
        {
            myTree.mostrarPreOrder();

        }
        if (opcion == 4)
        {
            myTree.mostrarPostOrder();

        }
        if (opcion == 5)
        {
        //    int nodoBuscado;
		string nodoBuscado;
            cout << "nodo a buscar: "; cin >> nodoBuscado;
            if (myTree.Buscar(nodoBuscado))
            {
                cout << " :encontrado " << endl;

            }
            else
            {
                cout << "nodo no encontrado: " << nodoBuscado << endl;

            }



        }
        if (opcion == 6)
        {
            int h = myTree.Altura();
            cout << "altura " << h << endl;
        }
        if (opcion == 7)
        {
            int t = myTree.Contar();
            cout << "total Nodos " << t << endl;

        }
        if (opcion == 8)
        {
           read100anios(myTree);
			//readThousandNumbers(myTree);

        }
        if (opcion == 9)
        {
//
        }
        if (opcion == 10)
        {
            auto start = std::chrono::high_resolution_clock::now();
            read100anios(myTree);
			//readThousandNumbers(myTree);

            auto end = std::chrono::high_resolution_clock::now();
            auto int_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
            cout << "tiempo de insertar en AVL  " << int_s.count() << " segundos . " << endl;

        }

        if (opcion == 11)
        {
            auto start = std::chrono::high_resolution_clock::now();
            readFromFile(myMap);
            auto end = std::chrono::high_resolution_clock::now();
            auto int_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
            cout << "tiempo de insertar en MAP " << int_s.count() << " seconds " << std::endl;


        }
        if (opcion == 12)
        {

 // printing map 
    map<string, int>::iterator itr;
    cout << "\tKEY\tELEMENT\n";
    for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second<< '\n';
    }
    cout << endl;
    
		}
        if (opcion == 13)
        {
		//	countDuplicatesFromFile();
			
        }


    } while (opcion != 14);
    return 0;
}


int main()
{

    testMenu();

}