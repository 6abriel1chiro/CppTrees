// RedBlackTree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "RedBlackTree.h"
#include <fstream>


void readFromFile(RBtree<int>& myTree)
{
    ifstream file;
    int num;

    file.open("10000_Numeros.txt");

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

int testMenu()
{

    RBtree<int> myTree;
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
        cout << "9. ver altura negra" << endl;
        cout << "10. eliminar " << endl;
        cout << "11. TBD " << endl;
        cout << "12. TBD " << endl;
        cout << "13-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            int dato, cant;

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
            int nodoBuscado = 0;
            cout << "nodo a buscar: "; cin >> nodoBuscado;
            nodoBuscado = myTree.Buscar(nodoBuscado);
            if (nodoBuscado)
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
            myTree.AlturaNegra();
        }
        if (opcion == 10)
        {
            int  node;
            cout << "nodo a eliminar : "; cin >> node;
            myTree.eliminar(node);
        }

        if (opcion == 11)
        {

            //

        }
        if (opcion == 12)
        {
            //
        }


    } while (opcion != 13);
    return 0;
}


int main()
{

    testMenu();

}
