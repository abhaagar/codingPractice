#include <ctime>
#include <iostream>

int main()
{
    std::time_t result = std::time(0);
     std::cout  << result << " seconds since the Epoch\n";
}
