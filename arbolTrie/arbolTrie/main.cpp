#include "Tree.h"


int testMenu()
{

    Trie myTree;




    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1--Insertar nodos---" << endl;
        cout << "2-- buscar " << endl;
        cout << "3. ver cantidad de todos " << endl;
        cout << "4. Leer de archivo" << endl;
        cout << "5.  " << endl;
        cout << "6-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            string dato;
            int cant;

            cout << "cuantos nodos va a insertar: "; cin >> cant;
            for (int i = 0; i < cant; i++) {
                cout << "nodo dato: "; cin >> dato;
                myTree.insertTrie(dato);
            }
        }


        if (opcion == 2)
        {
            string nodoBuscado;
            cout << "nodo a buscar: "; cin >> nodoBuscado;
            if (myTree.buscarPalabra(nodoBuscado))
            {
                cout << " :encontrado " << endl;

            }
            else
            {
                cout << "nodo no encontrado " << nodoBuscado << endl;

            }


        }
        if (opcion == 3)
        {

     


        }
        if (opcion == 4)
        {
    
        }
        if (opcion == 5)
        {
  

        }



    } while (opcion != 6);
    return 0;
}

int main()
{
    testMenu();
}
