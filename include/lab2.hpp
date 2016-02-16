#pragma once
#include <iostream>
#include <gecode/minimodel.hh>

namespace gameai {
	namespace gecode {
		class lab2 : public Gecode::Space {
		private:
			Gecode::IntVar x;
		public:
			lab2() : x(*this, 0, 4) {
				Gecode::rel(*this, x == 7);
			}

			lab2(const bool share, lab2 &s) : Gecode::Space(share, s) {
				x.update(*this, share, s.x);
			}

			Gecode::Space * copy (const bool share) {
				return new lab2(share, *this);
			}

			std::ostream & print(std::ostream &os) {
				return os << "lab2 { x = " << x << " }" << std::endl;
			}
		};
	}
}
