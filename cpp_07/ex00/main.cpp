#include "whatever.hpp"

 class Point
    {
        public:
        int x;
        Point(int x) : x(x) {};
        bool operator<(Point const &other) const { return x < other.x; }
        bool operator>(Point const &other) const { return x > other.x; }

    };

std::ostream & operator<<(std::ostream &out, Point const &p)
{
    out << p.x;
    return out;
}

int main(void)
{
    int a = 2;
    int b = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap( a, b);
    std::cout << "after swap : a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;


    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "after swap : c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;

    char e = 'a';
    char f = 'b';
    std::cout << "e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "after swap : e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl << std::endl;


    double x = 1.5, y = 2.5;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    ::swap(x, y);
    std::cout << "after swap: x = " << x << ", y = " << y << std::endl;
    std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
    std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl << std::endl;

    Point p1(5);
    Point p2(10);
    std::cout << "p1 = " << p1 << ", p2 = " << p2 << std::endl;
    ::swap(p1, p2);
    std::cout << "after swap : p1 = " << p1 << ", p2 = " << p2 << std::endl;
    std::cout << "min( p1, p2 ) = " << ::min( p1, p2 ) << std::endl;
    std::cout << "max( p1, p2 ) = " << ::max( p1, p2 ) << std::endl << std::endl;

    return 0;
}

/*
Remember the subject's exact wording: "the two arguments must have the same type and
must support all the comparison operators." This is a requirement on the caller
,not something templates magically provide for free. < and > have no built-in meaning
 for a custom class like Point — C++ doesn't know how to compare two Point objects unless
you explicitly teach it,
the exact same way you had to explicitly teach it how to print a Point with operator<<.
Your min/max templates are doing exactly what they're supposed to:


if (a < b)   // this line requires operand type T to support operator<
When the compiler tries to generate min<Point>, it looks for a < b where a/b are
Point objects — finds nothing, and fails. This is precisely the trade-off templates make:
they work with any type, but only if that type actually provides what the template's body
needs.

*/