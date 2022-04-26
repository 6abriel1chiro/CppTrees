#include "Tree.h"

void readFromFile(map<int, int>& myMap)
{
    ifstream file;
    int num;
    string myFile = "10000_Numeros.txt";
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

void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it<<" ";

        cout<<endl;
}
int testMenu()
{

    Tree<int> myTree;
    map<int, int> myMap;
    list<int> myList;




    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1--Insertar nodos---" << endl;
        cout << "2--Mostrar monticulo---" << endl;
        cout << "3-- buscar " << endl;
        cout << "4-- heapsort--" << endl;
        cout << "5. ver cantidad de todos " << endl;
        cout << "6. Leer de archivo" << endl;
        cout << "7. eliminar mayor" << endl;
        cout << "8.  medir tiempo arbol " << endl;
        cout << "9. medir tiempo MAP " << endl;
        cout << "10.  mostar MAP " << endl;
        cout << "11.  " << endl;
        cout << "12-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            int dato;
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
            myTree.recorrerMonticulo();

        }
        if (opcion == 3)
        {
            
            int nodoBuscado;
            cout << "nodo a buscar: "; cin >> nodoBuscado;
            if (myTree.buscar(nodoBuscado))
            {
                cout << " :encontrado " << endl;

            }
            else
            {
                cout << "nodo no encontrado " << nodoBuscado << endl;

            }


            
        }
        if (opcion == 4)
        {
           myList = myTree.heapSort();
           showlist(myList);
        }
        if (opcion == 5)
        {
            int t = myTree.getTam();
            cout << "total Nodos " << t << endl;

        }
        if (opcion == 6)
        {
            readThousandNumbers(myTree);

        }
        if (opcion == 7)
        {
            //
            myTree.eliminarMayor();
        }
        if (opcion == 8)
        {
            auto start = std::chrono::high_resolution_clock::now();
            readThousandNumbers(myTree);

            auto end = std::chrono::high_resolution_clock::now();
            auto int_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
            cout << "tiempo de insertar en AVL  " << int_s.count() << " segundos . " << endl;

        }

        if (opcion ==9)
        {
            auto start = std::chrono::high_resolution_clock::now();
            readFromFile(myMap);
            auto end = std::chrono::high_resolution_clock::now();
            auto int_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
            cout << "tiempo de insertar en MAP " << int_s.count() << " seconds " << std::endl;


        }
        if (opcion == 10)
        {

            // printing map 
            map<int, int>::iterator itr;
            cout << "\tKEY\tELEMENT\n";
            for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
                cout << '\t' << itr->first << '\t' << itr->second << '\n';
            }
            cout << endl;

        }
        if (opcion == 11)
        {
            //heap sort


        }


    } while (opcion != 12);
    return 0;
}

int main()
{

    testMenu();
}