#include <iostream>
#include <type_safe/strong_typedef.hpp>

namespace ts = type_safe;

struct Displacement : ts::strong_typedef<Displacement, float>,
                      ts::strong_typedef_op::floating_point_arithmetic<Displacement> {
    using strong_typedef::strong_typedef;
};

std::ostream& operator<<(std::ostream& out, const Displacement & d)
{
    return out << static_cast<float>(d) << "m";
}

struct Count : ts::strong_typedef<Count, unsigned int>,
               ts::strong_typedef_op::integer_arithmetic<Count> {
    using strong_typedef::strong_typedef;
};

std::ostream& operator<<(std::ostream& out, const Count & c)
{
    return out << static_cast<unsigned int>(c) << " instances";
}

struct Angle : ts::strong_typedef<Angle, float>,
               ts::strong_typedef_op::floating_point_arithmetic<Angle>,
               ts::strong_typedef_op::mixed_division_noncommutative<Angle, Count> {  // enables Angle / Count
    using strong_typedef::strong_typedef;
};

std::ostream& operator<<(std::ostream& out, const Angle & a)
{
    return out << static_cast<float>(a) << " degrees";
}

int main() {

    //Count c(5);
    //Angle a(360.0 / c);  // degrees

    Displacement d(10.0);  // metres
    std::cout << "d: " << d << std::endl;

    d += Displacement(7.0);
    std::cout << "d: " << d << std::endl;

    Count c(5u);
    std::cout << "c: " << c << std::endl;

    Angle w(360.0);
    std::cout << "w: " << w << std::endl;

    Angle a(w / c);
    std::cout << "a: " << a << std::endl;

    return 0;
}

