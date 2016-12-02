#include <iostream>
#include <vector>
#define M 20
 
using namespace std;
 
struct wezel {
    int liczba;
    string nazwisko;
    string s;
};
 
int funkcja_haszujaca( int k, int i )
{
    int a;
    int b;
    int c;
 
    a = k % M;
    b = 1 + ( k % ( M - 2 ) );
    c = ( a + i * b ) % M;
 
    return c;
}
 
int szukanie( struct wezel T[], int k, string b )
{
    int i;
    int j;
    string str1;
    string str2;
 
    i = 0;
 
    while( i != M ) {
        j = funkcja_haszujaca( k, i );
 
		std::string str1 = T[j].nazwisko;
		std::string str2 = b;
 
        if( T[j].liczba == k && (str1.compare(str2)) == 0 && T[j].s == "FIL" ) {
            return j;
        }
 
        i++;
    }
 
    return -1;
}
 
void kasowanie( struct wezel *T, int k, string b)
{
    int i;
    int j;
 
    i = szukanie( T, k, b );
 
    if( i != -1 ) {
        T[i].s = "DEL";
        T[i].nazwisko = "";
    } else {
        cout << "Nie znaleziono!\n";
    }
 
    return;
}
 
void wstawianie( struct wezel *T, int k, string b )
{
    int i;
    int j;
 
    i = 0;
 
    while( i != M ) {
        j = funkcja_haszujaca( k, i );
        if(  T[j].s == "NIL" || T[j].s == "DEL" ) {
            T[j].liczba = k;
            T[j].nazwisko = b;
            T[j].s = "FIL";
            return;
        }
        i++;
    }
 
    if( i == M ) {
        cout << "Poza zakresem!\n";
    }
 
    return;
}
 
int main()
{
    int i;
    int j;
    int a;
    string b;
    int ch = 1;
    struct wezel T[M];
    string str1;
    string str2;
    string del = "DEL";
 
    for( i = 0; i < M; i++ ) {
        T[i].s = "NIL";
    }
 
    do{
                cout << "\nWybierz:\n1.Dodanie\n2.Kasowanie\n3.Wyświetl\n4.Szukaj\n5.Koniec\n6.Test\n";
                cin >> ch;
 
                switch ( ch )
                {       case 1: cout << "Podaj element do wpisania: \n";
								cout << "Podaj liczbe: \n";
                                cin >> a;
                                cout << "Podaj nazwisko: \n";
                                cin >> b;
                                wstawianie( T, a, b );                                
                                break;
                        case 2: cout << "Podaj element do skasowania: \n";
                                cin >> b;
                                kasowanie( T, a, b );
                                break;
                        case 3: for( i = 0; i < M; i++ ) {
						cout << T[i].s << " ";
                                        if( T[i].s == "FIL")
                        cout << T[i].liczba << " ";
                        cout << T[i].nazwisko;
						cout << endl;
						}
                                break;
                        case 4: cout << "Podaj element do wyszukania: \n";
								cout << "Podaj numer: \n";
                                cin >> a;
								cout << "Podaj nazwisko: \n";
								cin >> b;
								i = szukanie( T, a, b );
								cout << "Element " << a << b << " istnieje na pozycji " << i << "\n";
                                break;
                        case 5: break;
                        case 6: for (i=0; i<18; i++) {

									wstawianie( T, 123, "Rumanowski" );
								}
								for (i=0; i<=9; i++) {
									kasowanie( T, 123, "Rumanowski" );
								}
								for (i=0; i<=9; i++) {
									wstawianie( T, 98, "Mazur" );
								}
								i=0;
								for (i=0; i<=20; i++) {
									std::string str1 = T[i].s;
									std::string str2 = del;
									if ((str1.compare(str2)) == 0) {
										i++;
									}
								}
								cout << "DEL występuje " << i << " razy.\n";
                        default:cout << "Brak takiego wyboru.";
                                break;
                }
        } while( ch != 6 );
 
    return 0;
}
