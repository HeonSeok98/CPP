
#include "iter.hpp"

int main( void ) {

    int intArr[5] = {1, 2, 3, 4, 5};
    char charArr[5] = {'a', 'b', 'c', 'd', 'e'};
    
    iter(intArr, 5, printElement<int>);
    iter(charArr, 5, printElement<char>);

    return 0;
}
