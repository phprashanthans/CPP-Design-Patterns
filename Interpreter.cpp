#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Context {
    // any global information needed for interpretation
};

class Expression {
    public:
        virtual int interpret(Context ctx) = 0;
};

class NumberExpression : public Expression {
    private:
        int num;
    public:
        NumberExpression(int num) : num(num) {}
        int interpret(Context ctx) override {
            return num;
        }
};

class AdditionExpression : public Expression {
    private:
        Expression *left;
        Expression *right;
    public:
        AdditionExpression(Expression* l, Expression* r) :
        left(l),
        right(r){}

        int interpret(Context ctx) override {
            return left->interpret(ctx) + right->interpret(ctx);
        }
};

class MultiplicationExpression : public Expression {
    private:
        Expression *left;
        Expression *right;
    public:
        MultiplicationExpression(Expression* l, Expression* r) :
        left(l),
        right(r){}

        int interpret(Context ctx) override {
            return left->interpret(ctx) * right->interpret(ctx);
        }
};

class Interpreter {
    private:
        Context ctx;
    public:
        Interpreter(Context ctx) : ctx(ctx) {}
        int interpret(string exp) {
            Expression *ex = new AdditionExpression(new NumberExpression(2),
                             new MultiplicationExpression( new NumberExpression(3), 
                             new NumberExpression(4)));
            return ex->interpret(ctx);
        }
};

int main() {
    string expression = "2 + 3 * 4";
    Context ctx;
    Interpreter* interpreter = new Interpreter(ctx);
    int res = interpreter->interpret(expression);
    cout << "Result:" << res << endl;
    return 0;
}

