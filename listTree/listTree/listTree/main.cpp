

#include <fstream>
#include "Arbol.h"

void readFromFile(Arbol<int>& arbolBinario)
{
	ifstream file;
	int num;

	//usar animales para 3000+ 
	//usar animalesCorto para 100
	file.open("10000_Numeros.txt");

	if (!file)
		cout << "No se puede abrir";
	else
		while (!file.eof() && file >> num)
		{
			arbolBinario.insertar(num);
		}
	file.close();
}

int testMenu()
{
    string dato;
    Arbol<int> myTree;
    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1--Insertar---" << endl;
        cout << "2--recorrido inOrden--" << endl;
        cout << "3--recorrido preOrden--" << endl;
        cout << "4--recorrido postOrden--" << endl;
        cout << "5--Buscar--" << endl;
        cout << "6--Eliminar--" << endl;
        cout << "7. leerDeArchivo" << endl;
        cout << "8. Contar nodos" << endl;
        cout << "9. Contar hojas" << endl;
        cout << "10-Salir--" << endl;
        cin >> opcion;
        system("cls");


        if (opcion == 1)
        {
            cout << "dato: "; cin >> dato;

        }
        if (opcion == 2)
        {
        }
        if (opcion == 3)
        {
            cout << "dato a eliminar: "; cin >> dato;

            cout << "eliminado: " << endl;
        }
        if (opcion == 4)
        {
            cout << "dato a Buscar: "; cin >> dato;
        }
        if (opcion == 5)
        {
            readFromFile(myTree);

        }
        if (opcion == 6)
        {
        }
        if (opcion == 7)
        {
        }
        if (opcion == 8)
        {
        }
        if (opcion == 9)
        {
        }

    } while (opcion != 10);
    return 0;
}

int main()
{

    testMenu();
}
