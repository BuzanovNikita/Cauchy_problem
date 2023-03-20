#include <iostream>
#include <cmath>
#include <string>

#define N 1000

using namespace std;

double function_for_integral( double x ){
    return sin( x*x + x );
}

float integral( double(f)(double), double a, double b ){
    int i, k;
    double res = f(a) + f(b);
    double h = (b-a)/(N-1);
    for( i=1; i<=N-1; i++ ) {
        k = 2 + 2 * (i%2);
        res += k * f(a+i*h);
    }
    res = res*h/3;
    return res;
}

double new_value( double(f)(double), double h, double value_pred, int i, double a ){
    return (0.5*integral(f,a,h*i) + 0.5*integral(f,a,(i+1)*h))*h+value_pred;
}

void runge_kutta( double(f)(double), double a, double b, double y0, int n ){
    double h = (b-a)/(n-1), value=y0;
    int i;
    for ( i=0; i*h+a<=b; i++ ){
        printf( "%f, %f\n", a + h * (double)i, value );
        value = new_value( f, h, value, i, a );
    }
}

int main() {
    double a, b, y0;
    int n;
    cin >>a >>b >>y0 >>n;
    runge_kutta( function_for_integral, a, b, y0, n );
    return 0;
}

