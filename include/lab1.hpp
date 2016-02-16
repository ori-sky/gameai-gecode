#pragma once
#include <iostream>
#include <gecode/driver.hh>

namespace gameai {
	namespace gecode {
		class lab1 : public Gecode::Space {
		private:
			Gecode::IntVar x;
		public:
			lab1() : x(*this, 0, 4) {
				Gecode::rel(*this, x, Gecode::IRT_EQ, 2);
			}

			lab1(const bool share, lab1 &s) : Gecode::Space(share, s) {
				x.update(*this, share, s.x);
			}

			Gecode::Space * copy (const bool share) {
				return new lab1(share, *this);
			}

			std::ostream & print(std::ostream &os) {
				return os << "lab1 { x = " << x << " }" << std::endl;
			}
		};
	}
}
