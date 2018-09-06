#include <stdio.h>
#include <iostream>
int main() {
	//code
	int T;
	std::cin >> T;
	for(int i=0; i<T; ++i){
	    int num, sum;
	    std::cin >> num >> sum;
	    int totalSum = 0;
	    int array[num]; //= (int*)calloc(sizeof(int) * num,0);
	    for(int j=0; j<num; ++j){
	        std::cin >> array[j];
	        totalSum += array[j];
	    }
	    if(totalSum<sum)
	       std::cout << -1  << std::endl;
	    totalSum = array[0];
	    int windowStart = 0, windowEnd = 1;
	    if(totalSum==sum) {
	       std::cout << windowStart+1 << " " << windowEnd << std::endl;
	       continue;
	    }
	    while(windowEnd<num) {
	        if(totalSum+array[windowEnd]>sum) {
	            totalSum -= array[windowStart];
	            ++windowStart;
	        } else if(totalSum+array[windowEnd]==sum) {
	             std::cout << windowStart+1 <<" " << windowEnd+1  << std::endl;
	             break;
	        } else {
	            totalSum += array[windowEnd];
	            ++windowEnd;
	        }
	        
	    }
	    if(windowEnd>=num)
	       std::cout << -1  << std::endl;
	}
	return 0;
}
