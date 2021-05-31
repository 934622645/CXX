//
// Created by haoge on 2021/5/30.
//

#ifndef START_UNTIL_H
#define START_UNTIL_H


class until {

};

class Fib {
private:
    int f = 1, g = 0;
public:
    explicit Fib(int n) {
        while (f < n) next();
    }

    int get() const { return g; }

    int prev() {
        g = f - g;
        f = f - g;
        return g;
    }

    int next() {
        f = f + g;
        g = f - g;
        return g;
    }


};

#endif //START_UNTIL_H
