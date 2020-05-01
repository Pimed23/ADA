///////////////////////////////////////////////////////////
////                                                   ////
////    Codigo realizado por: Brian Pinto Medina       ////
////    GitHub: https://github.com/Pimed23/ADA.git     ////
////                                                   ////
///////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ull unsigned long long 

///////////////////////////////////////////////////////////
/////////////// PARAMETROS A TOMAR EN CUENTA //////////////
///////////////////////////////////////////////////////////
/*
    Comparaciones (nComp)                    x2
    Asignaciones (nAsig)                     x8
    Creacion de un objeto (cObj)             x200
    Reservar memoria (rMem)                  x50 + n x 10
*/
///////////////////////////////////////////////////////////
/////////////// DECLARACION DE SIMPLEARRAY ////////////////
///////////////////////////////////////////////////////////

class SimpleArray {
    public:
        SimpleArray();
        SimpleArray( const int );
        SimpleArray( const SimpleArray& ); 
        ~SimpleArray();

        void bubbleSort();
        void insertSort();
        void fillRandArray();
        void printArray();

    private:
        int size;
        int *arr;
};

///////////////////////////////////////////////////////////
/////////////////// VARIABLES GLOBALES ////////////////////
///////////////////////////////////////////////////////////

ull nComp = 0, nAsig = 0, cObj = 0, rMem = 0;
ull nCompBS = 0, nAsigBS = 0, nCompIS = 0, nAsigIS = 0;

///////////////////////////////////////////////////////////
//////////////////// FUNCION PRINCIPAL ////////////////////
///////////////////////////////////////////////////////////

int main() {
    srand( time( NULL )) ;
    unsigned int time0, time1;
    unsigned int timeBS0, timeBS1;
    unsigned int timeIS0, timeIS1;
    double timeCreation, timeBubble, timeInsert;
    int nElem;

    printf( "Insert the number of elements: " );
    scanf( "%i", &nElem ); ++nAsig;                             // Asignacion
    
    time0 = clock(); ++nAsig;                                   // Asignacion
    SimpleArray A( nElem ); ++cObj;                             // Creacion de un objeto
    A.fillRandArray();
    time1 = clock(); ++nAsig;                                   // Asignacion
    timeCreation = double( time1 - time0 ) / CLOCKS_PER_SEC;    // Asignacion
    ++nAsig;

    SimpleArray B( A ); ++cObj;                                 // Creacion de un objeto
    SimpleArray C( A ); ++cObj;                                 // Creacion de un objeto

    timeBS0 = clock(); ++nAsig;                                 // Asignacion
    B.bubbleSort();
    timeBS1 = clock(); ++nAsig;                                 // Asignacion
    timeBubble = double( timeBS1 - timeBS0 ) / CLOCKS_PER_SEC;  // Asignacion
    ++nAsig;

    timeIS0 = clock(); ++nAsig;                                 // Asignacion
    C.insertSort();
    timeIS1 = clock(); ++nAsig;                                 // Asignacion
    timeInsert = double( timeIS1 - timeIS0 ) / CLOCKS_PER_SEC;  // Asignacion
    ++nAsig;

    printf("\nARRAY OF %i ELEMENTS\n", nElem );
    printf("Creation time: %lf\n", timeCreation );
    printf("Number of total of comparisons: %llu\n", nComp * 2 );
    printf("Number of total of assignaments: %llu\n", nAsig * 8 );
    printf("Number of creations of an object: %llu\n", cObj * 200 );
    printf("Amount of memory allocations: %llu\n", rMem * 50 + nElem * 10 );
    printf("\nBUBBLE SORT\n");
    printf("Ordering time: %lf\n", timeBubble );
    printf("Number of comparisons: %llu\n", nCompBS * 2 );
    printf("Number of assignaments: %llu\n", nAsigBS * 8 );
    printf("\nINSERT SORT\n");
    printf("Ordering time: %lf\n", timeInsert );
    printf("Number of comparisons: %llu\n", nCompIS * 2 );
    printf("Number of assignaments: %llu\n", nAsigIS * 8 );
    
    
    return 0;
}

///////////////////////////////////////////////////////////
//////////////// DEFINICION DE SIMPLE ARRAY ///////////////
///////////////////////////////////////////////////////////

// Default constructor //
SimpleArray::SimpleArray() {
    this -> size = 0; ++nAsig;                                  // Asignacion
    this -> arr = new int[ size ]; ++rMem;                      // Reservar memoria
}

// Parametrized constructor //
SimpleArray::SimpleArray( const int nElem ) {
    this -> size = nElem; ++nAsig;                              // Asignacion
    this -> arr = new int[ size ]; ++rMem;                      // Reservar memoria
}

// Copy constructor //
SimpleArray::SimpleArray( const SimpleArray &other ) {
    this -> size = other.size; ++nAsig;                         // Asignacion
    this -> arr = new int[ size ]; ++rMem;                      // Reservar memoria

    for( int i = 0; i < size; ++i, ++nAsig, ++nComp ) {         // Asignacion y comparacion
        this -> arr[ i ] = other.arr[ i ];                      // Asignacion
        ++nAsig;                  
    }
}

// Destructor //
SimpleArray::~SimpleArray() {
    delete[] arr;                                               // Liberar memoria
}

// fillRandArray //
void SimpleArray::fillRandArray() {
    for( int i = 0; i < size; ++i, ++nAsig, ++nComp ) {         // Asignacion y comparacion
        arr[ i ] = rand() % 100 + 1;                            // Asignacion
        ++nAsig;
    }
}

// printArray //
void SimpleArray::printArray() {
    for( int i = 0; i < size; ++i, ++nAsig, ++nComp )           // Asignacion y comparacion
        printf( "%i ", arr[ i ]);
    printf("\n");
}


// BubbleSort //
void SimpleArray::bubbleSort() {
    for ( int i = size - 1; i > 0; --i, 
        ++nAsig, ++nComp, ++nAsigBS, ++nCompBS ) {              // Asignacion y comparacion  
        for ( int j = 0; j < i; ++j, 
            ++nAsig, ++nComp, ++nAsigBS, ++nCompBS ) {          // Asignacion y comparacion
            ++nComp, ++nCompBS;            
            if( arr[ j ] > arr[ j + 1 ]) {                      // Comparacion
                int temp = arr[ j ]; ++nAsig, ++nAsigBS;        // Asignacion
                arr[ j ] = arr[ j + 1 ]; ++nAsig, ++nAsigBS;    // Asignacion
                arr[ j + 1 ] = temp; ++nAsig; ++nAsigBS;        // Asignacion
            }
        }
    }       
}

// InsertSort //
void SimpleArray::insertSort() { 
    for ( int i = 1, j, k; i < size; ++i, 
        ++nAsig, ++nComp, ++nAsigIS, ++nCompIS ) {              // Asignacion y comparacion
        k = arr[ i ]; ++nAsig, ++nAsigIS;                       // Asignacion
        j = i - 1; ++nAsig, ++nAsigIS;                          // Asignacion

        ++nComp; ++nCompIS;
        while ( j >= 0 && arr[ j ] > k ) {                      // Comparacion
            arr[ j + 1 ] = arr[ j ]; ++nAsig; ++nAsigIS;        // Asignacion
            --j;
        } 
        arr[ j + 1 ] = k; ++nAsig, ++nAsigIS;                   // Asignacion
    } 
}
