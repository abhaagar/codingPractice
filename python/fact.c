long long int fact(long long int num) {
    if(num!=1){
       return num*fact(num-1);
    } else {
       return 1;
    }
}
