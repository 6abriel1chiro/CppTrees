
#include "Tree.h"

int testMenu()
{
    int dato;
    
    Arbol<int> myTree;
    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1--Insertar en arbol vacio---" << endl;
        cout << "2--Insertar en arbol con elementos---" << endl;
        cout << "3--Mostrar arbol inorder--" << endl;
        cout << "4--Mostrar arbol preorder--" << endl;
        cout << "5--Buscar en arbol--" << endl;
        cout << "6. Eliminar de arbol" << endl;
        cout << "7. Leer de archivo" << endl;
        cout << "8-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            int cant,padre,dato;
            cout << "cuantos nodos va a insertar: "; cin >> cant;
            for (int i = 0; i < cant; i++)
            {
                if (i==0)
                {
                    cout << " nodo dato: "; cin >> dato;
                    myTree.insertar(dato, NULL);

                }
                else
                {
                    cout << "nodo dato: "; cin >> dato;
                    cout << "nodo padre: "; cin >> padre;
                    myTree.insertar(dato, padre);

                }
               

            }
       
                

  
        }
        if (opcion == 2)
        {
            int padre, dato,cant;

            cout << "cuantos nodos va a insertar: "; cin >> cant;
            for (int i = 0; i < cant; i++){
            cout << "nodo dato: "; cin >> dato;
            cout << "nodo padre: "; cin >> padre;
            myTree.insertar(dato, padre);
            }
        }
        if (opcion == 3)
        {
            myTree.recorrerInOrder(1);
        }
        if (opcion == 4)
        {
            myTree.recorrerPreOrder(1);

    
        }
        if (opcion == 5)
        {
            int found;
            cout << "dato a Buscar: "; cin >> dato;
            found = false;
            cout << "resultado : " << found << endl;
        }
        if (opcion == 6)
        {
            cout << "dato a eliminar: "; cin >> dato;
            //myTree.deleteNode(dato);
            cout << "eliminado: " << endl;

        }
        if (opcion == 7)
        {
           // readFromFile(myTree);
        }

    } while (opcion != 8);
    return 0;
}

int main()
{



    testMenu();


}

