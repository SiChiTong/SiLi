
#include "SiLi.h"
#include "SiLi-iostream.h"

void unittests();

int main() {
	SiLi::Matrix<3, 2> b({{1, 0}, {0, 1}, {1, 0}});
	SiLi::Matrix<2, 3> c({{1, 0, 0}, {0, 1, 0}});
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << b * c << std::endl;
	std::cout << (b * c).t() << std::endl;

	std::cout << SiLi::Matrix<1, 1>(.1f).inv() << std::endl;

	auto subview = b.subview<3, 1>(0, 0);
	subview(0,0) = -1;
	subview(1,0) = -2;
	subview(2,0) = -3;
	std::cout << b << std::endl;
	std::cout << subview << std::endl;
	subview *= 2;
	std::cout << subview << std::endl;
	std::cout << b << std::endl;

	{
		SiLi::Matrix<2, 2> b({{1, 2}, {3, 4}});
		SiLi::Matrix<2, 2> c({{1, 2}, {3, 4}});
		auto view = (b+c).submat<2, 2>(0, 0);
		view(2, 2) = 5;

		SiLi::Matrix<2, 2> d({{1, 2}, {3, 4}});
		std::cout << view << std::endl;
	}
	{
		SiLi::Matrix<2, 2> b({{1, 2}, {3, 4}});
		SiLi::Matrix<2, 2> c({{1, 2}, {3, 4}});
		b = c;
		b.subview<2, 2>(0, 0) = c;
		c = b.subview<2, 2>(0, 0);
		c.subview<2, 2>(0, 0) = b.subview<2, 2>(0, 0);
	}
	{
		SiLi::Matrix<2, 2> b({{1, 2}, {3, 4}});
		SiLi::Matrix<2, 2> c({{1, 2}, {3, 4}});
		b += c;
		b -= c;
		b + c;
		b - c;
		b * c;

		SiLi::Matrix<2, 2> d(b.subview<2, 2>(0, 0));

		(b+c).submat<1, 1>(1, 1);
		b.submat<1, 1>(1, 1);

		SiLi::Matrix<4, 4> e(0);

		b.subview<1, 1>(1, 1) = e.subview<1, 1>(0, 0);

		// lines that shouldn't compile
//		b.submat<1, 1>(1, 1) = e.subview<1, 1>(0, 0);
//		SiLi::Matrix<2, 2>(0).subview<1, 1>(0, 0);
	}
	unittests();
}
