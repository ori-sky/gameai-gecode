#pragma once
#include <iostream>
#include <gecode/minimodel.hh>

namespace gameai {
	namespace gecode {
		class lab3 : public Gecode::Space {
		private:
			Gecode::IntVar x;
		public:
			lab3() : x(*this, 0, 9) {
				Gecode::rel(*this, x > 4 && x < 20);
			}

			lab3(const bool share, lab3 &s) : Gecode::Space(share, s) {
				x.update(*this, share, s.x);
			}

			Gecode::Space * copy (const bool share) {
				return new lab3(share, *this);
			}

			std::ostream & print(std::ostream &os) {
				return os << "lab3 { x = " << x << " }" << std::endl;
			}
		};
	}
}
