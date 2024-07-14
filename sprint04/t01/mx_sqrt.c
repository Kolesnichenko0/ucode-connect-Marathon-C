int mx_sqrt(int x) {
        if(x <= 0)
                return 0;
        else {
                for(int i = 1; i <= x / i; i++ ) {
                        if(x == i * i)
                                return i;
                }
                return 0;
        }
}
