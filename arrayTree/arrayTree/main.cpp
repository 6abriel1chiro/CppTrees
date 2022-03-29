
#include "Tree.h"
#include <fstream>


void readFromFile(Arbol<int>& myTree)
{
    ifstream file;
    int num;
    int padre;

    file.open("file.txt");

    if (!file)
        cout << "No se puede abrir";
    else
        while (!file.eof() && file >> num >> padre)
        {
            myTree.insert(num, padre);
        }
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
        cout << "4-- --" << endl;
        cout << "5--obtener altura--" << endl;
        cout << "6. obtener total" << endl;
        cout << "7. Leer de archivo" << endl;
        cout << "8-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            int dato, cant;

            cout << "cuantos nodos va a insertar: "; cin >> cant;
            for (int i = 0; i < cant; i++) {
                cout << "nodo dato: "; cin >> dato;
                // cout << "nodo padre: "; cin >> padre;
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
            cout << " . " << endl;
    
        }
        if (opcion == 5)
        {
            int h = myTree.calcularAltura(1);
            cout << "altura " << h << endl;
        }
        if (opcion == 6)
        {
            int t = myTree.contar();
            cout << "total Nodos " << t << endl;

        }
        if (opcion == 7)
        {
           readFromFile(myTree);
        }

    } while (opcion != 8);
    return 0;
}

int main()
{



    testMenu();


}

