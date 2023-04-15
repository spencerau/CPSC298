#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class CentralPolygonalNumbers 
{
public:
    CentralPolygonalNumbers();
    CentralPolygonalNumbers(int nMax);
    ~CentralPolygonalNumbers();
    void display();
    bool save(string strFilename);

private:
    int m_nMax;
    int *mp_iNumbers;
};

/*
Within the constructor, you'll need to allocate the array used to store the sequence.
(Remember that the array will be one larger than the value nMax.) Use the new operator
when allocating the array of integers. The statement to allocate the array of integers will
appear similar to the following; you'll need to fill in the blank where the red question
mark appears.

The constructor should also use a for loop to calculate all the values in the sequence, the
number of pieces, p. The loop must iterate over the values of n starting at 0 and up to and
include m_nMax. It must store the computed values of p in the array of integers (pointed
to by mp_iNumbers in the example code).
*/
CentralPolygonalNumbers::CentralPolygonalNumbers()
{
    m_nMax = 0;
    mp_iNumbers = new int[m_nMax+1];
    mp_iNumbers[0] = 1;
}
CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax) {
    m_nMax = nMax;
    mp_iNumbers = new int[m_nMax+1];
    // p = (n^2 + n + 2) / 2
    for (int n = 0; n <= m_nMax; n++) {
        mp_iNumbers[n] = (n*n + n + 2) / 2;
    }
}

CentralPolygonalNumbers::~CentralPolygonalNumbers() {
    delete [] mp_iNumbers;
    printf("Destructor called\n");
}

void CentralPolygonalNumbers::display() {
    for (int i = 0; i <= m_nMax; i++) {
        printf("n: %d, maximum number of pieces: %d\n", i, mp_iNumbers[i]);
    }
}

bool CentralPolygonalNumbers::save(string strFilename) {
    ofstream file;
    file.open(strFilename);
    for (int i = 0; i <= m_nMax; i++) {
        file << mp_iNumbers[i] << endl;
    }
    file.close();
    return true;
}

int main() {
    CentralPolygonalNumbers c(10);
    c.display();
    c.save("CPN.txt");
    return 0;
}