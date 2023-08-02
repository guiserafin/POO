#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Polinomio
{
    public : 
        double *a;
        int n;

        Polinomio(int n){
            Polinomio::n = n;
            a = new double[n];

            for (int i =0; i< n; i++){
                a[i] = 0;
            }
        }

        void setCoeficiente(int i, double c){

            if (i >= n){
                cerr << "Coeficiente invalido " << endl;
                exit(1);
            }

            a[i] = c;
        }

        double avaliar(double x){
            double sum = 0;


            for (int i = 0; i < n; i++){

                sum += a[i]*pow(x,i);
            }

            return sum;
        }

        void imprimir(){
            for (int i = 0; i< n-1; i++){
                // printf("%lfx^ %d +", a[i], i);
                cout << a[i] << "*x^" << i << "+";
            }
            cout << a[n-1] << "*x^" << n-1 << endl;
        }

        void somar(Polinomio p1, Polinomio p2){

            //Verifica qual o tamanho do maior polinomio para fazer a soma
            int tamanho = p1.n > p2.n ? p1.n : p2.n;
            
            Polinomio p3(tamanho);

            for(int i = 0; i < tamanho; i++){

                p3.a[i] = p1.a[i] + p2.a[i];

            }

            p3.imprimir();

        }
};


int main(int argc, char *argv[]){

    Polinomio p(4);
    p.setCoeficiente(0, 2);
    p.setCoeficiente(1, 2);
    p.setCoeficiente(3, 3.1);
    p.imprimir();

    double x = M_PI;
    printf("p(%lf)=%lf \n", x, p.avaliar(x));

    Polinomio p1(3);
    Polinomio p2(4);

    p1.setCoeficiente(0, 1);
    p1.setCoeficiente(1, 2.3);
    p1.setCoeficiente(2, 5);

    p2.setCoeficiente(0, 1);
    p2.setCoeficiente(1, 2.3);
    p2.setCoeficiente(2, 5);
    p2.setCoeficiente(3, 9);

    p.somar(p1, p2);

    return 0;
}

