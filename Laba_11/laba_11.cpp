#include <NTL/mat_GF2E.h>

#define PRINT(X) std::cout << X << std::endl; 

int main () {
    long r;
    NTL::GF2  q(2);
    NTL::GF2E d(3);
    NTL::GF2X mod(2, 1);
    NTL::GF2E::init(mod);

    NTL::vec_GF2E a, b, x;
    random(a, 2L);
    random(b, 2L);
    PRINT("Vectors:");
    PRINT(a);
    PRINT(b);

    NTL::mat_GF2E A, B, X;
    A.SetDims(2, 2);
    B.SetDims(2, 2);
    X.SetDims(2, 2);

    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 1;

    B[0][0] = 0; B[0][1] = 0;
    B[1][0] = 0; B[1][1] = 1;
     
    PRINT("Addition");
    add(X, A, B);
    X = A + B;
    PRINT(X);

    PRINT("Substraction");
    sub(X, A, B);
    X = A - B;
    PRINT(X);

    PRINT("To negative");
    negate(X, A);
    X = -A;
    PRINT(X);

    PRINT("Multiplication");
    mul(X, A, B);
    X = A * B;
    PRINT(X)

    mul(x, A, b);
    PRINT(x);

    mul(x, a, B);
    PRINT(x);

    mul(X, A, d);
    PRINT(x);

    mul(X, A, q);
    PRINT(X);

    mul(X, A, 3L);
    PRINT(X);

    mul(X, d, A);
    PRINT(X);

    mul(X, q, A);
    PRINT(X);

    mul(X, 2L, A);
    PRINT(X);

    PRINT("Determinant");
    determinant(d, A);
    d = determinant(A);
    PRINT(d);

    PRINT("Transpose");
    transpose(X, A);
    X = transpose(A);
    PRINT(X);

    PRINT("Solve");
    solve(d, a, A, b);
    PRINT(d);

    solve(d, A, a, b);
    PRINT(d);

    PRINT("Invert");
    inv(d, X, A);
    PRINT(d);
    PRINT(X);

    PRINT("Power");
    power(X, A, 2L);
    X = power(A, 2L);
    PRINT(X);

    PRINT("Ident");
    ident(X, 2L);
    PRINT(X);

    PRINT("Is Ident");
    r = IsIdent(A, 2L);
    PRINT(r);

    PRINT("Diagonal");
    diag(X, 2L, NTL::to_GF2E(1));
    PRINT(X);

    PRINT("Is diagonal");
    r = IsDiag(A, 2L, NTL::to_GF2E(1));
    PRINT(r);

    PRINT("Random matrix");
    random(X, 2L, 2L);
    X = NTL::random_mat_GF2E(2L, 2L);
    PRINT(X);

    PRINT("Gauss");
    r = gauss(A);
    r = gauss(A, 2L);
    PRINT(r);

    PRINT("Image");
    image(X, A);
    PRINT(X);

    PRINT("Kernel");
    kernel(X, A);
    PRINT(X);

    PRINT("Clear");
    clear(X);
    PRINT(X);

    PRINT("Is Zero");
    r = IsZero(X);
    PRINT(r);

    return 0;
}