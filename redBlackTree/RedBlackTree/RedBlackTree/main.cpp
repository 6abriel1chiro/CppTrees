
#include "RedBlackTree.h"
#include <chrono>
#include <thread>
#include <iterator>
#include <set>

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
			//cout<<word<<endl;
            mySet.insert(word);
        }
		cout<<" cargado . . . "<<endl;
    file.close();
}

void readFromFile(RBtree<string>& myTree)
{
    ifstream file;
    string num;

    file.open("100anios.txt");

    if (!file)
        cout << "No se puede abrir";
    else
        while (!file.eof() && file >> num)
        {
            myTree.Insertar(num);
        }
    cout << " cargado . . . " << endl;
    file.close();
}


void countDuplicatesFromFile(RBtree<string>& myTree)
{
    ifstream file;
    string num;

    file.open("100anios.txt");

    if (!file)
        cout << "No se puede abrir";
    else
        while (!file.eof() && file >> num)
        {
            myTree.Insertar(num);
			myTree.setRaiz("Negro");
        }
    cout << " cargado . . . " << endl;
    file.close();
}

int testMenu()
{
    
    RBtree<string> myTree;
	set<string > mySet;

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
		cout << "11. medir tiempo SET " << endl;
		cout << "12.  mostar SET " << endl;
		cout << "13.  contar repetidos en archivo " << endl;
        cout << "14-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            string dato;
			int cant;

            cout << "cuantos nodos va a insertar: "; cin >> cant;
            for (int i = 0; i < cant; i++) {
                cout << "nodo dato: "; cin >> dato;
                myTree.Insertar(dato);
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
			string nodoBuscado;
            cout << "nodo a buscar: "; cin>>nodoBuscado;
            if ( myTree.Buscar(nodoBuscado))
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
			readFromFile(myTree);

        }
        if (opcion == 9)
        {
			  //          string  node;
          //  cout << "nodo a eliminar : "; cin>>node;
          //  myTree.eliminar(node);
        }
		if (opcion == 10)
        {
			  auto start = std::chrono::high_resolution_clock::now();
				readFromFile(myTree);
			  auto end = std::chrono::high_resolution_clock::now();
			  auto int_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
			  cout << "tiempo de insertar en ABB  " << int_s.count() << " segundos . " <<endl;

        }
                
        if (opcion == 11)
        {
			  auto start = std::chrono::high_resolution_clock::now();
				readFromFile(mySet);
			  auto end = std::chrono::high_resolution_clock::now();
			  auto int_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
			  cout << "tiempo de insertar en set " << int_s.count() << " seconds " << std::endl;


        }
        if (opcion == 12)
        {

			set<string >::iterator itr;
			int counter = 0;
			cout << "\nThe set s1 is : \n";
			for (itr = mySet.begin(); itr != mySet.end(); itr++)
			{
				 cout << *itr << " ";
				 counter++;
			}
		cout << endl;
		cout<<"elementos : "<<counter<<endl;
            
        }
		        if (opcion == 13)
        {
			countDuplicatesFromFile(myTree);
        }


    } while (opcion != 14);
    return 0;
}


int main()
{

    testMenu();

}
