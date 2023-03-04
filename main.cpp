#include <iostream>
#include <vector>

using namespace std;

// Exemplu:
// A = [1,2,3,4,5,6,7,8]
// B = [1,4,5,8] , avg = 4.5
// C = [2,3,6,7] , avg = 4.5

int SumOfArray(int &n, int X[]) {
    int sum = 0;
    for (int i = 0; i <= n; i++)
        sum += X[i];
    return sum;
}

/* Documentatie functia SplitArray:
    - are ca parametrii n = nr de elemente ale array-ului
                        X[] = array-ul dat
    - initializam variabila "sum" cu suma elementelor array-ului
    - cream un tablou bidimensional "subsets"
    - "subsets[i][j]", unde i = suma submultimii curente
                            j = dimensiunea submultimii curente
    - "subsets" va putea lua valoarea   True -> daca exista o submultime cu suma i si dimensiunea j
                                        False -> in caz contrar
    - initializam "subsets[0][0]" cu true, pentru ca o multime goala poate avea suma 0
    - parcurgem array-ul de la inceput pana la n, cu indexul i
    - memoram elementul curent in variabila "x"
    - parcurgem array-ul de la sum la elementul curent, cu indexul j
    - pentru fiecare element A[j], actualizam "subsets" pentru a include elementul A[j] in toate submultimile care au suma "j" si dimenisunea "r".
    - verificăm toate submultimile pentru a vedea dacă putem găsi o submultime cu aceeași medie în două liste nevide.
*/
bool SplitArray(int &n, int A[]) {
    int sum = SumOfArray(n, A);
    vector<vector<bool>> subsets(sum+1, vector<bool>(n + 1, false));
    subsets[0][0] = true;

    for (int i = 0; i < n; i++) {
        int x = A[i];
        for (int j = sum; j >= x; j--) {
            for (int r = 1; r <= n; r++) {
                if(subsets[j-x][r-1]) subsets[j][r]= true;  //se poate scrie si: subsets[j][r] = subsets[j][r] || subsets[j-x][r-1];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        auto avg = (float)((sum*i)%n);
        if(avg == 0 && subsets[avg][i]) return true;
    }
    return false;
}


int main() {

    cout << "Dati numarul de elemente ale lui A: ";
    int nr = 0;
    cin >> nr;
    cout << "Dati elementele lui A, separate prin Enter: ";
    int A[30];
    for (int i = 1; i <= nr; i++) {
        cin >> A[i];
    }
    if(SplitArray(nr, A))
        cout <<"True";
    else cout<<"False";

    return 0;
}
