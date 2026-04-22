#ifndef LEARNINGARITHMETICOPERATIONS
#define LEARNINGARITHMETICOPERATIONS

class LAO {
private:
    int iva, ivb;

public:
    LAO(int iva, int ivb);
    int add() const;
    int sub() const;
    int multiply() const; 
    int division() const;
    int check();
};

#endif