
#include "Tree.h"
#include <fstream>


void readFromFile(Arbol<int>& myTree)
{
    ifstream file;
    int num;

    file.open("10000_Numeros.txt");

    if (!file)
        cout << "No se puede abrir";
    else
        while (!file.eof() && file >> num)
        {
            myTree.insert(num,1);
        }
		cout<<" cargado . . . "<<endl;
    file.close();
}

int testMenu()
{
    
    Arbol<int> myTree;
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
        cout << "7. obtener total" << endl;
        cout << "8. Leer de archivo" << endl;
		cout << "9. hallar menor" << endl;
		cout << "10. contar hojas" << endl;
		cout << "11. encontar por padre" << endl;
        cout << "12-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            int dato, cant;

            cout << "cuantos nodos va a insertar: "; cin >> cant;
            for (int i = 0; i < cant; i++) {
                cout << "nodo dato: "; cin >> dato;
                myTree.insert(dato, 1);
            }
        }

        
        if (opcion == 2)
        {
            myTree.recorrerInOrder(1);

        }
        if (opcion == 3)
        {
            myTree.recorrerPreOrder(1);

        }
		        if (opcion == 4)
        {
            myTree.recorrerPostOrder(1);

        }
        if (opcion == 5)
        {
			int nodoBuscado= 0;
            cout << "nodo a buscar: "; cin>>nodoBuscado;
			nodoBuscado = myTree.buscar(nodoBuscado,1);
			 cout << "nodo encontrado: "<<nodoBuscado<<endl;


    
        }
        if (opcion == 6)
        {
            int h = myTree.calcularAltura(1);
            cout << "altura " << h << endl;
        }
        if (opcion == 7)
        {
            int t = myTree.contar();
            cout << "total Nodos " << t << endl;

        }
		        if (opcion == 8)
        {
			readFromFile(myTree);

        }
        if (opcion == 9)
        {
			int menor= 0;
			menor= myTree.getMenor(1);
			 cout << "nodo menor : "<<menor<<endl; 
        }
		        if (opcion == 10)
        {
	// contar hojas
			int cantHojas;
			cantHojas = myTree.contarHojas(1);
			cout << "total hojas : "<<cantHojas<<endl; 
        }
				        if (opcion == 11)
        {
     /// find by parent
        }

    } while (opcion != 12);
    return 0;
}

int main()
{



    testMenu();


}

