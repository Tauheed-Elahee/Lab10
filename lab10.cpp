// INSERT YOUR PROGRAM COMMENTS HERE
//
// Name: Tauheed Elahee
// Student Number: ----------

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { 
	return value * value; 
}


// Complete function readPolynomial below.
//
// This function starts by asking the user for the order of the polynomial.  
// If the order entered is not between 1 and maxOrder, it will continue to ask 
// for the order, until a valid order is obtained.
// Then it asks the user for the coefficient for the order (which cannot be 0),
// followed by the coefficient for each power of x, down to 0.
// It puts the coefficients in the polynomial array and returns the order
// of the polynomial.
int readPolynomial (int maxOrder, double polynomial[]) {
	
	// you should remove the "return 0;" once you have the function working
	return 0;
}

// Complete function displayPolynomial below.
//
// This function outputs the polynomial of order n in a nice format (as per
// the sample executable).
void displayPolynomial (int order, double polynomial[]) {
	
}

int readPolynomial (int maxOrder, double polynomial[]); 
void displayPolynomial (int order, double polynomial[]);

int main () {
	

	const int MAXN = 8; // maximum order (a constant)
	double polynomial[MAXN + 1];
	int polynomialN;
	
	
    // User enters the order of the polynomial
    
	cout << "The order of the polynomial must >= 1 and <= 8 press 0 to exit." << endl <<  "Enter order of polynomial: ";
	cin >> polynomialN;
	cout << endl << endl;
    
    
    // Ensure the order of the polynomial is within acceptable limits
	
	while ((polynomialN > MAXN) || (polynomialN < 0)) {
		cout << "The order of the polynomial must >= 1 and <= 8 press 0 to exit." << endl;
		cout <<  "Enter order of polynomial: ";
		cin >> polynomialN;
		cout << endl << endl;
	}
	
	
	// User enters the coeffiecients of the polynomial
	
	while (polynomialN != 0) {
	
		int i = polynomialN;
		for (i=polynomialN; i >= 0; i--) {
			cout << "Enter the coeffiecient for x^" << i << ": ";
			cin >> polynomial[i];
			if ((polynomial[i] == 0) && (i == polynomialN)) {
				do {
					cout << "The coeffiecient cannot be equal to zero." << endl;
					cout << "Enter the coeffiecient for x^" << i << ": ";
					cin >> polynomial[i];
				} while (polynomial[i] == 0);
			}
		}
		
		cout << endl << endl;
        
        
        // Output the original polynomial
		
		cout << "The polynomial (order = " << polynomialN << ") is\n";
		for (i=polynomialN; i >= 0; i--) {
			if (polynomial[i] != 0) {
				if ((polynomial[i] > 0) && (i != polynomialN) && (i != 0)) {
                    if (polynomial[i] != 1) {
                        cout << " + " << polynomial[i] << "x^" << i;
                    } else {
                        cout << " + " << "x^" << i;
                    }
				} else if ((polynomial[i] < 0) && (i != polynomialN) && (i != 0)) {
                    if (polynomial[i] != 1) {
                        cout << " - " << fabs(polynomial[i]) << "x^" << i;
                    } else {
                        cout << " - " << "x^" << i;
                    }
				} else if (i == polynomialN) {
                    if (polynomial[i] != 1) {
                        cout << polynomial[i] << "x^" << i;
                    } else {
                        cout << "x^" << i;
                    }
				} else if (i == 0) {
					if (polynomial[i] > 0) {
						cout << " + ";
					} else if (polynomial[i] < 0) {
						cout << " - ";
					}
					cout << fabs(polynomial[i]);
				}
			}
		}
		
		cout << endl << endl;
		
        
        // Output the derivative of the polynomial
        
		cout << "The derivative is:\n";
		for (i=polynomialN; i > 0; i--) {  // We do not take the last number into consideration because the derivative has one less term than the original polynomial
			if (polynomial[i] != 0) {
				if ((polynomial[i] > 0) && (i != polynomialN) && (i != 1)) {
                    if ((polynomial[i]*i) != 1) {
                        cout << " + " << (polynomial[i]*i) << "x^" << (i-1);
                    } else {
                        cout << " + " << "x^" << (i-1);
                    }
				} else if ((polynomial[i] < 0) && (i != polynomialN) && (i != 1)) {
                    if (((fabs(polynomial[i]))*i) != 1) {
                        cout << " - " << ((fabs(polynomial[i]))*i) << "x^" << (i-1);
                    } else {
                        cout << " - " << "x^" << (i-1);
                    }
				} else if (i == polynomialN) {
                    if ((polynomial[i]*i) != 1) {
                        cout << (polynomial[i]*i) << "x^" << (i-1);
                    } else {
                        cout << "x^" << (i-1);
                    }
				} else if (i == 1) {
					if (polynomial[i] > 0) {
						cout << " + ";
					} else if (polynomial[i] < 0) {
						cout << " - ";
					}
					cout << fabs(polynomial[i]);
				}
			}
		}
		
		cout << endl << endl;
		
		
        // Output the integral of the polynomial
        
		cout << "The integral is:\n";
		for (i=polynomialN; i >= 0; i--) {
			if ((polynomial[i] > 0) && (i != polynomialN)) {
                if ((polynomial[i]/(i+1)) != 1) {
                    cout << " + " << (polynomial[i]/(i+1)) << "x^" << (i+1);
                } else {
                    cout << " + " << "x^" << (i+1);
                }
			} else if ((polynomial[i] < 0) && (i != polynomialN)) {
                if (((fabs(polynomial[i]))/(i+1)) != 1) {
                    cout << " - " << ((fabs(polynomial[i]))/(i+1)) << "x^" << (i+1);
                } else {
                    cout << " - " << "x^" << (i+1);
                }
			} else if (i == polynomialN) {
                if ((polynomial[i]/(i+1)) != 1 ) {
                    cout << (polynomial[i]/(i+1)) << "x^" << (i+1);
                } else {
                    cout << "x^" << (i+1);
                }
			}
		}
		
		cout << " + C" << endl << endl << endl << endl << endl;
		
        
        // Get the order of the next polynomial
        
        do {
            cout << "The order of the polynomial must >= 1 and <= 8 press 0 to exit." << endl <<  "Enter order of polynomial: ";
            cin >> polynomialN;
            cout << endl << endl;
        } while ((polynomialN > MAXN) || (polynomialN < 0));
	}
	
	
	// read in the polynomial
	//polynomialN = readPolynomial (MAXN, polynomial); //This is useless

	// output message
	//cout << "\nThe polynomial (order = " << polynomialN << ") is\n";
	// followed by the polynomial
	//displayPolynomial (polynomialN, polynomial);

	cout << endl;
	system("PAUSE"); return 0;

}
