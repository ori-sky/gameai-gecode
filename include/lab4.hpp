#pragma once
#include <iostream>
#include <gecode/minimodel.hh>

namespace gameai {
	namespace gecode {
		class lab4 : public Gecode::Space {
		private:
			const int count = 2;
			Gecode::IntVarArray xy;
		public:
			lab4() : xy(*this, count, -30, 30) {
				Gecode::IntVar x(xy[0]), y(xy[1]);
				Gecode::rel(*this, x * x + y * y == 5 * 5);
				Gecode::branch(*this, xy, Gecode::INT_VAR_SIZE_MIN(),
				                          Gecode::INT_VAL_MIN());
			}

			lab4(const bool share, lab4 &s) : Gecode::Space(share, s) {
				xy.update(*this, share, s.xy);
			}

			Gecode::Space * copy (const bool share) {
				return new lab4(share, *this);
			}

			std::ostream & print(std::ostream &os) {
				return os << "lab4 { xy = " << xy << " }" << std::endl;
			}
		};
	}
}
