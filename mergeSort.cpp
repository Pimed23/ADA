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
/////////////// DECLARACION DE SIMPLEARRAY ////////////////
///////////////////////////////////////////////////////////

class SimpleArray {
    public:
        SimpleArray();
        SimpleArray( const int );
        SimpleArray( const SimpleArray& ); 
        ~SimpleArray();

        void insertSort();
        void mergeSort();
        void fillRandArray();
        void printArray();

    private:
        void merge( int, int, int );
        void mergeSort( int, int );
        int size;
        int *arr;
};

///////////////////////////////////////////////////////////
//////////////////// FUNCION PRINCIPAL ////////////////////
///////////////////////////////////////////////////////////

int main() {
    FILE *arch;
    arch = fopen( "timeSorting.txt", "wt" );

    srand( time( NULL )) ;
    for( int i = 1; i < 1001; ++i ) {
        unsigned int time0, time1;
        unsigned int timeMS0, timeMS1;
        unsigned int timeIS0, timeIS1;
        double timeCreation, timeMerge, timeInsert;
        int nElem = i;
        
        time0 = clock();
        SimpleArray A( nElem ); 
        A.fillRandArray();
        A.insertSort();
        time1 = clock();
        timeCreation = double( time1 - time0 ) / CLOCKS_PER_SEC;
        
        SimpleArray B( A );                     
        SimpleArray C( A );                             
        
        timeMS0 = clock();
        B.mergeSort();
        timeMS1 = clock();
        timeMerge = double( timeMS1 - timeMS0 ) / CLOCKS_PER_SEC;
        
        timeIS0 = clock();
        C.insertSort();
        timeIS1 = clock();
        timeInsert = double( timeIS1 - timeIS0 ) / CLOCKS_PER_SEC;

        printf("\nARRAY OF %i ELEMENTS\n", nElem );
        printf("Creation time: %lf\n", timeCreation );
        fprintf( arch, "%lf\t", timeCreation );
        printf("\nMERGE SORT\n");
        printf("Ordering time: %lf\n", timeMerge );
        fprintf( arch, "%lf\t", timeMerge );
        printf("\nINSERT SORT\n");
        printf("Ordering time: %lf\n", timeInsert );
        fprintf( arch, "%lf\n", timeInsert );
    }
    fclose( arch );

    return 0;
}

///////////////////////////////////////////////////////////
//////////////// DEFINICION DE SIMPLE ARRAY ///////////////
///////////////////////////////////////////////////////////

// Default constructor //
SimpleArray::SimpleArray() {
    this -> size = 0;
    this -> arr = new int[ size ];
}

// Parametrized constructor //
SimpleArray::SimpleArray( const int nElem ) {
    this -> size = nElem;
    this -> arr = new int[ size ];
}

// Copy constructor //
SimpleArray::SimpleArray( const SimpleArray &other ) {
    this -> size = other.size;
    this -> arr = new int[ size ];

    for( int i = 0; i < size; ++i )     
        this -> arr[ i ] = other.arr[ i ];             
}

// Destructor //
SimpleArray::~SimpleArray() {
    delete[] arr; 
}

// fillRandArray //
void SimpleArray::fillRandArray() {
    for( int i = 0; i < size; ++i )
        arr[ i ] = rand() % 100 + 1; 
}

// printArray //
void SimpleArray::printArray() {
    for( int i = 0; i < size; ++i )
        printf( "%i ", arr[ i ]);
    printf("\n");
}

// InsertSort //
void SimpleArray::insertSort() { 
    for ( int i = 1, j, k; i < size; ++i ) {
        k = arr[ i ];
        j = i - 1; 

        while ( j >= 0 && arr[ j ] > k ) {  
            arr[ j + 1 ] = arr[ j ];
            --j;
        } 
        arr[ j + 1 ] = k;
    } 
}

// Merge //
void SimpleArray::merge( int left, int mid, int right ) {
    int *temp = new int[ right - left + 1 ];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while( i <= mid && j <= right ) {
        if( arr[ i ] <= arr[ j ])
            temp[ k++ ] = arr[ i++ ];
        else
            temp[ k++ ] = arr[ j++ ];
    }

    while( i <= mid )
        temp[ k++ ] = arr[ i++ ];
    while( j <= right )
        temp[ k++ ] = arr[ j++ ];
    for( k = 0, i = left; i <= right; ++i, ++k )
        arr[ i ] = temp[ k ];
 
    delete[] temp;
}

// MergeSort //
void SimpleArray::mergeSort() {
    mergeSort( 0, size - 1 );
}

// MergeSort //
void SimpleArray::mergeSort( int left, int right ) {
    int mid = ( left + right ) / 2;

    if( left < right ) {
        mergeSort( left, mid );
        mergeSort( mid + 1, right );
        merge( left, mid, right );
    }
}
